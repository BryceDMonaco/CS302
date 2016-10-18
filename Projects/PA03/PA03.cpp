/**
*	@file PA03.cpp
*
*	@brief This is PA03's main driver file.
*
*	@author Bryce Monaco
*
*	@details This is the main driver file for the project, it hands input mostly.
*
*	@version 1.0
*
*	@note !!!!!!!!!!!!SEE LINE 140 TO SWITCH BETWEEN V1 AND V2!!!!!!!!!!!!!!
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h> //Used in DecodeLine(string, string*, string*, int*, int*)

//#include "Stack.cpp"
//#include "City.h"
#include "FlightMapV1.h"
#include "FlightMapV2.h"

using namespace std;

int GetDataAmount (ifstream *sentFile);
void DecodeLine (string sentLine, string* leftCity, string* rightCity); //Used to decode the request file
void DecodeLine (string sentLine, string* leftCity, string* rightCity, int* flightNum, int* cost); //Used to decode the flight file
int FindCityIndex (string name, City* cityArray, int cityCount);
bool CheckIfValidCity (string name, City* cities, int numCities);

ofstream logFile; //Made global so that the output functions can access it without needing it as an argument

int main ()
{
	// Reading in from the input files

	ifstream cityFile;
	ifstream flightFile;
	ifstream requestFile;

	logFile.open("log.txt"); //Will only log the last run
	//logFile.open("log.txt", ios::app); //WIll append to the end of the log

	//Read in the city names
	cityFile.open("cityFile.txt");

	logFile << "Opened City File..." << endl;

	int cityCount = GetDataAmount(&cityFile);

	logFile << "Counted All Cities..." << endl;

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
		cities[i].PrintCityToLog(&logFile);

	}

	cityFile.close();

	//Read in the flights
	flightFile.open("flightFile.txt");

	int flightCount = GetDataAmount(&flightFile);

	if (flightCount <= 0)
	{
		cout << "Error: Empty or invalid flight file" << endl;
		logFile << "Error: Empty or invalid flight file" << endl;

		return 0;

	}

	flightFile.open("flightFile.txt");

	for (int i = 0; i < flightCount; i++)
	{
		string readString;

		getline(flightFile, readString);

		string fromCity;
		string toCity;
		int flightNumber;
		int cost;

		logFile << "Decoding the line: \"" << readString << "\"" << endl;

		DecodeLine(readString, &fromCity, &toCity, &flightNumber, &cost);

		logFile << "Decoded from: " << fromCity << " Decoded to: " << toCity << endl;

		int fromCityIndex = FindCityIndex(fromCity, cities, cityCount);
		int toCityIndex = FindCityIndex(toCity, cities, cityCount);

		if (fromCityIndex >= 999999 || toCityIndex >= 999999)
		{
			cout << "Error: something very wrong has occurred, either you have >999999 cities or an index could not be found." << endl;
			logFile << "Error: something very wrong has occurred, either you have >999999 cities or an index could not be found." << endl;

			return 0;

		}

		City* toCityPtr = cities;

		for (int i = 0; i < toCityIndex; i++)
		{
			toCityPtr++;

		}

		cities[fromCityIndex].AddDestination(toCity, toCityPtr, flightNumber, cost);


	}

/*
	****************************************************************************************************
				BELOW, COMMENT OUT V1 OR V2 TO SELECT WHICH VERSION TO USE
	****************************************************************************************************
*/

	FlightMapV1 map(cities, cityCount);
	//FlightMapV2 map(cities, cityCount);

	//Read in the requests
	requestFile.open("requestFile.txt");

	logFile << "Opened Request File..." << endl;

	int requestCount = GetDataAmount(&requestFile);

	if (requestCount <= 0)
	{
		cout << "Error: Empty or invalid request file" << endl;
		logFile << "Error: Empty or invalid request file" << endl;

		return 0;

	}

	requestFile.open("requestFile.txt");

	for (int i = 0; i < requestCount; i++)
	{
		string readString;

		getline(requestFile, readString);

		string fromCity;
		string toCity;

		logFile << "Decoding \"" << readString << "\"" << endl;

		DecodeLine(readString, &fromCity, &toCity);

		logFile << "Decoded from: " << fromCity << " Decoded to: " << toCity << endl;

		cout << "Request is to fly from " << fromCity << " to " << toCity << "." << endl;

		//Check if both of the cities are valid
		if (!CheckIfValidCity(fromCity, cities, cityCount) && !CheckIfValidCity(toCity, cities, cityCount)) //Both cities are invalid
		{
			cout << "Sorry, HPAir does not serve " << fromCity << " and " << toCity << "." << endl << endl;
			logFile << "Sorry, HPAir does not serve " << fromCity << " and " << toCity << "."<< endl;


			continue;

		} else if (!CheckIfValidCity(fromCity, cities, cityCount)) //From city is invalid
		{
			cout << "Sorry, HPAir does not serve " << fromCity << "." << endl << endl;
			logFile << "Sorry, HPAir does not serve " << fromCity << "."<< endl;


			continue;

		} else if (!CheckIfValidCity(toCity, cities, cityCount))
		{
			cout << "Sorry, HPAir does not serve " << toCity << "." << endl << endl;
			logFile << "Sorry, HPAir does not serve " << toCity << "."<< endl;


			continue;

		}

		int fromCityIndex = FindCityIndex(fromCity, cities, cityCount);
		int toCityIndex = FindCityIndex(toCity, cities, cityCount);

		logFile << "Request is " << fromCity << "(" << fromCityIndex << ") to " << toCity << "(" << toCityIndex << ")" << endl;


		if (fromCityIndex >= 999999 || toCityIndex >= 999999)
		{
			cout << "Error: something very wrong has occurred, either you have >999999 cities or an index could not be found." << endl;

			return 0;

		}

		if (map.IsPath (&cities[fromCityIndex], &cities[toCityIndex]))
		{
			logFile << "A valid path was found." << endl;

		} else
		{
			logFile << "A valid path could not be found." << endl;


		}

		cout << endl;

	}

	logFile << "Program ran successfully. Terminating." << endl;

	logFile.close();

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

		//cout << "\tFound: " << readChar << endl;

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

	//This loop will end, no matter what, when charIndex equals the length of sentLine, so the two null assignments technically are useless
	for (charIndex; charIndex < 31 && charIndex < sentLine.length(); charIndex++) //Two 15 char cities plus a comma and space is 32 chars
	{
		char readChar = sentLine.at(charIndex);

		//cout << "\tFound: " << readChar << " @ " << charIndex;


		if ((readChar == ',' || readChar < 65 || readChar == '\n') && readChar != ' ') //<65 means char is not possibly a letter
		{
			//cout << " Nulling..." << endl;


			*charTrav = '\0';

			break;

		} else if ((readChar >= 65 && readChar <= 90) || (readChar >= 97 && readChar <= 122) || readChar == ' ')
		{
			//cout << " Storing...";

			*charTrav = readChar;

			charTrav++;

		} else
		{
			//cout << " Nulling..." << endl;


			*charTrav = '\0';

			break;

		}

		//cout << endl;

	}

	*charTrav = '\0'; //The for loop above ends at the last char of the line read in (no null at the end) so one must be manually added

	//cout << "Read: " << leftCityChars << " " << rightCityChars << endl;

	*leftCity = leftCityChars;
	*rightCity = rightCityChars;

	charTrav = NULL;

	delete[] leftCityChars;
	leftCityChars = NULL;

	delete[] rightCityChars;
	rightCityChars = NULL;

	return;


}

