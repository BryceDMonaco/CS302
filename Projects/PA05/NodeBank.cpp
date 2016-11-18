/**
*	@file NodeBank.cpp
*
*	@brief This is the implementation of the NodeBank class
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation of the NodeBank class
*
*	@version 1.0
*
*	@note This is essentially an early prototype of a Client
*/

#include "NodeBank.h"

/**
*	@brief The default constructor of a NodeBank object
*
*	@details This constructor initializes values of a NodeBank object to default values
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
NodeBank::NodeBank ()
{
	arrival = 0;
	transaction = 0; 

	next = NULL;

}

/**
*	@brief The default constructor of a NodeBank object
*
*	@details This constructor initializes values of a NodeBank object to sent values
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
NodeBank::NodeBank (int sentArr, int sentTran, NodeBank* nextNode)
{
	arrival = sentArr;
	transaction = sentTran;

	next = nextNode;

}

/**
*	@brief The destructor of a NodeBank object
*
*	@details Safely removes this NodeBank object from memory
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
NodeBank::~NodeBank ()
{
	next = NULL;

}

/**
*	@brief Gets the arrival time of this Node
*
*	@details Returns the arrival value of this Node object
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the integer value of the arrival time of this Node.
*
*	@note None.
*
*/
int NodeBank::GetArrival ()
{
	return arrival;

}

/**
*	@brief Gets the transaction time of this Node
*
*	@details Returns the transaction value of this Node object
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the integer value of the transaction time of this Node.
*
*	@note None.
*
*/
int NodeBank::GetTransaction ()
{
	return transaction;

}

/**
*	@brief Gets the address of the next node.
*
*	@details Returns the address of the next node.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the address of the next node.
*
*	@note None.
*
*/
NodeBank* NodeBank::GetNext ()
{
	return next;

}

/**
*	@brief Sets the arrival time of this Node
*
*	@details Modifies the arrival value of this Node object
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void NodeBank::SetArrival (int sentVal)
{
	arrival = sentVal;

	return;

}

/**
*	@brief Sets the transaction time of this Node
*
*	@details Modifies the transaction value of this Node object
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void NodeBank::SetTransaction (int sentVal)
{
	transaction = sentVal;

	return;

}

/**
*	@brief Sets the address of the next node.
*
*	@details Sets the address of the next node.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void NodeBank::SetNext (NodeBank* nextPtr)
{
	next = nextPtr;

	return;

}

/**
*	@brief Prints the value of the node.
*
*	@details Prints the value of the node formatted as "[ARRIVAL - TRANSACTION]"
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void NodeBank::Print ()
{
	cout << "[" << arrival << " - " << transaction << "]";

	return;

}