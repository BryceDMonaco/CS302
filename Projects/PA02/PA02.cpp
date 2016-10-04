//  Created by Shehryar Khattak for CS302 Spring 2016 class.
//	Updated and modified by Bryce Monaco, CS302 Fall 2016

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ReadInData (ifstream *sentFile, int* arrayStart);
int GetDataAmount (ifstream *sentFile);
void PrintValues (int *arrayStart, int size);
void PrintValues (int *arrayStart, int from, int to, int pivotIndex);
int FindKthValue (int kth, int *arrayStart, int firstPos, int lastPos);
void OutputToLog (int kth, int firstPos, int lastPos, int pivotIndex, int pivot);
void OutputToLog (string sentString);

//Global Variables
ofstream logFile; //Made global so that the output functions can access it without needing it as an argument

int main (int argc, char *argv[])
{

	//Declerations (insert as needed)
	int kSmall_pos;			//For User Input
	int kSmall_val = 0;		//Populate using your algorithm implementation
	int pivot;		        //Pivot position in array

	int *values;

	//User Input DO NOT MODIFY
	cout << "(A data file not named \"data2.txt\" can be opened as a command-line argument)" << endl;
	cout << "Please enter required kth smallest value:";
	cin >> kSmall_pos;

	
	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.
	ifstream dataFile;
	
	logFile.open("log.txt", ios::app);

	if (!logFile.is_open())
	{
		cout << "There was an error in opening the log file, ending program." << endl;

		return 0;

	}

	OutputToLog("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	OutputToLog("\t\t\tBEGINNING NEW PROGRAM RUN");
	OutputToLog("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");


	//If the user gave a different file name through the command line, open it, otherwise, open the default name
	if (argc > 1)
	{
		//cout << "Argument: " << argv[1] << endl;

		dataFile.open(argv[1]);

	} else
	{
		dataFile.open("data2.txt");

	}

	if (!dataFile.is_open())
	{
		cout << "There was an error in opening the data file, perhaps the name is misspelled, ending program." << endl;

		return 0;

	}

	int entries = GetDataAmount(&dataFile);

	logFile << "Entries Found: " << entries << endl;

	values = new int[entries];

	if (kSmall_pos < 1 || kSmall_pos > entries)
	{
		cout << "Error: kSmall_pos out of valid range. Must be a value from 1-" << entries << endl;

		dataFile.close();

		delete values;
		values = NULL;

		return 0;

	}

	//If the user gave a different file name through the command line, open it, otherwise, open the default name
	if (argc > 1)
	{
		//cout << "Argument: " << argv[1] << endl;

		dataFile.open(argv[1]);

		ReadInData(&dataFile, values);

	} else
	{
		dataFile.open("data2.txt");

		ReadInData(&dataFile, values);

	}

	PrintValues(values, entries);

	//kmsall algorithm implementation or function call (insert) - implement using recursion as indicated
	int *firstVal = values;
	int *lastVal = values;

	for (int i = 0; i < entries - 1; i++)
	{
		lastVal++;

	}

	logFile << endl << "Begining Algorithm..." << endl << endl;

	kSmall_val = FindKthValue(kSmall_pos, values, 0, entries - 1);


	//PrintValues(values, entries);

	//Log file output (insert) - preferred in .txt format acoording to instructions posted on assignment page



	//Output DO NOT MODIFY
	cout<< "kth smallest value = " << kSmall_val << endl;

	delete[] values;
	values = NULL;

	firstVal = NULL;
	lastVal = NULL;

	return 0;
}

void ReadInData (ifstream *sentFile, int *arrayStart)
{
	bool continueRead = true;
	int *arrayTrav = arrayStart;

	while (continueRead)
	{
		int temp;

		(*sentFile) >> temp;

		if ((*sentFile).eof())
		{
			continueRead = false;

		} else
		{
			*arrayTrav = temp;

			arrayTrav++;

		}

	}


	(*sentFile).close();

	arrayTrav = NULL;

	return;

}

//Parses through the data file to find the amount of lines (entries) within the file
int GetDataAmount (ifstream *sentFile)
{
	int count = 0;

	bool continueRead = true;

	while (continueRead)
	{
		int temp;

		(*sentFile) >> temp;

		if ((*sentFile).eof())
		{
			continueRead = false;

		} else
		{
			count++;

		}

	}

	(*sentFile).close();

	return count;

}

void PrintValues (int *arrayStart, int size)
{
	int *arrayTrav = arrayStart;

	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			logFile << "(" << i << ") " << *arrayTrav << endl;

		} else
		{
			logFile << "(" << i << ") "<< *arrayTrav << ", ";

		}

		arrayTrav++;

	}

	arrayTrav = NULL;

}

