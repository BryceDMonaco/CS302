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