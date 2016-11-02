/**
*	@file PA04.cpp
*
*	@brief This is the main driver file for Programming Assignment 04
*
*	@author Bryce Monaco
*
*	@details This file runs through the data with each sorting algorithm and finds average times and counts for each to compare.
*
*	@version 1.0
*
*	@note None.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "BubbleSort.h"
#include "MergeSort.h"
#include "CountingSort.h"

//#include <ctime>
#include <cstdlib>
#include <time.h>



using namespace std;

void GenerateValues (int *valuesStart, int amount);
void ReadValuesFromFile (int* valuesStart, int amount, int fileNumber);

int main ()
{
	for (int i = 0; i < 3; i++)
	{
		int amount = 0;

		if (i == 0)
		{
			amount = 1000;

		} else if (i == 1)
		{
			amount = 10000;

		} else if (i == 2)
		{
			amount = 100000;

		} else
		{
			cout << "Error, ending." << endl;

			return 0;

		}

		int* values;

		values = new int[amount];

		//clock_t elapsedTime;

		//elapsedTime = clock();

		GenerateValues(values, amount);

		float bubbleAvgTime = 0;
		float mergeAvgTime = 0;
		float countAvgTime = 0;

		int bubbleSwaps = 0;
		int bubbleComps = 0;
		int mergeSwaps = 0;
		int mergeComps = 0;
		int countSwaps = 0;
		int countComps = 0;

		//Bubble Sort Tests
		for (int i = 0; i < 10; i++) //10 is the amount of tests to be performed
		{
			ReadValuesFromFile(values, amount, i + 1); //Read the values from file i into the array

			BubbleSort bub(values, amount);

			clock_t elapsedTime;

			elapsedTime = clock();

			bub.DoSort();

			elapsedTime = clock() - elapsedTime;

			float lastTime = ((float) elapsedTime)/CLOCKS_PER_SEC;

			bubbleAvgTime = bubbleAvgTime + lastTime;

			bubbleSwaps += bub.GetSwaps();
			bubbleComps += bub.GetComps();

		}

		bubbleAvgTime = bubbleAvgTime / 10;
		bubbleSwaps = bubbleSwaps / 10;
		bubbleComps = bubbleComps / 10;

		//Merge Sort Tests
		for (int i = 0; i < 10; i++) //10 is the amount of tests to be performed
		{
			ReadValuesFromFile(values, amount, i + 1); //Read the values from file i into the array

			MergeSort merge(values, amount);
			merge.ResetCounts();

			clock_t elapsedTime;

			elapsedTime = clock();

			merge.DoSort(0, amount - 1);
			//merge.PrintFinal();

			elapsedTime = clock() - elapsedTime;

			float lastTime = ((float) elapsedTime)/CLOCKS_PER_SEC;

			mergeAvgTime = mergeAvgTime + lastTime;

			mergeSwaps += merge.GetSwaps();
			mergeComps += merge.GetComps();

		}

		mergeAvgTime = mergeAvgTime / 10;
		mergeSwaps = mergeSwaps / 10;
		mergeComps = mergeComps / 10;

		//Counting Sort Tests
		for (int i = 0; i < 10; i++) //10 is the amount of tests to be performed
		{
			ReadValuesFromFile(values, amount, i + 1); //Read the values from file i into the array

			CountingSort count(values, amount, 1000000);

			clock_t elapsedTime;

			elapsedTime = clock();

			count.DoSort();

			elapsedTime = clock() - elapsedTime;

			float lastTime = ((float) elapsedTime)/CLOCKS_PER_SEC;

			countAvgTime = countAvgTime + lastTime;

			countSwaps += count.GetSwaps();
			countComps += count.GetComps();

		}

		countAvgTime = countAvgTime / 10;
		countSwaps = countSwaps / 10;
		countComps = countComps / 10;

		cout << endl << "Average times with " << amount << " values: " << endl;
		cout << "\tBubble Sort: " << bubbleAvgTime << "s" << endl;
		cout << "\t\tAverage Swaps: " << bubbleSwaps << " Average Comparisons: " << bubbleComps << endl;
		cout << "\tMerge Sort: " << mergeAvgTime << "s" << endl;
		cout << "\t\tAverage Swaps: " << mergeSwaps << " Average Comparisons: " << mergeComps << endl;
		cout << "\tCounting Sort: " << countAvgTime << "s" << endl;
		cout << "\t\tAverage Swaps: " << countSwaps << " Average Comparisons: " << countComps << endl;

	}

	cout << "Do 1,000,000 test? (Will run two times) [Y/N]: ";

	char response;

	cin >> response;

	if (response == 'y' || response == 'Y')
	{
		cout << "Running test with 1M values, this will take some time..." << endl;

		int amount = 1000000;

		int* values;

		values = new int[amount];

		//clock_t elapsedTime;

		//elapsedTime = clock();

		GenerateValues(values, amount);

		float bubbleAvgTime = 0;
		float mergeAvgTime = 0;
		float countAvgTime = 0;

		long long int bubbleSwaps = 0;
		long long int bubbleComps = 0;
		int mergeSwaps = 0;
		int mergeComps = 0;
		int countSwaps = 0;
		int countComps = 0;

		//Bubble Sort Tests
		for (int i = 0; i < 2; i++) //2 is the amount of tests to be performed
		{
			ReadValuesFromFile(values, amount, i + 1); //Read the values from file i into the array

			BubbleSort bub(values, amount);

			clock_t elapsedTime;

			elapsedTime = clock();

			bub.DoSort();

			elapsedTime = clock() - elapsedTime;

			float lastTime = ((float) elapsedTime)/CLOCKS_PER_SEC;

			bubbleAvgTime = bubbleAvgTime + lastTime;

			bubbleSwaps += bub.GetSwaps();
			bubbleComps += bub.GetComps();

		}

		bubbleAvgTime = bubbleAvgTime / 2;
		bubbleSwaps = bubbleSwaps / 2;
		bubbleComps = bubbleComps / 2;

		//Merge Sort Tests
		for (int i = 0; i < 2; i++) //2 is the amount of tests to be performed
		{
			ReadValuesFromFile(values, amount, i + 1); //Read the values from file i into the array

			MergeSort merge(values, amount);
			merge.ResetCounts();

			clock_t elapsedTime;

			elapsedTime = clock();

			merge.DoSort(0, amount - 1);
			//merge.PrintFinal();

			elapsedTime = clock() - elapsedTime;

			float lastTime = ((float) elapsedTime)/CLOCKS_PER_SEC;

			mergeAvgTime = mergeAvgTime + lastTime;

			mergeSwaps += merge.GetSwaps();
			mergeComps += merge.GetComps();

		}

		mergeAvgTime = mergeAvgTime / 2;
		mergeSwaps = mergeSwaps / 2;
		mergeComps = mergeComps / 2;

		//Counting Sort Tests
		for (int i = 0; i < 2; i++) //10 is the amount of tests to be performed
		{
			ReadValuesFromFile(values, amount, i + 1); //Read the values from file i into the array

			CountingSort count(values, amount, 1000000);

			clock_t elapsedTime;

			elapsedTime = clock();

			count.DoSort();

			elapsedTime = clock() - elapsedTime;

			float lastTime = ((float) elapsedTime)/CLOCKS_PER_SEC;

			countAvgTime = countAvgTime + lastTime;

			countSwaps += count.GetSwaps();
			countComps += count.GetComps();

		}

		countAvgTime = countAvgTime / 2;
		countSwaps = countSwaps / 2;
		countComps = countComps / 2;

		cout << endl << "Average times with " << amount << " values: " << endl;
		cout << "\tBubble Sort: " << bubbleAvgTime << "s" << endl;
		cout << "\t\tAverage Swaps: " << bubbleSwaps << " Average Comparisons: " << bubbleComps << endl;
		cout << "\tMerge Sort: " << mergeAvgTime << "s" << endl;
		cout << "\t\tAverage Swaps: " << mergeSwaps << " Average Comparisons: " << mergeComps << endl;
		cout << "\tCounting Sort: " << countAvgTime << "s" << endl;
		cout << "\t\tAverage Swaps: " << countSwaps << " Average Comparisons: " << countComps << endl;

	} else
	{
		cout << "Skipping 1M value test." << endl;

	}

	GenerateValues(NULL, 1); //To empty the files, saves space for Git

/*
	for (int i = 0; i < amount; i++)
	{
		cout << *(values + i) << " ";

	}

	cout << endl;
*/

