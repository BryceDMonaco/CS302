#include "Client.h"

Client::Client ()
{
	arrival = -1;
	transaction = -1;

}

Client::Client (int sentArr, int sentTrans)
{
	arrival = sentArr;
	transaction = sentTrans;

}

Client::~Client ()
{
	//Nothing needs to be destructed

}

int Client::GetArrival ()
{
	return arrival;

}

int Client::GetTransaction ()
{
	return transaction;

}

void Client::SetArrival (int sentVal)
{
	arrival = sentVal;

	return;

}

void Client::SetTransaction (int sentVal)
{
	transaction = sentVal;

	return;

}

void Client::Print ()
{
	cout << "[" << arrival << " - " << transaction << "]";

	return;

}

void Client::operator= (Client &sentClient)
{
	arrival = sentClient.GetArrival();
	transaction = sentClient.GetTransaction();

	return;

}
