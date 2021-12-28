
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
}

void _CYCLIC ProgramCyclic(void)
{
	// Call the function block during normal operation. This could be used in HIL tests	
	DynamicCLibFooFub_0.Enable = 1 ;
	DynamicCLibFooFub_0.DoSomething = 0 ;
		
	DynamicCLibFooFub(&DynamicCLibFooFub_0);
	
	
	// Save the Coverage when done. This saving can only done ones per reboot of the plc or installation of the task. 
	if( saveCoverage )
	{
		saveCoverage = 0 ;
		
		DynamicCLibGcovSave(); // This saves the libary CodeCoverage ( Every dynamic library has its own coverage memory that should be saved )
		//EmbGcovExit(); // This saves the UnitTest task CodeCoverage ( IN THIS SAMPLE PROGRAM THE SAVING DOESNT WORK BECAUSE THIS IS A PURE C TASK ! IF YOU UNCOMMENT THIS LINE YOU WILL GET ERRORS !)
	}
}

void _EXIT ProgramExit(void)
{
}

