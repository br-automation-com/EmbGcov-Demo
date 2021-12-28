#! python  

# Script with the following functionality that is called in order
# -> Builds AS Project
# -> Runs the ArSim
# -> Finds the UnitTests ( With a delay for x seconds ) 
# -> Stops ArSim
# -> Finds all coverage files and calls gcov
# -> Calls gcovr to make the HTML report
# -> Cleans the Binaries and Temp for a feature test

# Tested with Python 3.9.1 
# Require:
#    JUnitXml
#    gcovr

import os
import sys
from subprocess import call, Popen, PIPE, STDOUT
import stat
import shutil
from junitparser import JUnitXml
import json
import time
import glob
from urllib.request import urlopen


# --------------------------------------------------------------------------------------------------------------------------------------------
# Make project changes !
# --------------------------------------------------------------------------------------------------------------------------------------------

AsVersion = { 'Major' : '4',
              'Minor' : '10' }

Workdir = os.path.join( os.getcwd() , '..\\UnitTestWithCodeCoverage\\')     #Project path which contains the *.apj file 
 
AsBuild = "C:\\BrAutomation\\AS%(Major)s%(Minor)s\\Bin-en\\BR.AS.Build.exe"  % AsVersion
PviTransfer = "C:\\BrAutomation\\PVI\\V%(Major)s.%(Minor)s\\PVI\\Tools\\PVITransfer\\PVITransfer.exe" % AsVersion
ElfGcov = "C:\\BrAutomation\\AS%(Major)s%(Minor)s\\AS\\gnuinst\\V6.3.0\\4.9\\bin\\i686-elf-gcov.exe" % AsVersion

ArSimBootTime = 10  #Timeout for x seconds to wait for the UnitTest. ( This depends on the size of your project and PC performance )

ProjectData = { 'Project' : os.path.join(Workdir, 'UnitTestWithCodeCoverage.apj'),
                'Config' : 'TS_UnitTest_Sample',
                'Cpu'    : 'PC_any'
                }

UnittestSaveDir = Workdir + '\\UnitTest\\'  
CodeCoverageSaveDir = Workdir + '\\CodeCoverage\\'  

RemoveBinAndTemp = True   # True or False   ( Note: this trows also the other compiled parts in the project away ! )

# --------------------------------------------------------------------------------------------------------------------------------------------
# Don't change past this line !  ( It should be made more clean in a single style .. but it works ) 
# --------------------------------------------------------------------------------------------------------------------------------------------

# Simple check if the PVI TOOL and AS are OK.
if not (os.path.isfile(PviTransfer) and os.path.isfile(AsBuild) ):
    print ("Fail cant find AS\PVI version: %s" % AsVersion )
    sys.exit(1)    
print ( "Using tools from AS\PVI version: %s" % AsVersion)


RUCPackage = '' + Workdir + '\\Binaries\\%(Config)s\\%(Cpu)s\\RUCPackage\\RUCPackage.zip' % ProjectData 

print ("Compile the project %(Project)s for Unit Tests" % ProjectData)
cmd = AsBuild + ' "%(Project)s" -c "%(Config)s" -all -buildMode Build -buildRUCPackage' % ProjectData

 
p = Popen(cmd, shell=True, stdout=PIPE, stderr=STDOUT)
for line in iter(p.stdout.readline, b''):
    print (line.rstrip().decode("utf-8"))
retval = p.wait()
if int(retval) > 1:
    print ("There are compiler errors. Stopping....")
    sys.exit(1);

print ("Generating PIL file for Unit Tests")
pilfiledata = 'CreateARsimStructure "'+RUCPackage+'", "/ARsim", "Start=1"\n' 
pilfilename = Workdir+ 'Temp/generate_ut.pil'
pilfile = open(pilfilename, 'w')
pilfile.write(pilfiledata)
pilfile.close()

print ("Creating ARSIM for Unit Tests")
call([PviTransfer,
      "-silent",
      "-consoleOutput",
      "-%s" % os.path.join(Workdir, pilfilename),
      "-%s" % os.path.join(Workdir, 'Temp/generatelog.txt') ])

print ("Sleeping. Wait untill the ArSim is in RUN")
time.sleep(ArSimBootTime)

print ("Retrieving test list")
wstest = json.loads(urlopen("http://127.0.0.1/WsTest/").read())

# -------------------------------------------------------
# Unittest
# -------------------------------------------------------
print ("Executing Unit Tests")


# Clean old Unittests !
if os.path.isdir( UnittestSaveDir ):
    shutil.rmtree(UnittestSaveDir)
os.mkdir ( UnittestSaveDir ) 

sumofresults = JUnitXml()
for item in wstest['itemList']:
    testname = item['device']
    sumofresults += JUnitXml.fromstring(urlopen('http://127.0.0.1/WsTest/' + testname).read())
    (JUnitXml.fromstring(urlopen('http://127.0.0.1/WsTest/' + testname).read())).write( UnittestSaveDir+'\\'+testname + '.xml')

sumofresults.write( UnittestSaveDir+'\\'+'unittests-results.xml' )

print ("Stopping ARsim")
call([ Workdir+ "Temp/ARsim/ar000stop.exe"])
    

# -------------------------------------------------------
# Calling Gcov
# -------------------------------------------------------
print ("Calling Gcov ")
pattern = Workdir+'/**/*.gcda'


# Clean old CodeCoverageSaveDir !
if os.path.isdir( CodeCoverageSaveDir ):
    shutil.rmtree(CodeCoverageSaveDir)
os.mkdir ( CodeCoverageSaveDir ) 

os.chdir (CodeCoverageSaveDir)

for fname in glob.glob(pattern, recursive=True):
    if os.path.isfile(fname):
        print(fname)
        
        
        call([ ElfGcov , "-bc" , fname ])
        
        
# -------------------------------------------------------
# Calling gcovr
# -------------------------------------------------------
os.system("py -m gcovr -g -k -v --root "+ CodeCoverageSaveDir +"\\..\\ --html --html-details -o report.html")


# -------------------------------------------------------
# Clean the bin and temp folder
# -------------------------------------------------------
if RemoveBinAndTemp:
    print ("Removing Binaries and Temp")
 
    if os.path.isdir(os.path.join(Workdir, 'Binaries')):
        shutil.rmtree(os.path.join(Workdir, 'Binaries'))
    if os.path.isdir(os.path.join(Workdir, 'Temp')):
         
        # Temp has some files on read only .. this gives errors during removing. 
        def onerror(func, path, exc_info):
            """
            Error handler for ``shutil.rmtree``.

            If the error is due to an access error (read only file)
            it attempts to add write permission and then retries.

            If the error is for another reason it re-raises the error.

            Usage : ``shutil.rmtree(path, onerror=onerror)``
            """
            if not os.access(path, os.W_OK):
                # Is the error an access error ?
                os.chmod(path, stat.S_IWUSR)
                func(path)
            else:
                raise
        shutil.rmtree(os.path.join(Workdir, 'Temp'), onerror=onerror)
# 

print ("Done")
