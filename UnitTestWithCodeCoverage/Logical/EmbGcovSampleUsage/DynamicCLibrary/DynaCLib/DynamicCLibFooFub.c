
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DynaCLib.h"
#ifdef __cplusplus
	};
#endif

/* Dynamic C Library Foo Function block */
void DynamicCLibFooFub(struct DynamicCLibFooFub* inst)
{
	
	if( inst->Enable )
	{
	
	
		if( inst->DoSomething )
		{
			inst->InternalState ++;
		}
		
		if( inst->InternalState >= 1 )
		{
			inst->Out = 1 ;
		}
		else
		{
			inst->Out = 0 ;
		}
	
	}
	else
	{
		inst->DoSomething = 0 ;
		inst->Out = 0 ;
	}
}


