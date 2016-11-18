/**
*	@file NodeBank.h
*
*	@brief This is the header of the NodeBank class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the NodeBank class
*
*	@version 1.0
*
*	@note This is essentially an early prototype of a Client
*/

#include <iostream>

using namespace std;

class NodeBank
{
	public:
		NodeBank ();
		NodeBank (int sentArr, int sentTran, NodeBank* nextNodeBank);
		~NodeBank ();

		int GetArrival ();
		int GetTransaction ();
		NodeBank* GetNext();
		
		void SetArrival (int sentVal);
		void SetTransaction (int sentVal);
		void SetNext (NodeBank* nextPtr);

		void Print ();

	private:
		int arrival;
		int transaction;

		NodeBank* next;
};