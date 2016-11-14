#include "NodeBank.h"

NodeBank::NodeBank ()
{
	arrival = 0;
	transaction = 0; 

	next = NULL;

}

NodeBank::NodeBank (int sentArr, int sentTran, NodeBank* nextNode)
{
	arrival = sentArr;
	transaction = sentTran;

	next = nextNode;

}

NodeBank::~NodeBank ()
{
	next = NULL;

}

int NodeBank::GetArrival ()
{
	return arrival;

}

int NodeBank::GetTransaction ()
{
	return transaction;

}

NodeBank* NodeBank::GetNext ()
{
	return next;

}

void NodeBank::SetArrival (int sentVal)
{
	arrival = sentVal;

	return;

}

void NodeBank::SetTransaction (int sentVal)
{
	transaction = sentVal;

	return;

}

void NodeBank::SetNext (NodeBank* nextPtr)
{
	next = nextPtr;

	return;

}

void NodeBank::Print ()
{
	cout << "[" << arrival << " - " << transaction << "]";

	return;

}