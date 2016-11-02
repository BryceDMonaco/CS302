/**
*	@file MergeSort.cpp
*
*	@brief This is the implementation of the MergeSort class
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation of the MergeSort class
*
*	@version 1.0
*
*	@note None.
*/

#include "MergeSort.h"

/**
*	@brief The default constructor of a MergeSort object
*
*	@details This constructor initializes values of a MergeSort object to default values
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
MergeSort::MergeSort()
{
	size = 0;
	data = NULL;

	lastComparisonCount = 0;
	lastSwapCount = 0;

}

/**
*	@brief The parameterized constructor of a MergeSort object
*
*	@details This constructor initializes values of a MergeSort object to the sent values
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
MergeSort::MergeSort(int* sentData, int sentSize)
{
	size = sentSize;
	data = sentData;

	lastComparisonCount = 0;
	lastSwapCount = 0;

}

/**
*	@brief The destructor of a MergeSort object
*
*	@details This safely removes a MergeSort object from memory
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
MergeSort::~MergeSort ()
{
	data = NULL;

}

/**
*	@brief This function runs the sorting algorithm
*
*	@details The function takes the data and sorts it by splitting the array into smaller arrays and sorting those then merging it all back together
*
*	@par Algorithm Splits the main array into smaller arrays and sorts them then merges them together into one sorted array
*
*	@param[in] first The index of the first value of the array in scope
*
*	@param[in] last The index of the last value of the array in scope
*
*	@param[out] The array pointed at by data is now sorted
*
*	@return None.
*
*	@note None.
*
*/
void MergeSort::DoSort (int first, int last)
{
	if (first < last)
	{
		int mid = first + (last - first)/2;

		DoSort(first, mid);

		DoSort(mid + 1, last);

		DoSort(first, mid, last);

	}

	//PrintFinal(69, 0);

	return;

}

/**
*	@brief This function runs the sorting algorithm
*
*	@details The function takes the data and sorts it by splitting the array into smaller arrays and sorting those then merging it all back together
*
*	@par Algorithm Splits the main array into smaller arrays and sorts them then merges them together into one sorted array
*
*	@param[in] first The index of the first value of the array in scope
*
*	@param[in] last The index of the last value of the array in scope
*
*	@param[in] mid The index of the mid point of the array in scope
*
*	@param[out] The array pointed at by data is now sorted
*
*	@return None.
*
*	@note None.
*
*/
int* MergeSort::DoSort (int first, int mid, int last)
{
	if (data == NULL || size == 0)
	{
		return NULL;

	}

	int countComparisons = 0;
	int countSwaps = 0;

	//Sorting algorithm here
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;

	int* tempArray = new int[size];

	while (first1 <= last1 && first2 <= last2)
	{
		if (*(data + first1) <= *(data + first2))
		{
			*(tempArray + index) = *(data + first1);

			countSwaps++;

			first1++;
		} else
		{
			*(tempArray + index) = *(data + first2);

			countSwaps++;

			first2++;
		}

		countComparisons++;

		index++;

	}

	while (first1 <= last1)
	{
		*(tempArray + index) = *(data + first1);

		first1++;
		index++;

		countSwaps++;

	}

	while (first2 <= last2)
	{
		*(tempArray + index) = *(data + first2);

		first2++;
		index++;

		countSwaps++;

	}

	for (index = first; index <= last; index++)
	{
		*(data + index) = *(tempArray + index);

	}

	//PrintFinal(countSwaps, countComparisons);

	lastComparisonCount += countComparisons;
	lastSwapCount += countSwaps;

	delete[] tempArray;
	tempArray = NULL;

	return data;

}

void MergeSort::DoSort (int* sentData, int sentSize)
{
	size = sentSize;
	data = sentData;

	if (data == NULL || size == 0)
	{
		return;

	}

	return DoSort(0, size - 1);

}

void MergeSort::Swap (int* firstVal, int* secondVal)
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
void MergeSort::PrintFinal ()
{
	cout << "Merge Sort Stats: " << endl << "\tSize: " << size << "\n\tComparisons: " << lastComparisonCount;
	cout << "\n\tSwaps: " << lastSwapCount << endl;

	int* dataTrav = data;

	for (int i = 0; i < size; i++)
	{
		cout << *(dataTrav + i) << endl;

	}

	return;

}

void MergeSort::ResetCounts ()
{
	lastSwapCount = 0;
	lastComparisonCount = 0;

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
int MergeSort::GetSwaps ()
{
	return lastSwapCount;

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
int MergeSort::GetComps ()
{
	return lastComparisonCount;

}