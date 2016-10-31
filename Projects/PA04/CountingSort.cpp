#include "CountingSort.h"

CountingSort::CountingSort()
{
	size = 0;
	data = NULL;
	max = 0;

}

CountingSort::CountingSort(int* sentData, int sentSize, int sentMax)
{
	size = sentSize;
	data = sentData;
	max = sentMax;

}

CountingSort::~CountingSort ()
{
	data = NULL;

}

int* CountingSort::DoSort ()
{
	if (data == NULL || size == 0 || max == 0)
	{
		return NULL;

	}

	int countComparisons = 0;
	int countSwaps = 0;

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

	//PrintFinal(countSwaps, countComparisons);

	return data;

}

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