/*
	ofstream outFile;
	outFile.open("Numbers.txt");

	for (int i = 0; i < (amount); i++)
	{
		outFile << *(values + i) << endl;

	}

	elapsedTime = clock() - elapsedTime;

	cout << "Value Generation Time: " << ((float) elapsedTime)/CLOCKS_PER_SEC << " seconds" << endl;

	elapsedTime = clock();

	BubbleSort bub(values, amount);

	bub.DoSort();

	elapsedTime = clock() - elapsedTime;

	cout << "Bubble Sort Time: " << ((float) elapsedTime)/CLOCKS_PER_SEC << " seconds" << endl;

	delete[] values;
	values = NULL;

	outFile.close();
*/
	return 0;

}


/**
*	@brief Generates a certain amount of random values and stores them in a file
*
*	@details This function generates a certain amount of random values and them dumps them into a file for easy reference later
*
*	@par Algorithm Generates random values into an array, then traverses the array and outputs the values to a file.
*
*	@param[in] valuesStart A pointer to an integer array. The argument is never used in the current version and can just be called with NULL
*
*	@param[in] amount The amount of values to generate.
*
*	@param[out] Creates ten files each populated with a certain amount of random values.
*
*	@return None.
*
*	@note The pointer valuesStart is not used in the current implementation, so the argument can just be sent as NULL
*
*/
void GenerateValues (int *valuesStart, int amount)
{
	srand(time(0));

	for (int i = 0; i < 10; i++) //Run the loop ten times to generate ten files
	{
		
		//valuesStart = new int[amount];
		int* values = new int[amount];


		int* valueTrav = values;

		for (int ii = 0; ii < amount; ii++)
		{
			*(valueTrav + ii) = rand() % 1000001;

		}

		valueTrav = NULL;


		ofstream outFile;
		outFile.open("Numbers" + to_string(i+1) + ".txt");

		for (int ii = 0; ii < (amount); ii++)
		{
			outFile << *(values + ii) << endl;

		}

		outFile.close();

		delete[] values;
	}

	return;
}


/**
*	@brief This function reads the values in from a file
*
*	@details This function reads the values in from a file created by GenerateValues() and stores them in an array
*
*	@par Algorithm None.
*
*	@param[in] valuesStart The pointer to the values array in main()
*
*	@param[in] amount The number of values to read in
*
*	@param[in] fileNumber The number corresponding to the file to be opened
*
*	@param[out] the valuesStart pointer now holds the numbers inside the file.
*
*	@return None.
*
*	@note None.
*
*/
void ReadValuesFromFile (int* valuesStart, int amount, int fileNumber)
{
	ifstream file;

	file.open("Numbers" + to_string(fileNumber) + ".txt");

	for (int i = 0; i < amount; i++)
	{
		file >> *(valuesStart + i);

	}
/*
	cout << "Read in: ";

	for (int i = 0; i < amount; i++)
	{
		cout << *(valuesStart + i) << " ";

	}

	cout << endl;
*/
	return;

}