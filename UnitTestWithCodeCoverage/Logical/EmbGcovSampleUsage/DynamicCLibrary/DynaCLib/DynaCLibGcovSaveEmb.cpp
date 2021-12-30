
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DynaCLib.h"
	#include "EmbGcov.h"
	#include "sys_lib.h"

#ifdef __cplusplus
	};

#include <string.h>

#endif

/* Project path of the AS project. Valid when GetProjectPath is called */
char* projectPath = 0 ;

/* Helper function to extract the path: Then we dont have to alter the code when moving the project around */
static char* GetProjectPath()
{
	if( projectPath == 0 )
	{
		 TMP_alloc(strlen(__FILE__)+1 ,(void**) &projectPath ); // We never free this. So a small memory leak when downloading this library all the time
		
		if( projectPath != 0 ) 
		{
			strcpy( projectPath , __FILE__ );
			char *find = strstr( projectPath , "Logical"); // This only works if the function is located in the project
			if(find != 0 ) 	memset( find , 0 , 1 ); // Only delete it when it finds it 
		}
	}
	return projectPath ;
}

/* This own close is required.. else we never get the gcov data out of the dynamic lib 
	- Instead of a 'public' function it could be more hidden in a header and excluded from the build if not in debug
	- This uses the EmbGcovSetup to remove the complete path of the project, on a target we dont need this base file structure.
*/
plcbit DynamicCLibGcovSaveEmb(void)
{
	EmbGcovSetup( GetProjectPath() );
	EmbGcovExit();
	return 0;
}
