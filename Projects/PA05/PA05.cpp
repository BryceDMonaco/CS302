#include <iostream>
#include <fstream>

#include "LinkQueueBank.h"
#include "ArrayQueueBank.h"
#include "CountingSort.h"
#include "Client.h"

#include <cstdlib>
#include <time.h>

using namespace std;

void ReadInLine (Client* sentClients, int amount);
void OutputLine (Client* sentClients, int amount);
void GenerateValues (int amount);

int main ()
{
	GenerateValues(10);

	CountingSort sorter;

	Client* clients = new Client[10];

	ReadInLine(clients, 10);

	sorter.DoSort(clients, 10, 100000);

	OutputLine(clients, 10);

	return 0;

}

void ReadInLine (Client* sentClients, int amount)
{
	ifstream inputFile;

	inputFile.open("Line1.txt");

	for (int i = 0; i < amount; i++)
	{
		int tempArr;
		int tempTrans;

		inputFile >> tempArr;
		inputFile >> tempTrans;

		(*(sentClients + i)).SetArrival(tempArr);
		(*(sentClients + i)).SetTransaction(tempTrans);

	}

	return;

}

void OutputLine (Client* sentClients, int amount)
{
	ofstream outputFile;

	outputFile.open("Line1.txt");

	for (int i = 0; i < amount; i++)
	{
		int tempArr = (*(sentClients + i)).GetArrival();
		int tempTrans = (*(sentClients + i)).GetTransaction();

		outputFile << tempArr;
		outputFile << " ";
		outputFile << tempTrans << endl;

	}

	return;

}

/**
*	@brief Generates a certain amount of random values and stores them in a file
*
*	@details This function generates a certain amount of random values and them dumps them into a file for easy reference later
*
*	@par Algorithm Generates random values into an array, then traverses the array and outputs the values to a file.
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
void GenerateValues (int amount)
{
	srand(time(0));

	for (int i = 0; i < 1; i++) //Run the loop ten times to generate ten files
	{
		
		//valuesStart = new int[amount];
		int* valuesArr = new int[amount];
		int* valuesTrans = new int[amount];

		int* arrivalTrav = valuesArr;
		int* transTrav = valuesTrans;

		for (int ii = 0; ii < amount; ii++)
		{
			*(arrivalTrav + ii) = rand() % 100001;
			*(transTrav + ii) = rand() % 101;

		}

		arrivalTrav = NULL;
		transTrav = NULL;


		ofstream outFile;
		outFile.open("Line" + to_string(i+1) + ".txt");

		for (int ii = 0; ii < (amount); ii++)
		{
			outFile << *(valuesArr + ii) << " " << *(valuesTrans + ii) << endl;

		}

		outFile.close();

		delete[] valuesArr;
		delete[] valuesTrans;

	}

	return;
}