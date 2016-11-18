/**
*	@file ArrayQueue.h
*
*	@brief This is the header of the ArrayQueue class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the ArrayQueue class
*
*	@version 1.0
*
*	@note This is a version only meant for integer values.
*/

#include <iostream>

using namespace std;

class ArrayQueue
{
	public:
		ArrayQueue ();
		ArrayQueue (int sentCap);
		~ArrayQueue ();

		bool IsEmpty ();
		bool Enqueue (int entry);
		bool Dequeue ();
		int Peek ();

		void Print ();

	private:
		int front;
		int back;
		int count;
		int capacity;
		int* data;

};