/**
*	@file ArrayQueueBank.h
*
*	@brief This is the header of the ArrayQueueBank class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the ArrayQueueBank class
*
*	@version 1.0
*
*	@note This is a version only meant for Client objects.
*/

#include <iostream>

#include "Client.h"

using namespace std;

class ArrayQueueBank
{
	public:
		ArrayQueueBank ();
		ArrayQueueBank (int sentCap);
		~ArrayQueueBank ();

		bool IsEmpty ();
		bool Enqueue (int sentArr, int sentTrans);
		bool Dequeue ();
		int PeekArrival ();
		int PeekTransaction ();
		Client* PeekFront ();


		void Print ();

	private:
		int front;
		int back;
		int count;
		int capacity;
		Client* data;

};