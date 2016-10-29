/**
*	@file FlightMapV2.h
*
*	@brief This file contains the header of the FLightMapV2 class.
*
*	@author Bryce Monaco
*
*	@details This file contains the header for the various members of the FlightMapV2 class.
*
*	@version 1.0
*
*	@note None.
*/

#include <string>
#include "Stack.cpp"
#include "City.h"

using namespace std;

class FlightMapV2
{
	public:
		FlightMapV2(City* sentCityHead, int sentNumCities);
		~FlightMapV2();

		void MarkVisited (City* sentCity);
		void UnvisitAll (); //Resets the visited state in all cities
		void UnvisitAll (vector<City *> *sentVector);
		City* GetNextCity (City* fromCity); //Returns a pointer to the next unvisited city
		bool IsPath (City* originCity, City* destinationCity, ofstream* logFile); //Checks for a sequence of flights between the cities 

	private:
		City* cityHead;

		int numCities;

};