/**
 * @file	task6_2.cpp
 * @brief	Realization of constants, macros and project functions
 *
 * @autor	Sorokovskiy Muchailo
 */

#include "task6_2.h"

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

// This function provides the correct input string
void InputStr ( char *pStr, const unsigned char max_len )
{
	printf("Enter the expression (max length %hhu): ", max_len);
	fflush(stdin);
	while( !scanf_s( "%[-+*/%%()0-9]s", pStr, max_len + 1U ) ) // until not introduced the correct value
	{
		printf("Incorrect input!\n");
		printf("Please re-enter: ");
		fflush(stdin);
	}	
}

// This function determines whether the symbol is the operator
bool IsOp ( const char c )
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}
 
// This function determines the priority of operations
char Priority (const char op )
{
	return
		op == '+' || op == '-' ? 1 :
			op == '*' || op == '/' || op == '%' ? 2 : -1;
}

// This function performs a calculation
bool ProcOp ( StackArr *st, const char op )
{
	char r;
	char l;
	if(	st->GetTop( &r ) && st->GetTop( &l ))
	{	
		st->Pop(); // removed from stack the left operand
		st->Pop(); // removed from stack the right operand
	}
	else
	{
		return false;
	}

	switch( op )
	{
		case '+':  
			st->Push( l + r );  break;	// added to stack the result of operation
		case '-':  
			st->Push( l - r );  break;
		case '*':  
			st->Push( l * r );  break;
		case '/':  
			st->Push( l / r );  break;
		case '%':  
			st->Push( l % r );  break;
	}
	return true;
}

// This function calculates the final result of the expression
char Calc (const char *pStr) 
{
	unsigned char len = strlen( pStr );	// length expression
	StackArr *st = new StackArr( len );	// stack to store operations
	StackArr *op = new StackArr( len );	// stack to store operands
	char curr;	// current character
	char currOp;	// current operands

	for (unsigned char i = 0U; i < len; ++i)
	{
		curr = *( pStr + i );
		switch( curr )
		{
			case '(':
				op->Push( curr );
				break;

			case ')':
				while( op->GetTop( &currOp ) && currOp != '(' )	// until the top of the stack is not '('
				{
					ProcOp( st, currOp );	// perform calculations
					op->Pop();	// removed operation
				}
				op->Pop();	// removed '('
				break;

			default:
				if ( IsOp( curr ) ) // if the character is operation
				{
					// until operation priority is lower than the operation in the top of the stack
					while( op->GetTop( &currOp ) && Priority( currOp ) >= Priority( curr ) ) 
					{
						ProcOp( st, currOp ); // perform calculations
						op->Pop(); // removed operation
					}
					op->Push( curr ); // added operation
				}
				else 
				{
					st->Push( atoi( &curr ) );	// added nuber
				}
				break;
		}	// end of switch
	}	// end of for

	while ( op->GetTop( &currOp ) )	// while stack not empty
	{
		ProcOp( st, currOp ); // perform calculations
		op->Pop();	// removed operation
	}
	st->GetTop( &curr );	// get the result of the expression
	delete st;
	delete op;
	return curr;
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
		printf("The program calculates a number from 0 to 10.\n");
		printf("The expression is entered without spaces.\n");
		printf("Available operations: +, -, *, /, %% and ().\n\n");

		InputStr( pStr, MAX_LENGTH );
		printf("%s = %d\n",  pStr, Calc( pStr ) );
	}
	while(CONTINUE, _getch() != CODE_ESC);

	delete[] pStr;
	return;
}