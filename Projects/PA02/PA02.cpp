//  Created by Shehryar Khattak for CS302 Spring 2016 class.
//	Updated and modified by Bryce Monaco, CS302 Fall 2016

/**
*	@file PA02.cpp
*
*	@brief This file contains the code for Programming Assignment 2, finding the kth smallest value in a set of data.
*
*	@author Bryce Monaco (base file by Shehryar Khattak)
*
*	@details This file contains the code for all functions used in the PA02 assignment. The user inputs a value k and the program returns the kth smallest value in given data.
*
*	@version 1.0
*
*	@note The program assumes that the data file is named "data02.txt", if it is not a new file name can be given as a command line argument
*/

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

	logFile.close();

	//Output DO NOT MODIFY
	cout<< "kth smallest value = " << kSmall_val << endl;

	delete[] values;
	values = NULL;

	firstVal = NULL;
	lastVal = NULL;

	return 0;
}

/**
*	@brief This function is used to read in the data from the given data file.
*
*	@details The function continuously reads in data line by line until it reaches the end of the file. It stores the values in the array pointed to by arrayStart.
*
*	@par Algorithm Continuously reads through the file checking if it has reached the end of the file. It reads in a new value and stores it in the current memory position in the array.
*
*	@param[in] sentFile The data file opened in main(), contains the data to be read in.
*
*	@param[in] arrayStart The pointer to the start of the array to store the values in.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
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

/**
*	@brief This function is used to scan through the data file to see the amount of values within the file.
*
*	@details The function continuously reads through the data file to count the number of values within it. The number found is used to dynamically size the values array in main().
*
*	@par Algorithm Continuously reads through the file checking if it has reached the end of the file. It increments an integer to keep count of the values and returns it at the end of the file.
*
*	@param[in] sentFile The data file opened in main(), contains the data to be read in.
*
*	@param[out] count The number of values within the data file.
*
*	@return Returns the amount of valid values within the data file.
*
*	@note None.
*
*/
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

/**
*	@brief This function is used to print every value within the array.
*
*	@details This function starts at the address pointed to by arrayStart and prints values until zie amount of values have been printed.
*
*	@par Algorithm Prints each value within the array pointed to by arrayStart.
*
*	@param[in] arrayStart The pointer to the start of the array to store the values in.
*
*	@param[in] size The amount of values within the array, used to prevent the arrayTrav pointer from going out of bounds.
*
*	@param[out] None.
*
*	@return None.
*
*	@note If size is incorrect then the entire array might not be printed or the arrayTrav will run out of bounds. Output is formatted as (index number) value.
*
*/
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

	return;

}

/**
*	@brief This function is used to print the data within a given scope of the values array. <P> denotes that the value is the pivot.
*
*	@details This function this function starts at the value within the array at index from and prints all values up to and including the value at index to. Used for printing partitions.
*
*	@par Algorithm Moves the arrayTrav to the start of the scope, then prints all values starting from arrayStart[from] and ending with arrayStart[to].
*
*	@param[in] arrayStart The pointer to the start of the array to store the values in.
*
*	@param[in] from The array index value of where to start printing.
*
*	@param[in] to The array index value of the end of the scope.
*
*	@param[in] pivotIndex The index value of the pivot, used to print which value is the pivot.
*
*	@param[out] None.
*
*	@return None.
*
*	@note Output is formatted as (index number) value. <P> to the right of a value denotes that it is the pivot.
*
*/
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

/**
*	@brief This function is used to find the kth smallest value within an array of values.
*
*	@details This function is used to find the kth smalles value with in an array of values. It recursively calls itself and sends a partition of the previously scanned array until it finds the value.
*
*	@par Algorithm The main algorithm of this function is the partitioning algorithm which puts values less than the pivot value to the left (left partition) and values greater than the pivot to the right (right partition). It then determines if the value it is searching for is the pivot, is in the left partition, or is in the right partion. If the value is in the left or right partition it makes a recursive call, sending it the scope of the respective partition that it wants to search, if the value it is searching for is in the pivot then the pivot value is returned and the recursion ends.
*	
*	@param[in] kth The value to search for.
*
*	@param[in] arrayStart The pointer to the start of the array to store the values in.
*
*	@param[in] firstPos The index value of the array to start the scope at.
*
*	@param[in] lastPos The index value of the array to end the scope at.
*
*	@param[out] pivot Returns pivot if it is the kth smallest value in the array
*
*	@return The value of pivot is returned if it is the kth smalles value within the given array, otherwise the function makes a recursive call.
*
*	@note None.
*
*/
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

/**
*	@brief This function is used to print various values that are important for debugging the partitioning algorithm.
*
*	@details This function simply formats and prints the values sent to it from the current run of the FindKthValue function.
*
*	@param[in] kth The value to search for.
*
*	@param[in] firstPos The index value of the array to start the scope at.
*
*	@param[in] lastPos The index value of the array to end the scope at.
*
*	@param[in] pivotIndex The index value of the pivot, used to print which value is the pivot.
*
*	@param[in] pivot The value of the pivot.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void OutputToLog (int kth, int firstPos, int lastPos, int pivotIndex, int pivot)
{
	logFile << "K = " << kth << endl;
	logFile << "Pivot Index = " << pivotIndex << endl;
	logFile << "First Pos = " << firstPos << endl;
	logFile << "Last Pos = " << lastPos << endl;
	logFile << "Pivot Value = " << pivot << endl;

	return;

}

/**
*	@brief This function simply prints a given string to the output file.
*
*	@details This function simply prints a given string to the output file and then moves to the next line.
*
*	@param[in] sentString The string to be printed
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void OutputToLog (string sentString)
{
	logFile << sentString << endl;

	return;

}