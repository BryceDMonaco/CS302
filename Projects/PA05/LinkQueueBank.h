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