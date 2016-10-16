#include <iostream>
#include <fstream>
#include <string>

#include "Stack.cpp"
#include "City.h"

using namespace std;

int GetDataAmount (ifstream *sentFile);

int main ()
{
	ifstream cityFile;

	cityFile.open("cityFile.txt");

	cout << "Opened..." << endl;

	int cityCount = GetDataAmount(&cityFile);

	cout << "Counted..." << endl;

	Stack<string> cityStack(cityCount);	

	cityStack.print();

	cityFile.open("cityFile.txt");


	for (int i = 0; i < cityCount; i++)
	{
		string readString;

		getline(cityFile, readString);

		cityStack.push(readString);

	}

	cityStack.print();

	cout << "Top is: " << cityStack.peek() << endl;

	return 0;

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
*	@return Returns the amount of valid values within the data file. Plus one because eof isn't marked until after with getline
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
		string temp;

		getline(*sentFile, temp);

		if ((*sentFile).eof())
		{
			continueRead = false;

		} else
		{
			count++;

		}

	}

	(*sentFile).close();

	return count + 1;

}