#include <iostream>

#include "Client.h"

using namespace std;

class ArrayQueueEvent
{
	public:
		ArrayQueueEvent ();
		ArrayQueueEvent (int sentCap);
		~ArrayQueueEvent ();

		bool IsEmpty ();
		bool Enqueue (int sentArr, int sentTrans);
		bool Dequeue ();
		int PeekArrival ();
		int PeekTransaction ();
		Event* PeekFront ();


		void Print ();

	private:
		int front;
		int back;
		int count;
		int capacity;
		Event* data;

};