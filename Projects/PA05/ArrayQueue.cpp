/**
*	@file ArrayQueue.cpp
*
*	@brief This is the implementation of the ArrayQueue class
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation of the ArrayQueue class
*
*	@version 1.0
*
*	@note This is a version only meant for integer values.
*/

#include "ArrayQueue.h"

/**
*	@brief The default constructor of an ArrayQueue object
*
*	@details This constructor initializes values of a ArrayQueue object to default values
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
ArrayQueue::ArrayQueue ()
{
	front = 0;
	capacity = 10;
	back = capacity - 1;
	count = 0;
	data = new int[capacity];

}

/**
*	@brief The parameterized constructor of an ArrayQueue object
*
*	@details This constructor initializes values of a ArrayQueue object to sent values
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
ArrayQueue::ArrayQueue (int sentCap)
{
	front = 0;
	capacity = sentCap;
	back = capacity - 1;
	count = 0;
	data = new int[capacity];

}

/**
*	@brief The destructor of an ArrayQueue object
*
*	@details This safely removes an ArrayQueue object from memory
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
ArrayQueue::~ArrayQueue ()
{
	delete[] data;
	data = NULL;

}

/**
*	@brief Checks if the ArrrayQueue is empty
*
*	@details Checks the count of the queue to see if it is empty
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns true if the queue is empty, false if it contains at least one item.
*
*	@note None.
*
*/
bool ArrayQueue::IsEmpty ()
{
	if (count == 0)
	{
		return true;

	} else
	{
		return false;

	}
}

/**
*	@brief Adds an item to the queue
*
*	@details Adds an item to the back of the queue, this implementation is a circular array.
*
*	@par Algorithm None.
*
*	@param[in] entry The integer value to insert into the queue
*
*	@param[out] None.
*
*	@return Returns true if there is space for the new value, false if the queue is full.
*
*	@note None.
*
*/
bool ArrayQueue::Enqueue (int entry)
{
	if (count < capacity)
	{
		back = (back + 1) % capacity;

		int* dataTrav = data;

		*(data + back) = entry;

		count++;

		dataTrav = NULL;

		return true;

	} else
	{
		return false;

	}
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
bool ArrayQueue::Dequeue ()
{
	if (!IsEmpty())
	{
		front = (front + 1) % capacity;

		count--;

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
int ArrayQueue::Peek ()
{
	if (!IsEmpty())
	{
		int* dataTrav = data;

		return *(dataTrav + front);

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
*	@par Algorithm If the queue wraps around then the function just prints the entire queue, if it does not wrap then it just prints those values in scope.
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
void ArrayQueue::Print ()
{
	cout << "Contents of queue:" << endl << "\tFront: " << front << endl << "\tBack: " << back << endl << "\t";

	int* dataTrav = data;

	if (IsEmpty())
	{
		cout << "(EMPTY)";

	}else if (front > back)
	{
		for (int i = 0; i < capacity; i++)
		{
			cout << "[" << *(data + i) << "]";

		}

	} else
	{
		for (int i = front; i <= back; i++)
		{
			cout << "[" << *(data + i) << "]";

		}
	}

	cout << endl;

	return;

}