/**
 * @file	StackArr.h
 * @brief	Defining the class StackArr
 *
 * @autor	Sorokovskiy Muchailo
 */

#ifndef STACKARR_H_
#define STACKARR_H_

#pragma once
class StackArr
{
private:
	unsigned char size;	// maximum size of the stack
	unsigned char top;	// index of the top element of the stack
	char *pArr;	// pointer to stack
public:
	/**
	* @brief	Constructor with parameter
	* @param	[in]	max_size maximum size of the stack
	*/
	StackArr ( unsigned char maxSize );	

	/**
	* @brief	Copy constructor
	* @param	[in]	&SA Reference to an object of this class
	*/
	StackArr ( const StackArr &SA );

	/**
	* @brief	This method adds the symbol to the stack
	* @param	[in]	ch The symbol
	* @post		Returns false if the stack is not initialized or filled
	* @return	bool
	*/
	bool Push ( char ch );

	/**
	* @brief	This method determines if the stack is not empty
	* @post		Returns false if the stack is not empty
	* @return	bool
	*/
	bool IsEmpty ( void );

	/**
	* @brief	This method returns the top of stack
	* @param	[in, out]	*ch Pointer to the symbol
	* @post		Returns false if the stack is not initialized or empty
	* @return	bool
	*/
	bool GetTop ( char *ch );

	/**
	* @brief	This method removes the top stack
	* @post		Returns false if the stack is not initialized or empty
	* @return	bool
	*/
	bool Pop ( void );

	/**
	* @brief	Class destructor frees the memory allocated for the stack
	*/
	~StackArr ();
};


#endif /* STACKARR_H_ */