void PrintValues (int *arrayStart, int from, int to, int pivotIndex) //Prints the values within a scope
{	
	int *arrayTrav = arrayStart;

	for (int i = 0; i < from; i++)
	{
		arrayTrav++;

	}

	for (int i = 0; i < (to - from + 1); i++)
	{
		//cout << i << "i ";
		if (i == (to - from))
		{
			logFile << "(" << i + from << ") " << *arrayTrav;

			if (i == pivotIndex - from)
			{
				logFile << "<P>";

			}

		} else
		{
			logFile << "(" << i + from << ") "<< *arrayTrav;

			if (i == pivotIndex - from)
			{
				logFile << "<P>";

			}

			logFile  << ", ";

		}



		arrayTrav++;

	}

	arrayTrav = NULL;

	return;

}

int FindKthValue (int kth, int *arrayStart, int firstPos, int lastPos)
{
	/*
		//Used for debug purposes to prevent an infinite from filling the console with output data
		cout << "Press enter to start run...";

		int dummy;

		cin >> dummy;
	*/

	logFile << "Starting new run..." << endl;
	logFile << "Sent First: " << firstPos << " Sent Last: " << lastPos << endl;

	int *leftPtr = arrayStart;
	int leftPtrPos = firstPos;

	int *rightPtr = arrayStart;
	int rightPtrPos = lastPos;

	for (int i = 0; i < firstPos; i++)
	{
		leftPtr++;

	}

	for (int i = 0; i < lastPos; i++)
	{
		rightPtr++;

	}

	int pivot = *leftPtr;
	int pivotIndex = firstPos;
	int *pivotPtr = leftPtr;
	int *partitionTrav = leftPtr;

	leftPtr++;		//Moves to the value after the pivot;
	leftPtrPos++;	//Moves the position too

	logFile << "Values in scope before partition: (";
	PrintValues(arrayStart, firstPos, lastPos, pivotIndex);
	logFile << ")" << endl;

	while (leftPtr != rightPtr && leftPtrPos < rightPtrPos)
	{
		if (*leftPtr >= pivot)
		{
			if (*rightPtr < pivot)
			{
				int temp = *rightPtr;

				*rightPtr = *leftPtr;
				*leftPtr = temp;

			} else if (*rightPtr >= pivot)
			{
				rightPtr--;
				rightPtrPos--;

			}

		} else if (*leftPtr < pivot)
		{
			leftPtr++;
			leftPtrPos++;

		}
	}

	while (*(partitionTrav + 1) < pivot && pivotIndex < lastPos)
	{
		partitionTrav++;
		pivotIndex++;

	}

	int swapDump = *partitionTrav;

	*partitionTrav = pivot;
	*pivotPtr = swapDump;

	logFile << "Values in scope after partition: (";
	PrintValues(arrayStart, firstPos, lastPos, pivotIndex);
	logFile << ")" << endl;

	OutputToLog(kth, firstPos, lastPos, pivotIndex, pivot);


	if (kth < (pivotIndex - firstPos + 1))
	{
		OutputToLog("Kth value is in the left partition.");

		return FindKthValue(kth, arrayStart, firstPos, pivotIndex - 1); //Check S1

	} else if (kth == (pivotIndex - firstPos + 1))
	{
		OutputToLog("Kth value is the pivot.");


		return pivot;

	} else
	{
		OutputToLog("Kth value is in the right partition.");

		return FindKthValue(kth - (pivotIndex - firstPos + 1), arrayStart, pivotIndex + 1, lastPos); //Check S2

	}
}

void OutputToLog (int kth, int firstPos, int lastPos, int pivotIndex, int pivot)
{
	logFile << "K = " << kth << endl;
	logFile << "Pivot Index = " << pivotIndex << endl;
	logFile << "First Pos = " << firstPos << endl;
	logFile << "Last Pos = " << lastPos << endl;
	logFile << "Pivot Value = " << pivot << endl;

	return;

}

void OutputToLog (string sentString)
{
	logFile << sentString << endl;

	return;

}