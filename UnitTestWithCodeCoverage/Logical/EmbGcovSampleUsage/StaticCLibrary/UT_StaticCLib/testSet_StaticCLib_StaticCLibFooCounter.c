/********************************************************************
 * COPYRIGHT -- Bernecker + Rainer
 ********************************************************************
 * Program: 
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

#include "StaticCLibFooCounter.h"

_TEST test_Check(void)
{
	
	TEST_ASSERT(  StaticCLibFooCounter( 2 ,  3 ) == 5 );
	TEST_ASSERT(  StaticCLibFooCounter( 20 ,  3 ) == 23 );
	
	TEST_ASSERT(  StaticCLibFooCounterRecursive( 2 ,  3 , 2 ) == 10 );
	
	/* test is done */
	TEST_DONE;
}


/* Save the GCOV Information -> This should be done at the last test ! */
_TEARDOWN_SET(void)
{
	EmbGcovExit(); // This saves the UnitTest task and Library CodeCoverage
	
	TEST_DONE;
}



/*
B+R UnitTest: This is generated code.
Do not edit! Do not move!
Description: UnitTest Testprogramm infrastructure (TestSet).
LastUpdated: 2021-09-29 12:56:35Z
By B+R UnitTest Helper Version: 2.0.1.59
*/
UNITTEST_FIXTURES(fixtures)
{
	new_TestFixture("test_Check", test_Check), 
};

UNITTEST_CALLER_COMPLETE_EXPLICIT(testSet_StaticCLib_StaticCLibFooCounter, "testSet_StaticCLib_StaticCLibFooCounter", 0, 0, fixtures, 0, teardownSet, 0);

