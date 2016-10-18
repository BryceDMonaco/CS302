/**
*	@file City.cpp
*
*	@brief This file contains the implementation of the City class.
*
*	@author Bryce Monaco
*
*	@details This file contains the implementations for the various members of the City class. Some functions are not used.
*
*	@version 1.0
*
*	@note None.
*/

#include "City.h"

using namespace std;

/**
*	@brief The default constructor of a City object
*
*	@details This constructor initializes values of a City object to default values
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
City::City ()
{
	thisCityName = "NO NAME ASSIGNED";

	beenVisited = false;
	destinations = 0;

}

/**
*	@brief The parameterized constructor of a City object
*
*	@details This constructor initializes values of a City object to default values except for the name
*
*	@par Algorithm None.
*
*	@param[in] name The name to give to the new City object.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
City::City (string name)
{
	thisCityName = name;

	beenVisited = false;
	destinations = 0;

}

/**
*	@brief The destructor of a City object
*
*	@details This is meant to remove any presense of a City object on memory.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
City::~City ()
{
	//No member needs to be destructed manually

}

/**
*	@brief Marks if a city has been visited
*
*	@details Sets the value of beenVisited to the sent value
*
*	@par Algorithm None.
*
*	@param[in] state The state (true/false) to set beenVisited 
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void City::SetVisitedState (bool state)
{
	beenVisited = state;

	return;

}

/**
*	@brief Changes a city's name
*
*	@details Sets the value of thisCityName to the sent value
*
*	@par Algorithm None.
*
*	@param[in] name The new name to assign to the city.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void City::SetCityName (string name)
{
	thisCityName = name;

	return;

}

/**
*	@brief Adds a new detination for the city to go to
*
*	@details Adds the various sent values to their respective arrays to keep track of adjacent cities
*
*	@par Algorithm Checks if the destination already exists, if it doesn't then it is created.
*
*	@param[in] name The name of the destination
*
*	@param[in] destinationPtr The pointer to the destination City object
*
*	@param[in] flightNumber The flight number of the flight between this city and the destination
*
*	@param[in] cost The price of the flight from here to there
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void City::AddDestination (string name, City* destinationPtr, int flightNumber, int cost)
{
	for (unsigned int i = 0; i < destinationNames.size(); i++) //vecotr.size() returns an unsigned int so i must be unsigned
	{
		if (destinationNames[i] == name)
		{
			return; //There is already a city with this name

		}
	}

	destinationNames.push_back(name);
	destinationPointers.push_back(destinationPtr);
	flightNumbers.push_back(flightNumber);
	flightCosts.push_back(cost);

	destinations++;

	return;

}

/**
*	@brief Checks if a city is a destination from here
*
*	@details Checks if any of its destinations match the name of the one sent
*
*	@par Algorithm None.
*
*	@param[in] name The name of the city to look for
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
bool City::CheckIfDestination (string name)
{
	for (unsigned int i = 0; i < destinationNames.size(); i++) //vecotr.size() returns an unsigned int so i must be unsigned
	{
		if (destinationNames[i] == name)
		{
			return true; //There is a city with this name

		}
	}

	return false; //There is not a city with this name

}

/**
*	@brief Checks if this city has been visited
*
*	@details Returns the value of beenVisited
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the value of beenVisited
*
*	@note None.
*
*/
bool City::CheckIfVisited ()
{
	return beenVisited;

}

/**
*	@brief Gives the pointer to the destination sent
*
*	@details If the destination exists from this city it will return a pointer to its object
*
*	@par Algorithm None.
*
*	@param[in] name The name of the city to search for
*
*	@param[out] None.
*
*	@return Returns a pointer to the city that was searched for.
*
*	@note Assumes that the city does exist as a destination
*
*/
City* City::GetDestination (string name)
{
	unsigned int position = 0;

	while (destinationNames[position] != name)
	{
		position++;

	}

	return destinationPointers[position];

}

