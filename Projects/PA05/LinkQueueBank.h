/**
*	@file LinkQueueBank.h
*
*	@brief This is the header of the LinkQueueBank class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the LinkQueueBank class
*
*	@version 1.0
*
*	@note This is a version only meant for Client values.
*/

#include <iostream>
#include "NodeBank.h"

using namespace std;

class LinkQueueBank
{
	public:
		LinkQueueBank ();
		~LinkQueueBank ();

		bool IsEmpty ();
		bool Enqueue (int sentArr, int sentTrans);
		bool Dequeue ();
		int PeekArrival ();
		int PeekTransaction ();

		void Print ();

	private:
		NodeBank* front;
		NodeBank* back;

};