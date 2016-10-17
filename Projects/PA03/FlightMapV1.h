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
