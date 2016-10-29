/**
*	@file FlightMapV1.cpp
*
*	@brief This file contains the implementation of the FLightMapV1 class.
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation for the various members of the FlightMapV1 class.
*
*	@version 1.0
*
*	@note None.
*/

#ifndef MAP_V1
#define MAP_V1

#include "FlightMapV1.h"

using namespace std;

/*
#include <string>
#include "Stack.cpp"
#include "City.h"

using namespace std;

class FlightMapV1
{
	public:
		FlightMapV1(City* sentCityHead, int sentNumCities);
		~FlightMapV1();

		void MarkVisited (City* sentCity);
		void UnvisitAll (); //Resets the visited state in all cities
		City* GetNextCity (City* fromCity); //Returns a pointer to the next unvisited city
		bool IsPath (City* originCity, City* destinationCity); //Checks for a sequence of flights between the cities 

	private:
		City* cityHead;
		//City* originCity;
		
		int numCities;

};
*/

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
FlightMapV1::FlightMapV1 (City* sentCityHead, int sentNumCities)
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
FlightMapV1::~FlightMapV1 ()
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
void FlightMapV1::MarkVisited (City* sentCity)
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
void FlightMapV1::UnvisitAll ()
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
City* FlightMapV1::GetNextCity (City* fromCity)
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
bool FlightMapV1::IsPath (City* originCity, City* destinationCity, ofstream* logFile)
{
	Stack<string> cityStack; //Keeps track of the city names
	Stack<City *> cityPTRStack; //Keeps track of the city objects, should be pushed/popped at the same time as cityStack

	UnvisitAll();

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