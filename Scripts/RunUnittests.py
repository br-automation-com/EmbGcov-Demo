#! python  

# Script with the following functionality that is called in order
# -> Find the UnitTests 
# -> Runs all tests and saves the result

# Tested with Python 3.9.1 
# Require:
#    JUnitXml

import os
import shutil
from junitparser import JUnitXml
import json
from urllib.request import urlopen


# --------------------------------------------------------------------------------------------------------------------------------------------
# Make project changes !
# --------------------------------------------------------------------------------------------------------------------------------------------

Projectdir = os.path.join( os.getcwd() , '..\\UnitTestWithCodeCoverage\\')     #Project path which contains the *.apj file 
 
UnittestSaveDir = Projectdir + '\\UnitTest\\'  

CombineAllResults = True   # True or False 

CleanConsole = True

# --------------------------------------------------------------------------------------------------------------------------------------------
# Don't change past this line !
# --------------------------------------------------------------------------------------------------------------------------------------------

print("-----------------------------------------")
print("Running")
print("-----------------------------------------")

# Clean old Unittests !
if os.path.isdir( UnittestSaveDir ):
    shutil.rmtree(UnittestSaveDir)
os.mkdir ( UnittestSaveDir ) 


#Use the Webservice to get all tests 
WsTest = json.loads(urlopen("http://127.0.0.1/WsTest/").read())


CombinedUnitResults = JUnitXml()
for item in WsTest['itemList']:
    testname = item['device']
    
    if CombineAllResults:
        CombinedUnitResults += JUnitXml.fromstring(urlopen('http://127.0.0.1/WsTest/' + testname).read())
    else:
        (JUnitXml.fromstring(urlopen('http://127.0.0.1/WsTest/' + testname).read())).write( UnittestSaveDir+'\\'+testname + '.xml')

if CombineAllResults:
    CombinedUnitResults.write( UnittestSaveDir+'\\'+'Unittests-CombinedResults.xml' )
   
# Remove all junk
if CleanConsole:
    os.system('cls')

# Report something 
print("-----------------------------------------")
print("All unit tests finished")
print("File(s) stored at : %s" % os.path.abspath(UnittestSaveDir))
print("-----------------------------------------")
input("Press ENTER to continue.")