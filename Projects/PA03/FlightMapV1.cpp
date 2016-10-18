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

FlightMapV1::FlightMapV1 (City* sentCityHead, int sentNumCities)
{
	cityHead = sentCityHead;

	numCities = sentNumCities;

}

FlightMapV1::~FlightMapV1 ()
{
	cityHead = NULL;

}

void FlightMapV1::MarkVisited (City* sentCity)
{
	(*sentCity).SetVisitedState(true);

	return;

}

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

City* FlightMapV1::GetNextCity (City* fromCity)
{
	return (*fromCity).GetUnvisitedDestination(); //Will return NULL if there are no more unvisited cities!!!

}

bool FlightMapV1::IsPath (City* originCity, City* destinationCity)
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
