#include <iostream>

using namespace std;

class Node
{
	public:
		Node ();
		Node (int sentVal, Node* nextNode);
		~Node ();

		int GetValue ();
		Node* GetNext();
		
		void SetValue (int sentVal);
		void SetNext (Node* nextPtr);

		void Print ();

	private:
		int value;

		Node* next;
};