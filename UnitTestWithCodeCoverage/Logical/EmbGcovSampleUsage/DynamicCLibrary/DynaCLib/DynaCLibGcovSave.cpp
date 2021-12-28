
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DynaCLib.h"
	#include "EmbGcov.h"
#ifdef __cplusplus
	};
#endif



/* This own close is required.. else we never get the gcov data out of the dynamic lib 
	- Instead of a 'public' function it could be more hidden in a header and excluded from the build if not in debug*/
plcbit DynamicCLibGcovSave(void)
{
	EmbGcovExit();
	return 0;
}
