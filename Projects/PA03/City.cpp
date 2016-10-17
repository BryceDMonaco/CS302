/*
Class City
{
	public:
		City();
		City(string name = "NO NAME ASSIGNED");
		~City();

		void SetVisitedState (bool state);
		void SetCityName (string name);
		void AddDestination (string name, City* destinationPtr);	//Adds a destination name and address	

		bool CheckIfDestination (string name);						//Used to see if this city goes to sent city
		City* GetDestination (string name);							//Used to return the address of a destination city

		void PrintCity ();											//Prints this city name and its destinations (if any)



	private:
		string thisCityName;

		bool beenVisited = false; 			//Used to prevent a city being flown to again in a loop

		vector<string> destinationNames; 	//Contains the names of cities that this city flies to
		vector<City*> destinationPointers; 	//Pointers to the city objects that this city flies to

		int destinations = 0;

}
*/

#include "City.h"

using namespace std;

City::City ()
{
	thisCityName = "NO NAME ASSIGNED";

	beenVisited = false;
	destinations = 0;

}

City::City (string name)
{
	thisCityName = name;

	beenVisited = false;
	destinations = 0;

}

City::~City ()
{
	//No member needs to be destructed manually

}

void City::SetVisitedState (bool state)
{
	beenVisited = state;

	return;

}

void City::SetCityName (string name)
{
	thisCityName = name;

	return;

}

void City::AddDestination (string name, City* destinationPtr)
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

	destinations++;

	return;

}

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

bool City::CheckIfVisited ()
{
	return beenVisited;

}

City* City::GetDestination (string name)
{
	unsigned int position = 0;

	while (destinationNames[position] != name)
	{
		position++;

	}

	return destinationPointers[position];

}

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

string City::GetCityName ()
{
	return thisCityName;

}

int City::GetDestinationCount ()
{
	return destinations;

}


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
				cout << destinationNames[i];


			} else
			{
				cout << destinationNames[i] << ",";

			}

		}

	}

	cout << "}" << endl;

	return;

}