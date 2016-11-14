#include "Node.h"

Node::Node ()
{
	int value = 0;

	next = NULL;

}

Node::Node (int sentVal, Node* nextNode)
{
	value = sentVal;

	next = nextNode;

}

Node::~Node ()
{
	next = NULL;

}

int Node::GetValue ()
{
	return value;

}

Node* Node::GetNext ()
{
	return next;

}

void Node::SetValue (int sentVal)
{
	value = sentVal;

	return;

}

void Node::SetNext (Node* nextPtr)
{
	next = nextPtr;

	return;

}

void Node::Print ()
{
	cout << "[" << value << "]";

	return;

}