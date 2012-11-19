/**
 * @file	task6_2.h
 * @brief	Definition of constants, macros and project functions
 *
 * @autor	Sorokovskiy Muchailo
 */

#ifndef TASK6_2_H_
#define TASK6_2_H_

#include "../StackArr/StackArr.h"

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
* @brief	This function determines whether the symbol is the operator
* @param	[in]	ch The symbol
* @return	bool
*/
bool IsOp ( const char c );

/**
* @brief	This function determines the priority of operations
* @param	[in]	ch The symbol
* @post		Returns 2 if the operation * or /
*			Returns 1 if the operation + or -
*			Returns -1 if the number
* @return	char
*/
char Priority (const char op );

/**
* @brief	This function performs a calculation
* @param	[in, out]	*st The pointer to the stack of operands
* @param	[in]	op The symbol
* @return	bool
*/
bool ProcOp ( StackArr *st, const char op );

/**
* @brief	This function calculates the final result of the expression
* @param	[in]	*st The pointer to the expression
* @return	char
*/
char Calc (const char &pStr);

#endif /* TASK6_2_H_ */