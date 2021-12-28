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

#include "foo.hpp"

_TEST testCPP_Check(void)
{
	/* initialize class parameters */
	Foo f(10);

	int test = f.getX() ; // Do something in the *.cpp file
	int thePath = f.doSomething( f.Path1 ); // Do something in the *.hpp file
	
	TEST_ASSERT(test == 10);
	TEST_ASSERT(thePath == 1);
	
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
LastUpdated: 2021-04-09 10:27:35Z
By B+R UnitTest Helper Version: 2.0.1.59
*/
UNITTEST_FIXTURES(fixtures)
{
	new_TestFixture("testCPP_Check", testCPP_Check), 
};

UNITTEST_CALLER_COMPLETE_EXPLICIT(testSet_SampleLib_SampleLitTestFub, "testSet_SampleLib_SampleLit", 0, 0, fixtures, 0, teardownSet, 0);

