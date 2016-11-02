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
*	@note None.
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
CountingSort::CountingSort(int* sentData, int sentSize, int sentMax)
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
int* CountingSort::DoSort ()
{
	if (data == NULL || size == 0 || max == 0)
	{
		return NULL;

	}

	int countComparisons = 0;
	int countSwaps = 0;

	lastSwap = 0;
	lastComp = 0;

	//Sorting algorithm here
	int count[max];

	//Ensure that all values are at 0
	for (int i = 0; i < max; i++)
	{
		count[i] = 0;

	}

	//Go through the data and count the frequency of each value
	for (int i = 0; i < size; i++)
	{
		int val = *(data + i);

		count[val]++;

		countComparisons++;

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
	int* tempData = new int[size];

	for (int i = 0; i < size; i++)
	{
		*(tempData + i) = *(data + i);

	}

	for (int i = 0; i < size; i++)
	{
		int val = *(tempData + i); //Pick this value
		int newPosition = count[val]; //Find its new position according to the count

		*(data + (newPosition - 1)) = val;

		count[val]--;

		countSwaps++;

	}

	lastSwap = countSwaps;
	lastComp = countComparisons;

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
int* CountingSort::DoSort (int* sentData, int sentSize, int sentMax)
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

/**
*	@brief Outputs what happened in the sort
*
*	@details Prints the data in the array as well as the number of swaps and comparisons
*
*	@par Algorithm None.
*
*	@param[in] swapCount An integer representing the number of swaps performed
*
*	@param[in] compCount An integer representing the number of comparisons performed
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void CountingSort::PrintFinal (int swapCount, int compCount)
{
	cout << "Counting Sort Stats: " << endl << "\tSize: " << size << "\n\tComparisons: " << compCount;
	cout << "\n\tSwaps: " << swapCount << endl;

	int* dataTrav = data;

	for (int i = 0; i < size; i++)
	{
		cout << *(dataTrav + i) << endl;

	}

	return;

}

/**
*	@brief Gets the number of swaps
*
*	@details Gets the number of swaps from the last run of the sort
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the integer value of lastSwap.
*
*	@note None.
*
*/
int CountingSort::GetSwaps ()
{
	return lastSwap;

}

/**
*	@brief Gets the number of comparisons
*
*	@details Gets the number of comparisons from the last run of the sort
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the integer value of lastComp.
*
*	@note None.
*
*/
int CountingSort::GetComps ()
{
	return lastComp;

}