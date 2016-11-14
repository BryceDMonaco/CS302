#include "ArrayQueue.h"

ArrayQueue::ArrayQueue ()
{
	front = 0;
	capacity = 10;
	back = capacity - 1;
	count = 0;
	data = new int[capacity];

}

ArrayQueue::ArrayQueue (int sentCap)
{
	front = 0;
	capacity = sentCap;
	back = capacity - 1;
	count = 0;
	data = new int[capacity];

}

ArrayQueue::~ArrayQueue ()
{
	delete[] data;
	data = NULL;

}

bool ArrayQueue::IsEmpty ()
{
	if (count == 0)
	{
		return true;

	} else
	{
		return false;

	}
}

bool ArrayQueue::Enqueue (int entry)
{
	if (count < capacity)
	{
		back = (back + 1) % capacity;

		int* dataTrav = data;

		*(data + back) = entry;

		count++;

		dataTrav = NULL;

		return true;

	} else
	{
		return false;

	}
}

bool ArrayQueue::Dequeue ()
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

int ArrayQueue::Peek ()
{
	if (!IsEmpty())
	{
		int* dataTrav = data;

		return *(dataTrav + front);

	} else
	{
		return 9999999;

	}
}

void ArrayQueue::Print ()
{
	cout << "Contents of queue:" << endl << "\tFront: " << front << endl << "\tBack: " << back << endl << "\t";

	int* dataTrav = data;

	if (IsEmpty())
	{
		cout << "(EMPTY)";

	}else if (front > back)
	{
		for (int i = 0; i < capacity; i++)
		{
			cout << "[" << *(data + i) << "]";

		}

	} else
	{
		for (int i = front; i <= back; i++)
		{
			cout << "[" << *(data + i) << "]";

		}
	}

	cout << endl;

	return;

}