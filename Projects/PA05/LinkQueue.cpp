/**
*	@file LinkQueue.cpp
*
*	@brief This is the implementation of the LinkQueue class
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation of the LinkQueue class
*
*	@version 1.0
*
*	@note This is a version only meant for integer values.
*/

#include "LinkQueue.h"

/**
*	@brief The default constructor of a LinkQueue object
*
*	@details This constructor initializes values of a LinkQueue object to default values
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
LinkQueue::LinkQueue ()
{
	front = NULL;
	back = NULL;

}

/**
*	@brief The destructor of a LinkQueue object
*
*	@details This safely removes a LinkQueue object from memory
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
LinkQueue::~LinkQueue ()
{
	Node* nodeTrav = front;

	while (nodeTrav != NULL)
	{
		Node* temp = (*nodeTrav).GetNext();

		delete nodeTrav;

		nodeTrav = temp;
		temp = NULL;

	}

	front = NULL;
	back = NULL;

}

/**
*	@brief Checks if the LinkQueue is empty
*
*	@details Checks if the front and back of the queue are equal to NULL
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns true if the queue is empty, false otherwise.
*
*	@note None.
*
*/
bool LinkQueue::IsEmpty ()
{
	return (front == back && front == NULL);

}

/**
*	@brief Adds an item to the queue
*
*	@details Adds an item to the back of the queue, this implementation uses nodes.
*
*	@par Algorithm None.
*
*	@param[in] entry The integer value to insert into the queue
*
*	@param[out] None.
*
*	@return Returns true if there is space for the new value, false if the queue is full. Node based means that it will never be full.
*
*	@note None.
*
*/
bool LinkQueue::Enqueue (int entry)
{
	Node* newNode = new Node(entry, NULL);

	if (!IsEmpty()) //If the queue is non-empty
	{
		(*back).SetNext(newNode);

		back = newNode;

	} else //The queue is empty
	{
		front = newNode;
		back = newNode;

	}

	return true;

}

/**
*	@brief Removes the item at the front of the queue
*
*	@details Removes the item at the front of the queue, the value is not returned.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns true if an item could be removed, false if it was already empty.
*
*	@note This function can be modified to return the dequeued value.
*
*/
bool LinkQueue::Dequeue ()
{
	 if (!IsEmpty())
	 {
	 	Node* removeNode = front;

	 	if (front == back && front != NULL) //Queue has only one node
	 	{
	 		front = NULL;

	 		back = NULL;

	 	} else
	 	{
	 		front = (*front).GetNext();

	 	}

	 	delete removeNode;

	 	return true;

	 } else
	 {
	 	return false;

	 }
}

/**
*	@brief Gets the item at the front of the queue
*
*	@details Checks the front of the queue and returns the value if there is one.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the value if there is one, -1 if there isn't (in this project the data used is only positive)
*
*	@note None.
*
*/
int LinkQueue::Peek ()
{
	if (!IsEmpty())
	{
		return (*front).GetValue();

	} else
	{
		return -1;

	}
}

/**
*	@brief Prints the contents of the queue.
*
*	@details Runs through the queue and prints the contents.
*
*	@par Algorithm Prints each node in the queue.
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
void LinkQueue::Print ()
{
	cout << "Contents of link queue: " << endl;

	if (IsEmpty())
	{
		cout << "\t(EMPTY)";

	} else
	{
		cout << "\t";

		Node* nodeTrav = front;

		while (nodeTrav != NULL)
		{
			(*nodeTrav).Print();

			nodeTrav = (*nodeTrav).GetNext();

		}
	}

	cout << endl;

	return;

}