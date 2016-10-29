#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "BubbleSort.h"
#include "MergeSort.h"

//#include <ctime>
#include <cstdlib>
#include <time.h>



using namespace std;

void GenerateValues (int *valuesStart, int amount);
void ReadValuesFromFile (int* valuesStart, int amount, int fileNumber);

int main ()
{
	int* values;

	int amount = 0;

	cout << "Amount: ";
	cin >> amount;

	values = new int[amount];

	//clock_t elapsedTime;

	//elapsedTime = clock();

	GenerateValues(values, amount);

	ReadValuesFromFile(values, amount, 1);

	MergeSort merge(values, amount);

	merge.ResetCounts();
	merge.DoSort(0, amount - 1);
	merge.PrintFinal();

	ReadValuesFromFile(values, amount, 1);

	BubbleSort bub(values, amount);
	bub.DoSort();


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

void ReadValuesFromFile (int* valuesStart, int amount, int fileNumber)
{
	ifstream file;

	file.open("Numbers" + to_string(fileNumber) + ".txt");

	for (int i = 0; i < amount; i++)
	{
		file >> *(valuesStart + i);

	}

	cout << "Read in: ";

	for (int i = 0; i < amount; i++)
	{
		cout << *(valuesStart + i) << " ";

	}

	cout << endl;

	return;

}