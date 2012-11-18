/**
 * @file	StackArr.cpp
 * @brief	Realization methods of the class StackArr
 *
 * @autor	Sorokovskiy Muchailo
 */

#include "StackArr.h"
#include <memory.h>

// Constructor with parameter
StackArr::StackArr ( unsigned char maxSize ): pArr(new char[maxSize]), size(maxSize), top(0U)
{
	//...
}

// Copy constructor
StackArr::StackArr ( const StackArr &SA ): pArr(new char[SA.size]), size(SA.size), top(SA.top)
{
	memcpy( pArr, SA.pArr, size );	// copying array
}

// This method adds the symbol to the stack
bool StackArr::Push ( char ch )
{
	if( !pArr || top == size )  // if the array is not initialized, or stack filled
	{
		return false;
	}
	*( pArr + top ) = ch;
	top++;
	return true;
}

// This method determines if the stack is not empty
bool StackArr::IsEmpty ( void )
{
	return top > 0U ? false : true;	// if the index of top of the stack bigger of the 0 
									// then return true else return false;
}

// This method returns the top of stack
bool StackArr::GetTop ( char *ch )
{
	if( !pArr || !top )	// // if the array is not initialized or top == 0
	{
		return false;
	}
	*ch = *( pArr + top - 1U );
	return true;
}


// This method removes the top stack
bool StackArr::Pop ( void )
{
	if( !top )	// if top == 0
	{
		return false;
	}
	top--;
	return true;
}

// Class destructor frees the memory allocated for the stack
StackArr::~StackArr()
{
	delete[] pArr;
}
