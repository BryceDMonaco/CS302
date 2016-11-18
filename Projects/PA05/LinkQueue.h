/**
*	@file LinkQueue.h
*
*	@brief This is the header of the LinkQueue class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the LinkQueue class
*
*	@version 1.0
*
*	@note This is a version only meant for integer values.
*/

#include <iostream>
#include "Node.h"
#include <memory>

using namespace std;

class LinkQueue
{
	public:
		LinkQueue ();
		~LinkQueue ();

		bool IsEmpty ();
		bool Enqueue (int entry);
		bool Dequeue ();
		int Peek ();

		void Print ();

	private:
		Node* front;
		Node* back;

};