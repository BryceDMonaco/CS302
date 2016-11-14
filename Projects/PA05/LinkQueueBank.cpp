#include "LinkQueueBank.h"

LinkQueueBank::LinkQueueBank ()
{
	front = NULL;
	back = NULL;

}

LinkQueueBank::~LinkQueueBank ()
{
	NodeBank* nodeTrav = front;

	while (nodeTrav != NULL)
	{
		NodeBank* temp = (*nodeTrav).GetNext();

		delete nodeTrav;

		nodeTrav = temp;
		temp = NULL;

	}

	front = NULL;
	back = NULL;

}

bool LinkQueueBank::IsEmpty ()
{
	return (front == back && front == NULL);

}

bool LinkQueueBank::Enqueue (int sentArr, int sentTrans)
{
	NodeBank* newNodeBank = new NodeBank(sentArr, sentTrans, NULL);

	if (!IsEmpty()) //If the queue is non-empty
	{
		(*back).SetNext(newNodeBank);

		back = newNodeBank;

	} else //The queue is empty
	{
		front = newNodeBank;
		back = newNodeBank;

	}

	return true;

}

bool LinkQueueBank::Dequeue ()
{
	 if (!IsEmpty())
	 {
	 	NodeBank* removeNodeBank = front;

	 	if (front == back && front != NULL) //Queue has only one node
	 	{
	 		front = NULL;

	 		back = NULL;

	 	} else
	 	{
	 		front = (*front).GetNext();

	 	}

	 	delete removeNodeBank;

	 	return true;

	 } else
	 {
	 	return false;

	 }
}

int LinkQueueBank::PeekArrival ()
{
	if (!IsEmpty())
	{
		return (*front).GetArrival();

	} else
	{
		return -1;

	}
}

int LinkQueueBank::PeekTransaction ()
{
	if (!IsEmpty())
	{
		return (*front).GetTransaction();

	} else
	{
		return -1;

	}
}

void LinkQueueBank::Print ()
{
	cout << "Contents of link queue: " << endl;

	if (IsEmpty())
	{
		cout << "\t(EMPTY)";

	} else
	{
		cout << "\t";

		NodeBank* nodeTrav = front;

		while (nodeTrav != NULL)
		{
			(*nodeTrav).Print();

			nodeTrav = (*nodeTrav).GetNext();

		}
	}

	cout << endl;

	return;

}