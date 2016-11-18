/**
*	@file ArrayQueueBank.cpp
*
*	@brief This is the implementation of the ArrayQueueBank class
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation of the ArrayQueueBank class
*
*	@version 1.0
*
*	@note This is a version only meant for Client objects.
*/

#include "ArrayQueueBank.h"

/**
*	@brief The default constructor of an ArrayQueueBank object
*
*	@details This constructor initializes values of a ArrayQueueBank object to default values
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
ArrayQueueBank::ArrayQueueBank ()
{
	front = 0;
	capacity = 10;
	back = capacity - 1;
	count = 0;
	data = new Client[capacity];

}

/**
*	@brief The parameterized constructor of an ArrayQueueBank object
*
*	@details This constructor initializes values of a ArrayQueueBank object to sent values
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
ArrayQueueBank::ArrayQueueBank (int sentCap)
{
	front = 0;
	capacity = sentCap;
	back = capacity - 1;
	count = 0;
	data = new Client[capacity];

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
ArrayQueueBank::~ArrayQueueBank ()
{
	delete[] data;
	data = NULL;

}

/**
*	@brief Checks if the queue is empty
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
bool ArrayQueueBank::IsEmpty ()
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
bool ArrayQueueBank::Enqueue (int sentArr, int sentTrans)
{
	if (count < capacity)
	{
		back = (back + 1) % capacity;

		Client* dataTrav = data;

		(*(data + back)).SetArrival(sentArr);
		(*(data + back)).SetTransaction(sentTrans);

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
bool ArrayQueueBank::Dequeue ()
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
int ArrayQueueBank::PeekArrival ()
{
	if (!IsEmpty())
	{
		Client* dataTrav = data;

		return (*(dataTrav + front)).GetArrival();

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
int ArrayQueueBank::PeekTransaction ()
{
	if (!IsEmpty())
	{
		Client* dataTrav = data;

		return (*(dataTrav + front)).GetTransaction();

	} else
	{
		return -1;

	}
}

/**
*	@brief Gets the item at the front of the queue
*
*	@details Checks the front of the queue and returns the address if there is one.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the value if there is one, NULL if there isn't
*
*	@note None.
*
*/
Client* ArrayQueueBank::PeekFront ()
{
	if (!IsEmpty())
	{
		return (data + front);

	} else
	{
		return NULL;

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
void ArrayQueueBank::Print ()
{
	cout << "Contents of queue:" << endl << "\tFront: " << front << endl << "\tBack: " << back << endl << "\t";

	Client* dataTrav = data;

	if (IsEmpty())
	{
		cout << "(EMPTY)";

	}else if (front > back)
	{
		for (int i = 0; i < capacity; i++)
		{
			(*(dataTrav + i)).Print();

		}

	} else
	{
		for (int i = front; i <= back; i++)
		{
			(*(dataTrav + i)).Print();

		}
	}

	cout << endl;

	return;

}