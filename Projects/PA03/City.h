#include <iostream>
/**
*	@file City.h
*
*	@brief This file contains the header of the City class.
*
*	@author Bryce Monaco
*
*	@details This file contains the header for the various members of the City class. Some functions are not used.
*
*	@version 1.0
*
*	@note None.
*/

#include <fstream>
#include <vector>

#ifndef CITY_CLASS
#define CITY_CLASS

using namespace std;

class City
{
	public:
		City();
		City(string name);
		~City();

		void SetVisitedState (bool state);
		void SetCityName (string name);
		void AddDestination (string name, City* destinationPtr, int flightNumber, int cost);	//Adds a destination name and address	

		bool CheckIfDestination (string name);						//Used to see if this city goes to sent city
		bool CheckIfVisited ();
		City* GetDestination (string name);							//Used to return the address of a destination city
		City* GetUnvisitedDestination ();							//Returns the next unvisited destination
		string GetCityName ();
		int GetDestinationCount ();
		vector<City *> GetDestinationPointers ();

		void PrintCity ();											//Prints this city name and its destinations (if any)
		int PrintFlight (City* destinationPtr);
		void PrintCityToLog (ofstream* logFile);



	private:
		string thisCityName;

		bool beenVisited; 					//Used to prevent a city being flown to again in a loop

		vector<string> destinationNames; 	//Contains the names of cities that this city flies to
		vector<City *> destinationPointers; 	//Pointers to the city objects that this city flies to
		vector<int> flightNumbers;
		vector<int> flightCosts;

		int destinations;

};

#endif