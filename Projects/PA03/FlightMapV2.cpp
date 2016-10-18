#ifndef MAP_V2
#define MAP_V2

#include "FlightMapV2.h"

using namespace std;

/*
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
		City* GetNextCity (City* fromCity); //Returns a pointer to the next unvisited city
		bool IsPath (City* originCity, City* destinationCity); //Checks for a sequence of flights between the cities 

	private:
		City* cityHead;
		//City* originCity;
		
		int numCities;

};
*/

FlightMapV2::FlightMapV2 (City* sentCityHead, int sentNumCities)
{
	cityHead = sentCityHead;

	numCities = sentNumCities;

}

FlightMapV2::~FlightMapV2 ()
{
	cityHead = NULL;

}

void FlightMapV2::MarkVisited (City* sentCity)
{
	(*sentCity).SetVisitedState(true);

	return;

}

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

void FlightMapV2::UnvisitAll (vector<City *> *sentVector)
{
	for (unsigned int i = 0; i < (*sentVector).size(); i++)
	{
		(*((*sentVector).at(i))).SetVisitedState(false);

	}

	return;

} 

City* FlightMapV2::GetNextCity (City* fromCity)
{
	return (*fromCity).GetUnvisitedDestination(); //Will return NULL if there are no more unvisited cities!!!

}

bool FlightMapV2::IsPath (City* originCity, City* destinationCity)
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
	//cityStack.printFlights();

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