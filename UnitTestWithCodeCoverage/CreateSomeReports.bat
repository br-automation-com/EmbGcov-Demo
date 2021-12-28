

set GNUGCOVPATH=C:\BrAutomation\AS49\AS\gnuinst\V6.3.0\4.9\bin
set GNUGCOV=%GNUGCOVPATH%\i686-elf-gcov.exe

set PROJECTPATH=C:\Projects\_GITHUB\CodeCoverage\EmbGcov-Demo\UnitTestWithCodeCoverage
set TEMPCPUPATH=%PROJECTPATH%\Temp\Objects\TS_UnitTest_Sample\PC_any

set GENREPORTPATH=C:\Projects\_GITHUB\CodeCoverage\Results

@echo off
@echo ------------------------------------------------------------
@echo CALLING GCOV 
@echo ------------------------------------------------------------

cd %GENREPORTPATH%\

set tempGCOV=%TEMPCPUPATH%\UT_StaticC\
%GNUGCOV% -bc %tempGCOV%*.gcda

set tempGCOV=%TEMPCPUPATH%\UT_DynaCLi\
%GNUGCOV% -bc %tempGCOV%*.gcda

set tempGCOV=%TEMPCPUPATH%\UT_CppLib\
%GNUGCOV% -bc %tempGCOV%*.gcda


set tempGCOV=%TEMPCPUPATH%\DynaCLib\
%GNUGCOV% -bc %tempGCOV%*.gcda

set tempGCOV=%TEMPCPUPATH%\StaticCLib\
%GNUGCOV% -bc %tempGCOV%*.gcda

set tempGCOV=%TEMPCPUPATH%\CppFooLib\
%GNUGCOV% -bc %tempGCOV%*.gcda



@echo off
@echo ------------------------------------------------------------
@echo CALLING GCOVR from Python !  https://gcovr.com/
@echo 
@echo https://github.com/gcovr/gcovr/issues/441   
@echo ------------------------------------------------------------

py -m gcovr -g -k -v --root %GENREPORTPATH%\..\ --html --html-details -o report.html
py -m gcovr -g -k -v --root %GENREPORTPATH%\..\ --xml coverage.cobertura.xml --xml-pretty


@echo ------------------------------------------------------------
@echo html data should be available ! 
@echo ------------------------------------------------------------

pause