#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Stack.cpp"
#include "City.h"

using namespace std;

int GetDataAmount (ifstream *sentFile);
void DecodeLine (string sentLine, string* leftCity, string* rightCity);
int FindCityIndex (string name, City* cityArray, int cityCount);

int main ()
{
	ifstream cityFile;
	ifstream flightFile;
	ifstream requestFile;

	cityFile.open("cityFile.txt");

	cout << "Opened..." << endl;

	int cityCount = GetDataAmount(&cityFile);

	cout << "Counted..." << endl;
/*
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

*/
	City cities[cityCount];

	cityFile.open("cityFile.txt");

	for (int i = 0; i < cityCount; i++)
	{
		string readString;

		getline(cityFile, readString);

		cities[i].SetCityName(readString);

	}

	for (int i = 0; i < cityCount; i++)
	{
		cities[i].PrintCity();

	}

	cityFile.close();

	flightFile.open("flightFile2.txt");

	int flightCount = GetDataAmount(&flightFile);

	if (flightCount <= 0)
	{
		cout << "Error: Empty or invalid flight file" << endl;

		return 0;

	}

	flightFile.open("flightFile2.txt");

	for (int i = 0; i < flightCount; i++)
	{
		string readString;

		getline(flightFile, readString);

		string fromCity;
		string toCity;

		cout << "Decoding \"" << readString << "\"" << endl;

		DecodeLine(readString, &fromCity, &toCity);

		cout << "Decoded from: " << fromCity << " Decoded to: " << toCity << "---" << endl;

		int fromCityIndex = FindCityIndex(fromCity, cities, cityCount);
		int toCityIndex = FindCityIndex(toCity, cities, cityCount);

		if (fromCityIndex >= 999999 || toCityIndex >= 999999)
		{
			cout << "Error: something very wrong has occurred, either you have >999999 cities or an index could not be found." << endl;

			return 0;

		}

		City* toCityPtr = cities;

		for (int i = 0; i < toCityIndex; i++)
		{
			toCityPtr++;

		}

		cities[fromCityIndex].AddDestination(toCity, toCityPtr);


	}

	for (int i = 0; i < cityCount; i++)
	{
		cities[i].PrintCity();

	}

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

void DecodeLine (string sentLine, string* leftCity, string* rightCity)
{
	char* leftCityChars = new char[15]; //Project spec says city names will be no more than 15 chars
	char* rightCityChars = new char[15];
	char* charTrav;

	charTrav = leftCityChars;

	int charIndex = 0;

	for (charIndex = 0; charIndex < 15; charIndex++)
	{
		char readChar = sentLine.at(charIndex);

		cout << "\tFound: " << readChar << endl;

		if (readChar == ',' || readChar < 65 && readChar != ' ') //<65 means char is not possibly a letter
		{
			*charTrav = '\0';

			break;

		} else
		{
			*charTrav = readChar;

			charTrav++;

		}

	}

	charTrav = rightCityChars;

	charIndex++; //To skip the space after the comma
	charIndex++;

	for (charIndex; charIndex < 31 && charIndex < sentLine.length(); charIndex++) //Two 15 char cities plus a comma and space is 32 chars
	{
		char readChar = sentLine.at(charIndex);

		cout << "\tFound: " << readChar << " @ " << charIndex;


		if ((readChar == ',' || readChar < 65 || readChar == '\n') && readChar != ' ') //<65 means char is not possibly a letter
		{
			cout << " Nulling..." << endl;


			*charTrav = '\0';

			break;

		} else if ((readChar >= 65 && readChar <= 90) || (readChar >= 97 && readChar <= 122) || readChar == ' ')
		{
			cout << " Storing...";

			*charTrav = readChar;

			charTrav++;

		} else
		{
			cout << " Nulling..." << endl;


			*charTrav = '\0';

			break;

		}

		cout << endl;

	}

	*charTrav = '\0';

	cout << "PING" << endl;

	cout << "Read: " << leftCityChars << " " << rightCityChars << endl;

	*leftCity = leftCityChars;
	*rightCity = rightCityChars;

	charTrav = NULL;

	delete[] leftCityChars;
	leftCityChars = NULL;

	delete[] rightCityChars;
	rightCityChars = NULL;

	return;


}

int FindCityIndex (string name, City* cityArray, int cityCount)
{
	City* cityTrav = cityArray;

	for (int i = 0; i < cityCount; i++)
	{
		if ((*cityTrav).GetCityName() == name)
		{
			return i;

		} else
		{
			cityTrav++;

		}

	}

	return 999999; 	//I hope this never happens, means the city doesn't exist in the array
					//value should only cause issues if there is an array of >999999 cities

}