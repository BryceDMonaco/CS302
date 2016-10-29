/**
*	@file FlightMapV2.cpp
*
*	@brief This file contains the implementation of the FLightMapV2 class.
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation for the various members of the FlightMapV2 class.
*
*	@version 1.0
*
*	@note None.
*/

#ifndef MAP_V2
#define MAP_V2

#include "FlightMapV2.h"

using namespace std;

/**
*	@brief The parameter constructor for a FlightMapV2 object
*
*	@details The parameter constructor for a FlightMapV2 object
*
*	@par Algorithm None.
*
*	@param[in] sentCityHead Pointer to the start of the city array
*
*	@param[in] sentNumCities the number of cities in the city array
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
FlightMapV2::FlightMapV2 (City* sentCityHead, int sentNumCities)
{
	cityHead = sentCityHead;

	numCities = sentNumCities;

}

/**
*	@brief The destructor for a FlightMapV2 object
*
*	@details The destructor for a FlightMapV2 object
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
FlightMapV2::~FlightMapV2 ()
{
	cityHead = NULL;

}

/**
*	@brief Marks the sent city as visited
*
*	@details Calls the sent city object's SetVisitedState function with the argument true
*
*	@par Algorithm None.
*
*	@param[in] sentCity Pointer to the city to mark as visited
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void FlightMapV2::MarkVisited (City* sentCity)
{
	(*sentCity).SetVisitedState(true);

	return;

}

/**
*	@brief Marks all cities as unvisited
*
*	@details Starts at the beginning of the city array and mark each city as unvisited
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] All cities are now reset to be unvisited.
*
*	@return None.
*
*	@note None.
*
*/
void FlightMapV2::UnvisitAll ()
{
	City* cityTrav = cityHead;

	for (int i = 0; i < numCities; i++)
	{
		(*cityTrav).SetVisitedState(false);

		cityTrav++;

	}

	cityTrav = NULL;

	return;

}

/**
*	@brief Marks all cities as unvisited inside of a vector of cities
*
*	@details Starts at the beginning of the city vector and mark each city as unvisited
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] All cities in the vector are now reset to be unvisited.
*
*	@return None.
*
*	@note None.
*
*/
void FlightMapV2::UnvisitAll (vector<City *> *sentVector)
{
	for (unsigned int i = 0; i < (*sentVector).size(); i++)
	{
		(*((*sentVector).at(i))).SetVisitedState(false);

	}

	return;

} 

/**
*	@brief Gets the next unvisited city
*
*	@details Gets the first unvisited city from the sent city's destinations
*
*	@par Algorithm None.
*
*	@param[in] fromCity Pointer to the city which will have its destinations checked
*
*	@param[out] A pointer to a city.
*
*	@return Returns a pointer to the first unvisited city found, NULL if none found.
*
*	@note None.
*
*/
City* FlightMapV2::GetNextCity (City* fromCity)
{
	return (*fromCity).GetUnvisitedDestination(); //Will return NULL if there are no more unvisited cities!!!

}

/**
*	@brief Checks if there is a valid flight path between the two cities
*
*	@details Moves through the cities searching for a path from originCity to destinationCity
*
*	@par Algorithm Moves through destinations until it finds a valid path to the destination or it is out of possible routes. Marks cities as visited to avoid re-visiting them.
*
*	@param[in] originCity Pointer to the city which the search starts from
*
*	@param[in] destinationCity Pointer to the destination city
*
*	@param[out] A bool whether or not a path exists
*
*	@return Returns true if there is a valid path, false otherwise.
*
*	@note None.
*
*/
bool FlightMapV2::IsPath (City* originCity, City* destinationCity, ofstream* logFile)
{
	Stack<string> cityStack; //Keeps track of the city names
	Stack<City *> cityPTRStack; //Keeps track of the city objects, should be pushed/popped at the same time as cityStack
	vector<City *> tryNextArray = (*originCity).GetDestinationPointers(); //Exclusive to v2, an array of pointers to try next

	
	cityStack.push((*originCity).GetCityName());
	cityPTRStack.push(originCity);

	MarkVisited(originCity);

	City* topCity = cityPTRStack.peek();

	while (!cityStack.isEmpty() && topCity != destinationCity)
	{

		City* nextCity = GetNextCity(topCity);

		if (nextCity == NULL)
		{
			cityStack.pop();
			cityPTRStack.pop();

		} else
		{
			cityStack.push((*nextCity).GetCityName());
			cityPTRStack.push(nextCity);

			MarkVisited(nextCity);

		}

		if (!cityStack.isEmpty())
		{
			topCity = cityPTRStack.peek();

		}

	}
	
/*
	cityStack.push((*originCity).GetCityName());
	cityPTRStack.push(originCity);

	MarkVisited(originCity);

	//City* onCity = originCity;
	City* nextCity = tryNextArray[tryNextArray.size() - 1]; //Moves to the end of the array
	vector<City *> thisCityDestinations;

	while (!tryNextArray.empty() && onCity != destinationCity)
	{
		if ((*nextCity).GetDestinationCount() <= 0) //If the city in focus has no destinations it is a dead end
		{
			tryNextArray.pop_back();

			nextCity = tryNextArray[tryNextArray.size() - 1];

		} else if (thisCityDestinations.empty())
		{
			thisCityDestinations = (*nextCity).GetDestinationPointers();

			continue;

		}else
		{
			nextCity = thisCityDestinations[thisCityDestinations.size() - 1];

		}
		

	}
*/
	cityStack.printFlightsToLog(logFile);

	bool finalBool = !cityPTRStack.isEmpty();

	if (!cityPTRStack.isEmpty())
	{
		Stack<City *> reverseCityPTRStack;

		while (!cityPTRStack.isEmpty())
		{
			reverseCityPTRStack.push(cityPTRStack.pop());

		}

		int totalCost = 0;

		while (!reverseCityPTRStack.isEmpty())
		{
			City* currentCity = reverseCityPTRStack.pop();
			City* nextCity = reverseCityPTRStack.peek();

			if (nextCity != NULL)
			{
				totalCost += (*currentCity).PrintFlight(nextCity);

			}
		}

		cout << "Total Cost....................$" << totalCost << endl;
	} else
	{
		cout << "Sorry, HPAir does not fly from " << (*originCity).GetCityName() << " to " << (*destinationCity).GetCityName() << "." << endl;

	}

	

	return finalBool;
}

#endif