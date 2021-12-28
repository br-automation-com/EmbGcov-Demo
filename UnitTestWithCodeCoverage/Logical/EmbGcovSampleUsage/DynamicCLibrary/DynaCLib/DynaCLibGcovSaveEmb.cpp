
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
	- Instead of a 'public' function it could be more hidden in a header and excluded from the build if not in debug
	- This uses the EmbGcovSetup to remove the complete path of the project, on a target we dont need this base file structure.
*/
plcbit DynamicCLibGcovSaveEmb(void)
{
	EmbGcovSetup( "C:\\Projects\\_GITHUB\\CodeCoverage\\Project\\UnitTestWithCodeCoverage");
	EmbGcovExit();
	return 0;
}
