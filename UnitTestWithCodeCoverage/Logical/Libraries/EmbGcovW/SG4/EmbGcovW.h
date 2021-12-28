/* Automation Studio generated header file */
/* Do not edit ! */
/* EmbGcovW 1.00.0 */

#ifndef _EMBGCOVW_
#define _EMBGCOVW_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _EmbGcovW_VERSION
#define _EmbGcovW_VERSION 1.00.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "sys_lib.h"
		#include "FileIO.h"
		#include "AsMem.h"
#endif
#ifdef _SG4
		#include "sys_lib.h"
		#include "FileIO.h"
		#include "AsMem.h"
#endif
#ifdef _SGC
		#include "sys_lib.h"
		#include "FileIO.h"
		#include "AsMem.h"
#endif


/* Datatypes and datatypes of function blocks */
typedef struct EmbGcovWriteTyp
{	unsigned long pFileName;
	unsigned long fileNameSize;
	unsigned long pRemovePath;
	unsigned long removePathSize;
	unsigned long pData;
	unsigned long dataSize;
	unsigned long totalBufferSize;
} EmbGcovWriteTyp;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC unsigned short EmbGcovWrite(struct EmbGcovWriteTyp* WriteInfo);


#ifdef __cplusplus
};
#endif
#endif /* _EMBGCOVW_ */

