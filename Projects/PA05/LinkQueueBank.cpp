/**
*	@file LinkQueueBank.cpp
*
*	@brief This is the implementation of the LinkQueueBank class
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation of the LinkQueueBank class
*
*	@version 1.0
*
*	@note This is a version only meant for Client values.
*/

#include "LinkQueueBank.h"

/**
*	@brief The default constructor of a LinkQueueBank object
*
*	@details This constructor initializes values of a LinkQueueBank object to default values
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
LinkQueueBank::LinkQueueBank ()
{
	front = NULL;
	back = NULL;

}

/**
*	@brief The destructor of a LinkQueueBank object
*
*	@details This safely removes a LinkQueueBank object from memory
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
LinkQueueBank::~LinkQueueBank ()
{
	NodeBank* nodeTrav = front;

	while (nodeTrav != NULL)
	{
		NodeBank* temp = (*nodeTrav).GetNext();

		delete nodeTrav;

		nodeTrav = temp;
		temp = NULL;

	}

	front = NULL;
	back = NULL;

}

/**
*	@brief Checks if the queue is empty
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
bool LinkQueueBank::IsEmpty ()
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
bool LinkQueueBank::Enqueue (int sentArr, int sentTrans)
{
	NodeBank* newNodeBank = new NodeBank(sentArr, sentTrans, NULL);

	if (!IsEmpty()) //If the queue is non-empty
	{
		(*back).SetNext(newNodeBank);

		back = newNodeBank;

	} else //The queue is empty
	{
		front = newNodeBank;
		back = newNodeBank;

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
bool LinkQueueBank::Dequeue ()
{
	 if (!IsEmpty())
	 {
	 	NodeBank* removeNodeBank = front;

	 	if (front == back && front != NULL) //Queue has only one node
	 	{
	 		front = NULL;

	 		back = NULL;

	 	} else
	 	{
	 		front = (*front).GetNext();

	 	}

	 	delete removeNodeBank;

	 	return true;

	 } else
	 {
	 	return false;

	 }
}

/**
*	@brief Gets the arrival time of the client at the front of the queue
*
*	@details Checks the front of the queue and returns the arrival time of the client if there is one.
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
int LinkQueueBank::PeekArrival ()
{
	if (!IsEmpty())
	{
		return (*front).GetArrival();

	} else
	{
		return -1;

	}
}

/**
*	@brief Gets the transaction time of the client at the front of the queue
*
*	@details Checks the front of the queue and returns the transaction time of the client if there is one.
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
int LinkQueueBank::PeekTransaction ()
{
	if (!IsEmpty())
	{
		return (*front).GetTransaction();

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
void LinkQueueBank::Print ()
{
	cout << "Contents of link queue: " << endl;

	if (IsEmpty())
	{
		cout << "\t(EMPTY)";

	} else
	{
		cout << "\t";

		NodeBank* nodeTrav = front;

		while (nodeTrav != NULL)
		{
			(*nodeTrav).Print();

			nodeTrav = (*nodeTrav).GetNext();

		}
	}

	cout << endl;

	return;

}