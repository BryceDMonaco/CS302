#include "MergeSort.h"

MergeSort::MergeSort()
{
	size = 0;
	data = NULL;

	lastComparisonCount = 0;
	lastSwapCount = 0;

}

MergeSort::MergeSort(int* sentData, int sentSize)
{
	size = sentSize;
	data = sentData;

	lastComparisonCount = 0;
	lastSwapCount = 0;

}

MergeSort::~MergeSort ()
{
	data = NULL;

}

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