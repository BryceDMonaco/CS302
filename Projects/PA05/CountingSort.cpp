/**
*	@file CountingSort.cpp
*
*	@brief This is the implementation of the CountingSort class
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation of the CountingSort class
*
*	@version 1.0
*
*	@note This is modified from PA04's counting sort to work with Clients. Sorts by arrival times.
*/

#include "CountingSort.h"

/**
*	@brief The default constructor of a CountingSort object
*
*	@details This constructor initializes values of a CountingSort object to default values
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
CountingSort::CountingSort()
{
	size = 0;
	data = NULL;
	max = 0;

}

/**
*	@brief The parameterized constructor of a CountingSort object
*
*	@details This constructor initializes values of a CountingSort object to the sent values
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
CountingSort::CountingSort(Client* sentData, int sentSize, int sentMax)
{
	size = sentSize;
	data = sentData;
	max = sentMax;

}

/**
*	@brief The destructor of a CountingSort object
*
*	@details This safely removes a CountingSort object from memory
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
CountingSort::~CountingSort ()
{
	data = NULL;

}

/**
*	@brief This function runs the sorting algorithm
*
*	@details The function takes the data and sorts it with the counting sort algorithm
*
*	@par Algorithm Counts the frequency of each value in the data, then sorts it by the count
*
*	@param[in] None.
*
*	@param[out] The array pointed at by data is now sorted
*
*	@return None.
*
*	@note None.
*
*/
Client* CountingSort::DoSort ()
{
	if (data == NULL || size == 0 || max == 0)
	{
		return NULL;

	}

	//Sorting algorithm here
	int count[max];

	//Ensure that all values are at 0
	for (int i = 0; i < max; i++)
	{
		count[i] = 0;

	}

	//Go through the data and count the frequency of each value by arrival time
	for (int i = 0; i < size; i++)
	{
		int val = (*(data + i)).GetArrival();

		count[val]++;

	}

	//Add the previous count to the next one
	for (int i = 0; i < max; i++)
	{
		if (i == 0)
		{
			count[i] += 0;

		} else
		{
			count[i] += count[i - 1];

		}
	}

	//Rearrange values based on the new count
	Client* tempData = new Client[size];

	for (int i = 0; i < size; i++)
	{
		*(tempData + i) = *(data + i);

	}

	for (int i = 0; i < size; i++)
	{
		int val = (*(tempData + i)).GetArrival(); //Pick this value
		int newPosition = count[val]; //Find its new position according to the count

		*(data + (newPosition - 1)) = *(tempData + i);

		count[val]--;

	}

	//PrintFinal(countSwaps, countComparisons);

	return data;

}

/**
*	@brief This function runs the sorting algorithm
*
*	@details The function takes the data and sorts it with the counting sort algorithm with the sent values
*
*	@par Algorithm Counts the frequency of each value in the data, then sorts it by the count
*
*	@param[in] sentData Pointer to the integer array to be sorted
*
*	@param[in] sentSize The size of the array
*
*	@param[in] sentMax The maximum value in the data, constantly 1M for this project
*
*	@param[out] The array pointed at by data is now sorted
*
*	@return Returns a pointer to the sorted integer array
*
*	@note None.
*
*/
Client* CountingSort::DoSort (Client* sentData, int sentSize, int sentMax)
{
	size = sentSize;
	data = sentData;
	max = sentMax;

	if (data == NULL || size == 0 || max == 0)
	{
		return NULL;

	}

	return DoSort();

}