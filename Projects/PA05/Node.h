/**
*	@file Node.h
*
*	@brief This is the header of the Node class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the Node class
*
*	@version 1.0
*
*	@note This is a version only meant for integer values.
*/

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