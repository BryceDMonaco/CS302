#include "Simulation1A.h"

Simulation1A::Simulation1A ()
{
	clients = NULL;
	clientCount = 99999;
	tellerAvailable = true;

	bankQueue = ArrayQueueBank(clientCount);
	clientQueue = ArrayQueueBank(clientCount);

}

Simulation1A::Simulation1A (Client* sentClients, int count)
{
	clients = sentClients;
	clientCount = count;
	tellerAvailable = true;

	bankQueue = ArrayQueueBank(clientCount);
	clientQueue = ArrayQueueBank(clientCount);

}

Simulation1A::~Simulation1A ()
{
	clients = NULL;

}

void Simulation1A::SendClients (Client* sentClients, int count)
{
	clients = sentClients;

	clientCount = count;

	return;

}

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

void Simulation1A::Simulate ()
{
	ResetSimulation(); //Make sure the queue is empty

	//Enter all of the clients into the client queue
	for (int i = 0; i < clientCount; i++)
	{
		clientQueue.Enqueue(*clients + i);

	}

}

void Simulation1A::ProcessArrival (Client* sentClient, int time)
{
	Client* frontClient = sentClient;

	clientQueue.Dequeue(); //Remove client from the client queue

	bankQueue.Enqueue(frontClient);


}

void Simulation1A::ProcessDeparture (Client* sentClient, int time)
{


}