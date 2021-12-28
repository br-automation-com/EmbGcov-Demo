# EmbGcov-Demo
Automation Studio demo project to showcase the Code coverage function of the EmbGcov library.
It contains a small C/C++ tasks and libraries with the help of the UnitTesting package that can be used in Automation Studio.

![SampleCodeCoverage](Doc/UnitTestWithCodeCoverageLogicalView.jpg)

<!-- TABLE OF CONTENTS -->
## Table of Contents

* [Background](#Background)
* [Getting Started](#getting-started)
* [Usage](#Usage)
* [Usage Demo project](#usage-Demo-project)
* [Usage Demo project on a Real Target](#Usage-Demo-project-on-a-Real-Target)
* [Tested](#Tested)


## Background
The GCC compiler supports code coverage with the '--coverage' option in the build option. The problem is that you are missing some implementations from the GCOV part. The functions in 'EmbGcov' library provides the implementation to generate this at an ARSim and in an (real PLC) embedded target. On an embedded target you can run the coverage but keep in mind that the coverage generates some additional cpu load. 

The main part of the EmbGcov is just to generate the *.gcda files. The '-elf-gcov.exe' is used from the GCC compiler to convert the *.gcno and .gcda data in a *.gcov file. The steps to display the coverage result require some 3e party programs but you can generate the coverage html results with other tools.


## Getting Started
The following software parts are required if you want to follow all 'Usage' steps:
- AS4.9.x or higher 
- UnitTest solution installed in AS ( Tested with version 2.0.1.65 this supports the GCC 6.3.0 )
- Python  ( Tested with version 3.9.1 )
- gcovr   ( See https://gcovr.com/en/stable/installation.html for the installation instructions )
- FTP Client ( only required if you want to download the files from an embedded system. )

## Usage Demo project
1. Compile and run the project so that the tests are completed ( Make sure that the all tests are preformed )
	- The data should now be created.

2. Run the 'CreateReport.py'. This will search for the .gcda files and creates a coverage report. 

	![SampleCodeCoverage](Doc/SampleCoverage.jpg)
	![SampleCodeCoverageFromFunction](Doc/SampleCoverageFunction.jpg)

## Usage Demo project on a Real Target
1. Alter the path in the function 'DynamicCLibGcovSaveEmb'. This should be changed to your project directorie. 
2. Change or add an additional user in the FTP Server so you can later download the *.gcda files.
3. Compile and download the project configuration 'X20CP1586' or 'X20CP0484'
4. Open the monitor or watch from the task 'RealTarget_DynaCLib' and set the variable 'saveCoverage' to TRUE. 
	- The data is now saved on the targets USER partition. 
	- ( You could dynamicly set the 'EmbGcovFileDevice' to a USB device )
5. Retrieve the data.
	- If your target has a CF or CFAST you could retrieve the data with a USB reader.
	- Or download the files with FTP
	- ( Or remove the USB device if u preformed the optional step )
6. Merge the download files with the temp folder of your project.

7. Run the 'CreateReport.py'. This will search for the .gcda files and creates a coverage report. 

## Tested
Used the following configuration and hardware to test the library function.

- Automation Studio 4.9.2.46 
	- ARSim 		AR C4.90 
	- X20CP1586		AR C4.90
	- X20CP0484		AR C4.90
