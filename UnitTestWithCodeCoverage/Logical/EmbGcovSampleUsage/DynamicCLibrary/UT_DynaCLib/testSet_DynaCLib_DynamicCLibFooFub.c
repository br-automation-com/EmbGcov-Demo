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

_TEST test_Check(void)
{
	/* initialize functionblock parameters */

	DynamicCLibFooFub_0.Enable = 0 ;
	DynamicCLibFooFub_0.DoSomething = 0 ;
		
	DynamicCLibFooFub(&DynamicCLibFooFub_0);
	
	TEST_ASSERT( DynamicCLibFooFub_0.Out == 0 );
	
	// ------------------------------------------
	DynamicCLibFooFub_0.Enable = 1 ;
	DynamicCLibFooFub_0.DoSomething = 0 ;
		
	DynamicCLibFooFub(&DynamicCLibFooFub_0);
	
	TEST_ASSERT( DynamicCLibFooFub_0.Out == 0 );
	
	// ------------------------------------------
	DynamicCLibFooFub_0.Enable = 1 ;
	DynamicCLibFooFub_0.DoSomething = 1 ;
		
	DynamicCLibFooFub(&DynamicCLibFooFub_0);
	
	TEST_ASSERT( DynamicCLibFooFub_0.Out == 0 );
	
	// ------------------------------------------
	DynamicCLibFooFub_0.Enable = 1 ;
	DynamicCLibFooFub_0.DoSomething = 1 ;
		
	DynamicCLibFooFub(&DynamicCLibFooFub_0);
	
	TEST_ASSERT( DynamicCLibFooFub_0.Out == 0 );
		
	/* test is done */
	TEST_DONE;
}


/* Save the GCOV Information -> This should be done at the last test ! */
_TEARDOWN_SET(void)
{
	DynamicCLibGcovSave();  // This saves the library CodeCoverage ( Every dynamic library has its own coverage memory that should be saved )
	EmbGcovExit(); // This saves the UnitTest task CodeCoverage
	
	TEST_DONE;
}



/*
B+R UnitTest: This is generated code.
Do not edit! Do not move!
Description: UnitTest Testprogramm infrastructure (TestSet).
LastUpdated: 2021-09-29 12:22:44Z
By B+R UnitTest Helper Version: 2.0.1.59
*/
UNITTEST_FIXTURES(fixtures)
{
	new_TestFixture("test_Check", test_Check), 
};

UNITTEST_CALLER_COMPLETE_EXPLICIT(testSet_DynaCLib_DynamicCLibFooFub, "testSet_DynaCLib_DynamicCLibFooFub", 0, 0, fixtures, 0, teardownSet, 0);

