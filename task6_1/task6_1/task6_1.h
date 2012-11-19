/**
 * @file	task6_1.h
 * @brief	Definition of constants, macros and project functions
 *
 * @autor	Sorokovskiy Muchailo
 */

#ifndef TASK6_1_H_
#define TASK6_1_H_


#define CODE_ESC 27	// code of the key ESC
#define MAX_LENGTH 50U	// maximum length of string
#define CONTINUE printf("Press any key to continue of ESC to exit...")	// message

/**
* @brief	This function provides the correct input string
* @param	[in, out]	*pStr Pointer to an array of characters
* @return	void
*/
void InputStr ( char *pStr, const unsigned char max_len );

/**
* @brief	This function checks the correctness of positioning brackets in line
* @param	[in]	*pStr Pointer to an array of characters
* @post		Returns -1 if an error memory allocation
*			Returns  0 Brackets located wrong
*			Returns  1 Brackets located correctly
* @return	char
*/
char IsCorrect ( const char *pStr );

#endif /* TASK6_1_H_ */