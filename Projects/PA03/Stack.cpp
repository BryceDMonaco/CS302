/*
	This is a modified Stack class. It is based off of a Stack class that
	I had written for an assignment in CS202 during Spring 2016 (Project 8). It is missing
	a few functions which I deemed nonessential for this project.
*/


#include <iostream>

using namespace std;

template<class itemType>
class Stack {
	public:
		Stack(int size = 10); //size is the size of the stack, cannot be changed
		Stack(const Stack<itemType>&);
		~Stack();

		bool push(itemType); //Inserts
		itemType pop(); //Removes
		bool isEmpty() const; //Checks if empty
		bool isFull() const; //Checks if full
		bool clear(); //clears data

		void print();

	private:
		int max; //The max amount of values in the stack
		int top; //The position of the current top value in the array
		itemType* data;

};

/////////////////////////////////////////////////////////////////////////////////
///////////// 					End Header File 					/////////////
/////////////////////////////////////////////////////////////////////////////////

//Default Constructor
template<class itemType>
Stack<itemType>::Stack (int size)
{
	max = size;
	top = -1;

	data = new itemType[max];

}

//Copy Constructor
template<class itemType>
Stack<itemType>::Stack (const Stack<itemType>& sentStack)
{
	max = sentStack.max;
	top = sentStack.top;
	
	data = new itemType[max];
	
	itemType *dataTrav = data;
	itemType *sentTrav = sentStack.data;
	
	for (int i = 0; i < max; i++)
	{
		*dataTrav = *sentTrav;
		
		dataTrav++;
		sentTrav++;
	
	}
	
	dataTrav = NULL;
	sentTrav = NULL;

}

//Destructor
template<class itemType>
Stack<itemType>::~Stack() 
{
	delete[] data;
	data = NULL;

}

//Functions
template<class itemType>
bool Stack<itemType>::push (itemType value)
{
	if (top + 1 == max) //If true the stack is full
	{
		return false;

	} else if (top + 1 < max)
	{
		itemType* dataTrav = data;

		for (int i = 0; i <= top; i++)
		{
			dataTrav++;

		}

		*dataTrav = value;

		top++;

		dataTrav = NULL;

		return true;

	}
}

template<class itemType>
itemType Stack<itemType>::pop ()
{
	if (top != -1) //If false stack is empty
	{
		itemType* dataTrav = data;

		for (int i = 0; i < top; i++)
		{
			dataTrav++;

		}

		top--;

		return *dataTrav;

	}
}

template<class itemType>
bool Stack<itemType>::isEmpty () const
{
	if (top == -1)
	{
		return true;

	} else
	{
		return false;

	}
}

template<class itemType>
bool Stack<itemType>::isFull () const
{
	if (top + 1 == max)
	{
		return true;

	} else
	{
		return false;

	}
}

template<class itemType>
bool Stack<itemType>::clear ()
{
	delete[] data;
	data = NULL;

	data = new itemType[max];

	return true;

}

template<class itemType>
void Stack<itemType>::print ()
{
	cout << "Max: " << max << "\t\tTop: " << top << endl;

	cout <<"Contents: {";

	if (top != -1)
	{
		itemType* dataTrav = data;

		for (int i = 0; i < top + 1; i++)
		{
			if (i == top)
			{
				cout << *dataTrav;

			} else
			{
				cout << *dataTrav << ", ";

			}

			dataTrav++;

		}

		dataTrav = NULL;

	} else
	{
		cout << "EMPTY";

	}

	cout << "}" << endl;

	return;

}

