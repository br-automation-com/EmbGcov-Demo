<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio FileVersion="4.9"?>
<SwConfiguration CpuAddress="SL1" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1" />
  <TaskClass Name="Cyclic#2" />
  <TaskClass Name="Cyclic#3" />
  <TaskClass Name="Cyclic#4">
    <Task Name="SPL_CalcTe" Source="TS_UnitTest.Samples.Tests_Program.Tests_MyCalcLib_C.SPL_CalcTest.prg" Memory="UserROM" Language="ANSIC" BuildOptions="--coverage" Debugging="true" />
    <Task Name="SPL_CalcT1" Source="TS_UnitTest.Samples.Tests_Program.Tests_MyCalcLib_C.SPL_CalcTest_Variants.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="SPL_Assert" Source="TS_UnitTest.Samples.Framework_Extension_With_Custom_Asserts.SPL_AssertsEx.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="SPL_Asser1" Source="TS_UnitTest.Samples.Framework_Features.SPL_Asserts.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="SPL_Behavi" Source="TS_UnitTest.Samples.Framework_Features.SPL_Behavior.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="utTemplate" Source="TS_UnitTest.Templates.HelperTool_Supported.utTemplate_automated.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="utTemplat1" Source="TS_UnitTest.Templates.NoToolSupport.utTemplate_manual.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="UT_StaticC" Source="EmbGcovSampleUsage.StaticCLibrary.UT_StaticCLib.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="UT_DynaCLi" Source="EmbGcovSampleUsage.DynamicCLibrary.UT_DynaCLib.prg" Memory="UserROM" Language="ANSIC" Debugging="true" />
    <Task Name="UT_CppLib" Source="EmbGcovSampleUsage.CppLibrary.UT_CppLib.prg" Memory="UserROM" Language="ANSIC" BuildOptions="--coverage" Debugging="true" />
    <Task Name="Test_Cpp" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
    <Task Name="Test_Sampl" Source="" Memory="UserROM" Language="Binary" Debugging="true" />
  </TaskClass>
  <TaskClass Name="Cyclic#5" />
  <TaskClass Name="Cyclic#6" />
  <TaskClass Name="Cyclic#7" />
  <TaskClass Name="Cyclic#8">
    <Task Name="RealTarget" Source="EmbGcovSampleUsage.DynamicCLibrary.RealTarget_DynaCLib.prg" Memory="UserROM" Language="ANSIC" Debugging="true" Disabled="true" />
  </TaskClass>
  <Binaries>
    <BinaryObject Name="udbdef" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="TCData" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="iomap" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="asfw" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="arconfig" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="ashwd" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="sysconf" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="ashwac" Source="" Memory="UserROM" Language="Binary" />
  </Binaries>
  <Libraries>
    <LibraryObject Name="Runtime" Source="Libraries.Runtime.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="sys_lib" Source="Libraries.sys_lib.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="AsIecCon" Source="Libraries.AsIecCon.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="astime" Source="Libraries.astime.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="AsARCfg" Source="Libraries.AsARCfg.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="AsBrStr" Source="Libraries.AsBrStr.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="UnitTest" Source="TS_UnitTest.Libraries.UnitTest.lby" Memory="None" Language="ANSIC" Debugging="true" />
    <LibraryObject Name="LibAssert1" Source="TS_UnitTest.Samples.Framework_Extension_With_Custom_Asserts.LibAssert1.lby" Memory="None" Language="ANSIC" Debugging="true" />
    <LibraryObject Name="UtWs" Source="TS_UnitTest.Libraries.UtWs.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="UtMgr" Source="TS_UnitTest.Libraries.UtMgr.lby" Memory="UserROM" Language="Binary" Debugging="true" />
    <LibraryObject Name="SPLMyCalc" Source="TS_UnitTest.Samples.Tests_Program.SPLMyCalc.lby" Memory="UserROM" Language="IEC" Debugging="true" />
    <LibraryObject Name="FileIO" Source="Libraries.FileIO.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="AsMem" Source="Libraries.AsMem.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="DynaCLib" Source="EmbGcovSampleUsage.DynamicCLibrary.DynaCLib.lby" Memory="UserROM" Language="ANSIC" BuildOptions="--coverage" Debugging="true" />
    <LibraryObject Name="StaticCLib" Source="EmbGcovSampleUsage.StaticCLibrary.StaticCLib.lby" Memory="None" Language="ANSIC" BuildOptions="--coverage" Debugging="true" />
    <LibraryObject Name="CppFooLib" Source="EmbGcovSampleUsage.CppLibrary.CppFooLib.lby" Memory="None" Language="ANSIC" BuildOptions="--coverage" Debugging="true" />
    <LibraryObject Name="EmbGcov" Source="Libraries.EmbGcov.lby" Memory="None" Language="ANSIC" Debugging="true" />
    <LibraryObject Name="EmbGcovW" Source="Libraries.EmbGcovW.lby" Memory="UserROM" Language="Binary" Debugging="true" />
  </Libraries>
</SwConfiguration>