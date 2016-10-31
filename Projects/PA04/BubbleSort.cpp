#include "BubbleSort.h"

BubbleSort::BubbleSort()
{
	size = 0;
	data = NULL;

}

BubbleSort::BubbleSort(int* sentData, int sentSize)
{
	size = sentSize;
	data = sentData;

}

BubbleSort::~BubbleSort ()
{
	data = NULL;

}

int* BubbleSort::DoSort ()
{
	if (data == NULL || size == 0)
	{
		return NULL;

	}

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

	return data;

}

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

void BubbleSort::Swap (int* firstVal, int* secondVal)
{
	int temp = *secondVal;

	*secondVal = *firstVal;
	*firstVal = temp;

	return;

}

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