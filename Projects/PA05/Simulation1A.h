/**
*	@file Simulation1A.h
*
*	@brief This is the header of the Simulation1A class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the Simulation1A class
*
*	@version 1.0
*
*	@note The implementation of this class is incomplete.
*/

#include <iostream>

#include "ArrayQueueBank.h"
#include "ArrayQueue.h"
#include "Client.h"

using namespace std;

class Simulation1A
{
	public:
		Simulation1A ();
		Simulation1A (Client* sentClients, int count);
		~Simulation1A ();

		void SendClients (Client* sentClients, int count);
		void ResetSimulation ();

		void Simulate ();
		void ProcessArrival (Client* sentClient, int time);
		void ProcessDeparture (Client* sentClient, int time);

	private:
		Client* clients;
		ArrayQueueBank clientQueue; //All of the clients in order of arrival time
		ArrayQueueBank bankQueue; //The actual line of the bank
		ArrayQueue arrivalEvents;
		ArrayQueue departureEvents;

		int clientCount;
		bool tellerAvailable;

};