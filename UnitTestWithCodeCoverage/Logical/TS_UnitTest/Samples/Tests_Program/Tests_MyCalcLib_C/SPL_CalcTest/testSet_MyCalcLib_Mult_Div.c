/********************************************************************
 * COPYRIGHT -- Bernecker + Rainer
 ********************************************************************
 * Program: SPL_CalcTest
 * Author: B+R
 ********************************************************************
 * Test set implementation
 ********************************************************************/

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include "UnitTest.h"
#include "EmbGcov.h"


_TEST test_Multiplication(void)
{
	/* initialize functionblock parameters */
	instMyCalc.CalcOperator = splMyCalcOPERATOR_MULTIPLICATION; 
	instMyCalc.Param1   = 4;
	instMyCalc.Param2   = 4;
	/* call synchron functionblock */
	MyCalculator(&instMyCalc);
	/* check result */
	TEST_ASSERT_EQUAL_INT(16, instMyCalc.Result);
	TEST_ASSERT_EQUAL_INT(ERR_OK, instMyCalc.Status);
	/* test is done */
	TEST_DONE;
}


_TEST test_Division(void)
{
	/* initialize functionblock parameters */
	instMyCalc.CalcOperator = splMyCalcOPERATOR_DIVISION;
	instMyCalc.Param1   = 4;
	instMyCalc.Param2   = 4;
	/* call synchron functionblock */
	MyCalculator(&instMyCalc);

	/* check result */
	TEST_ASSERT_EQUAL_INT(1, instMyCalc.Result);
	TEST_ASSERT_EQUAL_INT(ERR_OK, instMyCalc.Status);

	/* test is done */
	TEST_DONE;
}

/* Save the GCOV Information -> This should be done at the last test ! */
_TEARDOWN_SET(void)
{
	EmbGcovExit();
	TEST_DONE;
}



/*
B+R UnitTest: This is generated code.
Do not edit! Do not move!
Description: UnitTest Testprogramm infrastructure (TestSet).
LastUpdated: 2021-01-19 13:25:41Z
By B+R UnitTest Helper Version: 2.0.1.59
*/
UNITTEST_FIXTURES(fixtures)
{
	new_TestFixture("test_Multiplication", test_Multiplication), 
	new_TestFixture("test_Division", test_Division), 
};

UNITTEST_CALLER_COMPLETE_EXPLICIT(testSet_MyCalcLib_Mult_Div, "testSet_MyCalcLib_Mult_Div", 0, 0, fixtures, 0, teardownSet, 0);

