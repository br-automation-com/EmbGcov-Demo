#! python  

# Script with the following functionality that is called in order
# -> Finds all coverage files and calls gcov
# -> Calls gcovr to make the HTML report

# Tested with Python 3.9.1 
# Require:
#    gcovr

import glob
import os
import sys
import stat
import shutil
from subprocess import call, Popen, PIPE, STDOUT

# --------------------------------------------------------------------------------------------------------------------------------------------
# Make project changes !
# --------------------------------------------------------------------------------------------------------------------------------------------
AsVersion = { 'Major' : '4',
              'Minor' : '9' }
              
ElfGcov = "C:\\BrAutomation\\AS%(Major)s%(Minor)s\\AS\\gnuinst\\V6.3.0\\4.9\\bin\\i686-elf-gcov.exe" % AsVersion

Projectdir = os.path.join( os.getcwd() , '..\\UnitTestWithCodeCoverage\\')
CodeCoverageSaveDir = os.path.join(Projectdir , 'CodeCoverage'  )

# --------------------------------------------------------------------------------------------------------------------------------------------
# Don't change past this line !  
# --------------------------------------------------------------------------------------------------------------------------------------------

# Clean old CodeCoverageSaveDir !
if os.path.isdir( CodeCoverageSaveDir ):
    shutil.rmtree(CodeCoverageSaveDir)
os.mkdir ( CodeCoverageSaveDir ) 

os.chdir (CodeCoverageSaveDir)

# Find all gcda files in the project
pattern = Projectdir+'/**/*.gcda'
for fname in glob.glob(pattern, recursive=True):
    if os.path.isfile(fname):
       
        call([ ElfGcov , "-bc" , fname ])

# call gcovr
os.system("py -m gcovr -g -k -v --root "+ CodeCoverageSaveDir +"\\..\\ --html --html-details -o report.html")
