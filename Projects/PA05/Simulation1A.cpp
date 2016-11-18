/**
*	@file Simulation1A.cpp
*
*	@brief This is the implementation of the Simulation1A class
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation of the Simulation1A class
*
*	@version 1.0
*
*	@note The implementation of this class is incomplete.
*/

#include "Simulation1A.h"

/**
*	@brief The default constructor of a Simulation1A object
*
*	@details This constructor initializes values of a Simulation1A object to default values
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
Simulation1A::Simulation1A ()
{
	clients = NULL;
	clientCount = 99999;
	tellerAvailable = true;

	bankQueue = ArrayQueueBank(clientCount);
	clientQueue = ArrayQueueBank(clientCount);

}

/**
*	@brief The default constructor of a Simulation1A object
*
*	@details This constructor initializes values of a Simulation1A object to sent values
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
Simulation1A::Simulation1A (Client* sentClients, int count)
{
	clients = sentClients;
	clientCount = count;
	tellerAvailable = true;

	bankQueue = ArrayQueueBank(clientCount);
	clientQueue = ArrayQueueBank(clientCount);

}

/**
*	@brief The destructor of a Simulation1A object
*
*	@details Safely removes this object from memeory.
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
Simulation1A::~Simulation1A ()
{
	clients = NULL;

}

/**
*	@brief Sets the clients of this simulation
*
*	@details Allows the user to change the clients used for the simulation
*
*	@par Algorithm None.
*
*	@param[in] sentClients The address of the Clients array to be used
*
*	@param[in] count The amount of Clients in the array.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void Simulation1A::SendClients (Client* sentClients, int count)
{
	clients = sentClients;

	clientCount = count;

	return;

}

/**
*	@brief Resets the simulation.
*
*	@details Completely dequeues both queues of the simulation.
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
void Simulation1A::ResetSimulation () //Clears the line
{
	while (!bankQueue.IsEmpty())
	{
		bankQueue.Dequeue();


	}

	while (!clientQueue.IsEmpty())
	{
		clientQueue.Dequeue();
		

	}

	return;

}

/**
*	@brief Runs the simulation
*
*	@details Runs the simulation using the current clients and count.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note This function couldn't be fully implemented due to time constraints.
*
*/
void Simulation1A::Simulate ()
{
	ResetSimulation(); //Make sure the queue is empty

	//Enter all of the clients into the client queue
	for (int i = 0; i < clientCount; i++)
	{
		clientQueue.Enqueue(*clients + i);

	}

	while (!clientQueue.IsEmpty())
	{


	}

}

/**
*	@brief Processes the arrival of a client
*
*	@details Takes the client that arrived and adds it to the bankQueue.
*
*	@par Algorithm None.
*
*	@param[in] sentClient Pointer to the client that arrived
*
*	@param[in] time The time that the client arrived.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void Simulation1A::ProcessArrival (Client* sentClient, int time)
{
	Client* frontClient = sentClient;

	clientQueue.Dequeue(); //Remove client from the client queue

	bankQueue.Enqueue(frontClient);


}

/**
*	@brief Processes the departure of a client
*
*	@details Takes the client that departed and adds removes it from the bank queue.
*
*	@par Algorithm None.
*
*	@param[in] sentClient Pointer to the client that arrived
*
*	@param[in] time The time that the client left.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void Simulation1A::ProcessDeparture (Client* sentClient, int time)
{


}