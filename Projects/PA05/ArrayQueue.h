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