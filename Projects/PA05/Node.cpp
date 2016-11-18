/**
*	@file Node.cpp
*
*	@brief This is the implementation of the Node class
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation of the Node class
*
*	@version 1.0
*
*	@note This is a version only meant for integer values.
*/

#include "Node.h"

/**
*	@brief The default constructor of a Node object
*
*	@details This constructor initializes values of a Node object to default values
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
Node::Node ()
{
	int value = 0;

	next = NULL;

}

/**
*	@brief The default constructor of a Node object
*
*	@details This constructor initializes values of a Node object to sent values
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
Node::Node (int sentVal, Node* nextNode)
{
	value = sentVal;

	next = nextNode;

}

/**
*	@brief The destructor of a Node object
*
*	@details Safely removes this Node object from memory
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
Node::~Node ()
{
	next = NULL;

}

/**
*	@brief Gets the value of the node.
*
*	@details Returns the value of the node.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the value of the node.
*
*	@note None.
*
*/
int Node::GetValue ()
{
	return value;

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
Node* Node::GetNext ()
{
	return next;

}

/**
*	@brief Sets the value of the node.
*
*	@details Sets the value of the node.
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
void Node::SetValue (int sentVal)
{
	value = sentVal;

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
void Node::SetNext (Node* nextPtr)
{
	next = nextPtr;

	return;

}

/**
*	@brief Prints the value of the node.
*
*	@details Prints the value of the node formatted as "[VALUE]"
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
void Node::Print ()
{
	cout << "[" << value << "]";

	return;

}