#include "ArrayQueueBank.h"

ArrayQueueBank::ArrayQueueBank ()
{
	front = 0;
	capacity = 10;
	back = capacity - 1;
	count = 0;
	data = new Client[capacity];

}

ArrayQueueBank::ArrayQueueBank (int sentCap)
{
	front = 0;
	capacity = sentCap;
	back = capacity - 1;
	count = 0;
	data = new Client[capacity];

}

ArrayQueueBank::~ArrayQueueBank ()
{
	delete[] data;
	data = NULL;

}

bool ArrayQueueBank::IsEmpty ()
{
	if (count == 0)
	{
		return true;

	} else
	{
		return false;

	}
}

bool ArrayQueueBank::Enqueue (int sentArr, int sentTrans)
{
	if (count < capacity)
	{
		back = (back + 1) % capacity;

		Client* dataTrav = data;

		(*(data + back)).SetArrival(sentArr);
		(*(data + back)).SetTransaction(sentTrans);

		count++;

		dataTrav = NULL;

		return true;

	} else
	{
		return false;

	}
}

bool ArrayQueueBank::Dequeue ()
{
	if (!IsEmpty())
	{
		front = (front + 1) % capacity;

		count--;

		return true;

	} else
	{
		return false;

	}
}

int ArrayQueueBank::PeekArrival ()
{
	if (!IsEmpty())
	{
		Client* dataTrav = data;

		return (*(dataTrav + front)).GetArrival();

	} else
	{
		return -1;

	}
}

int ArrayQueueBank::PeekTransaction ()
{
	if (!IsEmpty())
	{
		Client* dataTrav = data;

		return (*(dataTrav + front)).GetTransaction();

	} else
	{
		return -1;

	}
}

void ArrayQueueBank::Print ()
{
	cout << "Contents of queue:" << endl << "\tFront: " << front << endl << "\tBack: " << back << endl << "\t";

	Client* dataTrav = data;

	if (IsEmpty())
	{
		cout << "(EMPTY)";

	}else if (front > back)
	{
		for (int i = 0; i < capacity; i++)
		{
			(*(dataTrav + i)).Print();

		}

	} else
	{
		for (int i = front; i <= back; i++)
		{
			(*(dataTrav + i)).Print();

		}
	}

	cout << endl;

	return;

}