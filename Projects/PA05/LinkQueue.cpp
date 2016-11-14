#include "LinkQueue.h"

LinkQueue::LinkQueue ()
{
	front = NULL;
	back = NULL;

}

LinkQueue::~LinkQueue ()
{
	Node* nodeTrav = front;

	while (nodeTrav != NULL)
	{
		Node* temp = (*nodeTrav).GetNext();

		delete nodeTrav;

		nodeTrav = temp;
		temp = NULL;

	}

	front = NULL;
	back = NULL;

}

bool LinkQueue::IsEmpty ()
{
	return (front == back && front == NULL);

}

bool LinkQueue::Enqueue (int entry)
{
	Node* newNode = new Node(entry, NULL);

	if (!IsEmpty()) //If the queue is non-empty
	{
		(*back).SetNext(newNode);

		back = newNode;

	} else //The queue is empty
	{
		front = newNode;
		back = newNode;

	}

	return true;

}

bool LinkQueue::Dequeue ()
{
	 if (!IsEmpty())
	 {
	 	Node* removeNode = front;

	 	if (front == back && front != NULL) //Queue has only one node
	 	{
	 		front = NULL;

	 		back = NULL;

	 	} else
	 	{
	 		front = (*front).GetNext();

	 	}

	 	delete removeNode;

	 	return true;

	 } else
	 {
	 	return false;

	 }
}

int LinkQueue::Peek ()
{
	if (!IsEmpty())
	{
		return (*front).GetValue();

	} else
	{
		return 9999999;

	}
}

void LinkQueue::Print ()
{
	cout << "Contents of link queue: " << endl;

	if (IsEmpty())
	{
		cout << "\t(EMPTY)";

	} else
	{
		cout << "\t";

		Node* nodeTrav = front;

		while (nodeTrav != NULL)
		{
			(*nodeTrav).Print();

			nodeTrav = (*nodeTrav).GetNext();

		}
	}

	cout << endl;

	return;

}