void DecodeLine (string sentLine, string* leftCity, string* rightCity, int* flightNum, int* cost)
{
	char* leftCityChars = new char[15]; //Project spec says city names will be no more than 15 chars
	char* rightCityChars = new char[15];
	char* charTrav;

	charTrav = leftCityChars;

	int charIndex = 0;

	for (charIndex = 0; charIndex < 15; charIndex++)
	{
		char readChar = sentLine.at(charIndex);

		//cout << "\tFound: " << readChar << endl;

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

	//This loop will end, no matter what, when charIndex equals the length of sentLine, so the two null assignments technically are useless
	for (charIndex; charIndex < 31 && charIndex < sentLine.length(); charIndex++) //Two 15 char cities plus a comma and space is 32 chars
	{
		char readChar = sentLine.at(charIndex);

		//cout << "\tFound: " << readChar << " @ " << charIndex;


		if ((readChar == ',' || readChar < 65 || readChar == '\n') && readChar != ' ') //<65 means char is not possibly a letter
		{
			//cout << " Nulling..." << endl;


			*charTrav = '\0';

			break;

		} else if ((readChar >= 65 && readChar <= 90) || (readChar >= 97 && readChar <= 122) || readChar == ' ')
		{
			//cout << " Storing...";

			*charTrav = readChar;

			charTrav++;

		} else
		{
			//cout << " Nulling..." << endl;


			*charTrav = '\0';

			break;

		}

		//cout << endl;

	}

	*charTrav = '\0'; //The for loop above ends at the last char of the line read in (no null at the end) so one must be manually added

	//Read in the flight number
	bool hasReadNumber = false;
	Stack<int> intStack;

	for (charIndex; charIndex < sentLine.length(); charIndex++)
	{
		char readChar = sentLine.at(charIndex);

		if ((readChar == ' ' || readChar == '\t') && !hasReadNumber) //Skip whitespace until a number is found
		{
			continue;

		} else if (readChar >= '0' && readChar <= '9') //Char is a number
		{
			int convertedChar = (int) readChar - '0';

			intStack.push(convertedChar);

			hasReadNumber = true;

		} else if ((readChar == ' ' || readChar == '\t') && hasReadNumber) //Should be whitespace after the number
		{
			break;

		}
	}

	int readFlightNumber = 0;

	for (int i = 0; !intStack.isEmpty(); i++)
	{
		int value = intStack.pop() * (int) pow(10, i); //Multiply the value by 10^i

		readFlightNumber += value;

	}

	hasReadNumber = false;
	intStack.clear();

	for (charIndex; charIndex < sentLine.length(); charIndex++)
	{
		char readChar = sentLine.at(charIndex);

		if ((readChar == ' ' || readChar == '\t') && !hasReadNumber) //Skip whitespace until a number is found
		{
			continue;

		} else if (readChar >= '0' && readChar <= '9') //Char is a number
		{
			int convertedChar = (int) readChar - '0';

			intStack.push(convertedChar);

			hasReadNumber = true;

		} else if ((readChar == ' ' || readChar == '\t') && hasReadNumber) //Should be whitespace after the number
		{
			break;

		}
	}

	int readPrice = 0;

	for (int i = 0; !intStack.isEmpty(); i++)
	{
		int value = intStack.pop() * (int) pow(10, i); //Multiply the value by 10^i

		readPrice += value;

	}

	//cout << "Read: " << leftCityChars << " " << rightCityChars << endl;

	*leftCity = leftCityChars;
	*rightCity = rightCityChars;
	*cost = readPrice;
	*flightNum = readFlightNumber;

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

bool CheckIfValidCity (string name, City* cities, int numCities)
{
	bool isCity = false;
	City* cityTrav = cities;

	for (int i = 0; i < numCities; i++)
	{
		if ((*cityTrav).GetCityName() == name)
		{
			isCity = true;

			break;
		}

		cityTrav++;
	}

	cityTrav = NULL;

	return isCity;

}