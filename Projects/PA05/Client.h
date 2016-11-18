/**
*	@file Client.h
*
*	@brief This is the header of the Client class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the Client class
*
*	@version 1.0
*
*	@note None.
*/

#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

using namespace std;

class Client
{
	public:
		Client ();
		Client (int sentArr, int sentTrans);
		~Client ();

		int GetArrival ();
		int GetTransaction ();

		void SetArrival (int sentVal);
		void SetTransaction (int sentVal);

		void Print ();

		void operator= (Client &sentClient);

	private:
		int arrival;
		int transaction;

};

#endif