/**
*	@brief Returns an unvisted destination
*
*	@details Searches through its destinations to find one that has not been visited yet and returns it.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return A pointer to the first found unvisited city, NULL if none.
*
*	@note None.
*
*/
City* City::GetUnvisitedDestination ()
{
	for (int i = 0; i < destinations; i++)
	{
		if (!(*(destinationPointers[i])).CheckIfVisited()) //If it hasn't been visited
		{
			return destinationPointers[i];

		}

	}

	return NULL;

}

/**
*	@brief Gets a city's name
*
*	@details Returns the value at thisCityName
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return The string of the city's name
*
*	@note None.
*
*/
string City::GetCityName ()
{
	return thisCityName;

}

/**
*	@brief Gets a city's destination count
*
*	@details Returns the value at destinations
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return The number of destinations this city has
*
*	@note None.
*
*/
int City::GetDestinationCount ()
{
	return destinations;

}

/**
*	@brief Gets a city's destination pointer array
*
*	@details Returns a copy of the destination pointer vector
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return A copy of the vector of destinations that this city has
*
*	@note None.
*
*/
vector<City *> City::GetDestinationPointers ()
{
	return destinationPointers;

}

/**
*	@brief Prints a city and its destinations
*
*	@details Prints the city, then loops through its string vector printing its destinations
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void City::PrintCity ()
{
	cout << thisCityName << " has the destinations: {";

	if (destinations <= 0)
	{
		cout << "(No Destinations)";


	} else
	{
		for (unsigned int i = 0; i < destinationNames.size(); i++)
		{

			if (i == destinationNames.size() - 1)
			{
				cout << destinationNames[i] << " Flight #" << flightNumbers[i] << " Cost: $" << flightCosts[i];


			} else
			{
				cout << destinationNames[i] << " Flight #" << flightNumbers[i] << " Cost: $" << flightCosts[i] << ",";

			}

		}

	}

	cout << "}" << endl;

	return;

}

/**
*	@brief Prints the flight information
*
*	@details Prints the flight information from this city to the destination city
*
*	@par Algorithm None.
*
*	@param[in] destinationPtr A pointer to the destination city object.
*
*	@param[out] None.
*
*	@return Returns the cost of the flight from here to there.
*
*	@note None.
*
*/
int City::PrintFlight (City* destinationPtr)
{
	int destinationIndex = 0;
	string destinationName = (*destinationPtr).GetCityName();

	int index = 0;

	for (index; index < destinations; index++)
	{
		if (destinationNames[index] == destinationName)
		{
			break;

		}
	}

	cout << "Flight #" << flightNumbers[index] << " from " << thisCityName << " to " << destinationName;
	cout << "\tCost: $" << flightCosts[index] << endl;

	return flightCosts[index];

}

/**
*	@brief Prints a city and its destinations to the log file
*
*	@details Prints the city, then loops through its string vector printing its destinations to the log
*
*	@par Algorithm None.
*
*	@param[in] logFile A pointer to the log file to be output to.
*
*	@param[out] None.
*
*	@return None.
*
*	@note Assumes that the logFile has already been opened and will be closed somewhere else.
*
*/
void City::PrintCityToLog (ofstream* logFile)
{
	(*logFile) << thisCityName << " has the destinations: {";

	if (destinations <= 0)
	{
		(*logFile) << "(No Destinations)";


	} else
	{
		for (unsigned int i = 0; i < destinationNames.size(); i++)
		{

			if (i == destinationNames.size() - 1)
			{
				(*logFile) << destinationNames[i] << " Flight #" << flightNumbers[i] << " Cost: $" << flightCosts[i];


			} else
			{
				(*logFile) << destinationNames[i] << " Flight #" << flightNumbers[i] << " Cost: $" << flightCosts[i] << ",";

			}

		}

	}

	(*logFile) << "}" << endl;

	return;

}