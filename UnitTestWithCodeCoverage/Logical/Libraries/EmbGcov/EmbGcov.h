/*
 * EmbGcov.h
 * 
 * This library supports the creation of GCOV data in the Embedded system.
 * 
 * REQUIRES Filedevice "EmbGcovFileDevice" else the saving fails silently in the background
 */

#ifndef EMBCOVERAGE_SUPPORT_H_
#define EMBCOVERAGE_SUPPORT_H_

#ifdef __cplusplus
 extern "C" {
#endif

/*EmbGcovExit : Call this function when the GCOV data should be created*/
void EmbGcovExit(void);

/*EmbGcovSetup : ( Not required ) Makes it possible to save the data on a real target.
	- removePath : Path to be removed from the save action. In normal situations the data is stored in the project temp directory under the tasks/libraries. A part of the path can be removed to limit the directory creations on a real target. 
		
	Sample usage EmbGcovSetup( "C:\\Projects\\UnitTestWithCodeCoverage");
*/
void EmbGcovSetup(const char* removePath );

#ifdef __cplusplus
 }
#endif

#endif /* EMBCOVERAGE_SUPPORT_H_ */
