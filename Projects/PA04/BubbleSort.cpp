/**
*	@file BubbleSort.cpp
*
*	@brief This is the implementation of the BubbleSort class
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation of the BubbleSort class
*
*	@version 1.0
*
*	@note None.
*/

#include "BubbleSort.h"

/**
*	@brief The default constructor of a BubbleSort object
*
*	@details This constructor initializes values of a BubbleSort object to default values
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
BubbleSort::BubbleSort()
{
	size = 0;
	data = NULL;

	lastSwap = 0;
	lastComp = 0;

}

/**
*	@brief The parameterized constructor of a BubbleSort object
*
*	@details This constructor initializes values of a BubbleSort object to the sent values
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
BubbleSort::BubbleSort(int* sentData, int sentSize)
{
	size = sentSize;
	data = sentData;

}

/**
*	@brief The destructor of a BubbleSort object
*
*	@details This safely removes a BubbleSort object from memory
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
BubbleSort::~BubbleSort ()
{
	data = NULL;

}

/**
*	@brief This function runs the sorting algorithm
*
*	@details The function takes the data and sorts it using the bubble sorting algorithm
*
*	@par Algorithm Bubbles values up to the top so that an array is sorted in ascending order
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
int* BubbleSort::DoSort ()
{
	if (data == NULL || size == 0)
	{
		return NULL;

	}

	lastSwap = 0;
	lastComp = 0;

	int countComparisons = 0;
	int countSwaps = 0;

	//Sorting algorithm here
	bool sorted = false;
	int pass = 1;

	while (!sorted && pass < size)
	{
		sorted = true;

		for (int i = 0; i < (size - pass); i++)
		{
			int nextPosition = i + 1;

			if (*(data + i) > *(data + nextPosition))
			{
				Swap((data + i), (data + nextPosition));

				sorted = false;

				countSwaps++;

			}

			countComparisons++;

		}

		pass++;

	}

	//PrintFinal(countSwaps, countComparisons);

	lastSwap = countSwaps;
	lastComp = countComparisons;

	return data;

}

/**
*	@brief Runs the sorting algorithm with new parameters
*
*	@details This function uses the sent size and data and sorts it instead of the original values
*
*	@par Algorithm None.
*
*	@param[in] sentData A pointer to the new data array
*
*	@param[in] sentSize The size of the sent array
*
*	@param[out] None.
*
*	@return Returns a pointer to the sorted int array.
*
*	@note None.
*
*/
int* BubbleSort::DoSort (int* sentData, int sentSize)
{
	size = sentSize;
	data = sentData;

	if (data == NULL || size == 0)
	{
		return NULL;

	}

	return DoSort();

}

/**
*	@brief This function swaps two values
*
*	@details This function swaps the two values pointed at by the pointers
*
*	@par Algorithm None.
*
*	@param[in] firstVal Pointer to the first integer value
*
*	@param[in] secondVal Pointer to the second integer value
*
*	@param[out] The values are now swapped.
*
*	@return None.
*
*	@note None.
*
*/
void BubbleSort::Swap (int* firstVal, int* secondVal)
{
	int temp = *secondVal;

	*secondVal = *firstVal;
	*firstVal = temp;

	return;

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
void BubbleSort::PrintFinal (int swapCount, int compCount)
{
	cout << "Bubble Sort Stats: " << endl << "\tSize: " << size << "\n\tComparisons: " << compCount;
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
int BubbleSort::GetSwaps ()
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
int BubbleSort::GetComps ()
{
	return lastComp;

}