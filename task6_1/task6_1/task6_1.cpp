/**
 * @file	task6_1.cpp
 * @brief	Realization of constants, macros and project functions
 *
 * @autor	Sorokovskiy Muchailo
 */

#include "task6_1.h"
#include "../../StackArr/StackArr.h"

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

// This function provides the correct input string
void InputStr ( char *pStr, const unsigned char max_len )
{
	printf("Enter the string (max length %hhu): ", max_len);
	fflush(stdin);
	while( !scanf_s( "%[^\n]s", pStr, max_len + 1U ) ) // until not introduced the correct value
	{
		printf("Incorrect input!\n");
		printf("Please re-enter: ");
		fflush(stdin);
	}	
}

// This function checks the correctness of positioning brackets in line
char IsCorrect ( const char *pStr )
{
	if( !pStr )	// if memory for the array is not allocated
	{
		return -1;
	}
	unsigned char len = strlen( pStr );
	
	StackArr *stack;
	if( !(stack =  new StackArr( (len / 2U) + 1U ) ) )	// if memory for the object is not allocated
	{
		return -1;
	}

	char top;	// top stack value
	char curr;	// current symbol

	unsigned char i;	// counter
	for( i = 0; i < len ; ++i )
	{
		curr = *(pStr + i);	// current symbol

		switch( curr )
		{
			case '(':
			case '[':
			case '{':
				if( !stack->Push( curr ) )	// if the character is not added to the stack
				{
					i = len;
				}
				break;
			case ')':
				if( !stack->GetTop( &top ) || top != '(' ) // if the top of the stack is not opening bracket
				{
					i = len;
					break;
				}
				stack->Pop();
				break;
			case ']':
				if( !stack->GetTop( &top ) || top != '[' )
				{
					i = len;
					break;
				}
				stack->Pop();
				break;
			case '}':
				if( !stack->GetTop( &top ) || top != '{' )
				{
					i = len;
					break;
				}
				stack->Pop();
				break;
		}	// end of switch
	}	// end of for

	if( i > len || !stack->IsEmpty() )	// if the error or stack is not empty
	{
		delete stack;
		return 0;
	}
	delete stack;
	return 1;
}

void main ( void )
{
	char *pStr;
	if( !(pStr = new char[MAX_LENGTH + 1U]) )
	{
		printf("Memory allocation failed!\n");
		printf("Press any key to exit...");
		_getch();
	}

	do
	{
		system("cls");
		InputStr( pStr, MAX_LENGTH );
		switch( IsCorrect( pStr ) )
		{
			case 1:
				printf("Brackets located correctly.\n");
				break;
			case 0:
				printf("Brackets located wrong.\n");
				break;
			case -1:
				printf("Memory allocation failed!\n");
				break;
		}	// end of switch
	}
	while(CONTINUE, _getch() != CODE_ESC);

	delete[] pStr;
	return;
}