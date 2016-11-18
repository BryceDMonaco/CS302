/**
*	@file Client.cpp
*
*	@brief This is the implementation of the Client class
*
*	@author Bryce Monaco
*
*	@details This file contains the implementation of the Client class
*
*	@version 1.0
*
*	@note None.
*/

#include "Client.h"

/**
*	@brief The default constructor of a Client object
*
*	@details This constructor initializes values of a Client object to default values
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
Client::Client ()
{
	arrival = -1;
	transaction = -1;

}

/**
*	@brief The default constructor of a Client object
*
*	@details This constructor initializes values of a Client object to sent values
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
Client::Client (int sentArr, int sentTrans)
{
	arrival = sentArr;
	transaction = sentTrans;

}

/**
*	@brief The destructor of a Client object
*
*	@details Safely removes a Client object from memory
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
Client::~Client ()
{
	//Nothing needs to be destructed

}

/**
*	@brief Gets the arrival time of this Client
*
*	@details Returns the arrival value of this Client object
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the integer value of the arrival time of this Client.
*
*	@note None.
*
*/
int Client::GetArrival ()
{
	return arrival;

}

/**
*	@brief Gets the transaction time of this Client
*
*	@details Returns the transaction value of this Client object
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the integer value of the transaction time of this Client.
*
*	@note None.
*
*/
int Client::GetTransaction ()
{
	return transaction;

}

/**
*	@brief Sets the arrival time of this Client
*
*	@details Modifies the arrival value of this Client object
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
void Client::SetArrival (int sentVal)
{
	arrival = sentVal;

	return;

}

/**
*	@brief Sets the transaction time of this Client
*
*	@details Modifies the transaction value of this Client object
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
void Client::SetTransaction (int sentVal)
{
	transaction = sentVal;

	return;

}

/**
*	@brief Prints the values of this Client
*
*	@details Prints the arrival and transaction times of the client in the formal "[ARRIVALTIME - TRANSTIME]"
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
void Client::Print ()
{
	cout << "[" << arrival << " - " << transaction << "]";

	return;

}

/**
*	@brief The assignment operator for a Client
*
*	@details Overloads the assignment operator for a Client object
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
void Client::operator= (Client &sentClient)
{
	arrival = sentClient.GetArrival();
	transaction = sentClient.GetTransaction();

	return;

}
