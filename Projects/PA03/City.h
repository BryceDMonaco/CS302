#include <iostream>
#include <vector>

using namespace std;

class City
{
	public:
		City();
		City(string name);
		~City();

		void SetVisitedState (bool state);
		void SetCityName (string name);
		void AddDestination (string name, City* destinationPtr);	//Adds a destination name and address	

		bool CheckIfDestination (string name);						//Used to see if this city goes to sent city
		bool CheckIfVisited ();
		City* GetDestination (string name);							//Used to return the address of a destination city
		City* GetUnvisitedDestination ();							//Returns the next unvisited destination
		string GetCityName ();
		int GetDestinationCount ();

		void PrintCity ();											//Prints this city name and its destinations (if any)



	private:
		string thisCityName;

		bool beenVisited; 					//Used to prevent a city being flown to again in a loop

		vector<string> destinationNames; 	//Contains the names of cities that this city flies to
		vector<City *> destinationPointers; 	//Pointers to the city objects that this city flies to

		int destinations;

};