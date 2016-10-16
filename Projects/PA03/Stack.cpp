/**
*	@file Stack.cpp
*
*	@brief This file contains both the header and the implementation for the Stack class used in PA03.
*
*	@author Bryce Monaco (Originally for CS202)
*
*	@details This file contains the code for the Stack class used in PA03. This is a modified Stack class. It is based off of a Stack class that I had written for an assignment in CS202 during Spring 2016 (Project 8). It is missing a few functions which I deemed nonessential for this project.
*
*	@version 1.0
*
*	@note This code was put into one file instead of a .h and .cpp because of issues with templating. The header section of this code is the only part taken from the 202 code, I set it up to be templated (originally it only worked with chars) and completely rewrote the implementation.
*/

#include <iostream>

using namespace std;

template<class itemType>
class Stack 
{
	public:
		Stack(int size = 10); //size is the size of the stack, cannot be changed after initialization
		Stack(const Stack<itemType>&);
		~Stack();

		bool push(itemType); //Inserts
		itemType pop(); //Removes
		bool isEmpty() const; //Checks if empty
		bool isFull() const; //Checks if full
		bool clear(); //clears data
		itemType peek();

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

/**
*	@brief This function pushes a value onto the stack if there is room
*
*	@details This function pushes a value on the stack if there is room for the value

*	@par Algorithm If there is room, the traverser pointer is moved to the top of the stack and the value is inserted
*
*	@param[in] value The value to be inserted, must be the same type as the stack (i.e. a string can't be pushed into an int stack)
*
*	@param[out] None.
*
*	@return Returns true if a value was able to be pushed, returns false if the stack was full
*
*	@note None.
*
*/
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

/**
*	@brief This function is used to remove the value at the top of the stack.
*
*	@details This function removes the value from the top of the stack (if there is one) and returns it.
*
*	@par Algorithm Moves the pointer dataTrav to the top of the stack, removes it, and returns it.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the value that was at the top of the stack. NULL if the stack is empty.
*
*	@note None.
*
*/
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

	} else
	{
		return NULL;

	}
}

/**
*	@brief This function checks if the stack has any values stored.
*
*	@details This function checks the value of top, which should be >=0 if there is any data inside.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns true if the stack is empty, false otherwise.
*
*	@note None.
*
*/
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

/**
*	@brief This function checks if the stack is full
*
*	@details This function checks the value of top, which should be equal to max - 1 if it is full
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns true if the stack is full, false otherwise.
*
*	@note None.
*
*/
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

/**
*	@brief This function deletes the data stored in the stack
*
*	@details This function deletes the data stored in the stack, and allocates a new set of memory to make a clean stack
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Should always return true.
*
*	@note Originally the function should return false if the stack is already empty, this behaviour was removed and it just wipes the stack no matter what
*
*/
template<class itemType>
bool Stack<itemType>::clear ()
{
	delete[] data;
	data = NULL;

	data = new itemType[max];

	top = -1;

	return true;

}

/**
*	@brief This function returns the value at the top of the stack
*
*	@details This function goes to the top of the stack and returns the value
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the value at top if there is one
*
*	@note None.
*
*/
template<class itemType>
itemType Stack<itemType>::peek ()
{
	if (top == -1)
	{
		return NULL;

	} else
	{
		itemType *dataTrav = data;

		for (int i = 0; i < top; i++)
		{
			dataTrav++;

		}

		return *dataTrav;

	}

}

/**
*	@brief This function prints all values stored in the stack
*
*	@details This function runs through the stack and prints all values inside. Top is marked.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] Outputs the contents of the stack to the console
*
*	@return None.
*
*	@note None.
*
*/
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
				cout << *dataTrav << " (TOP)";

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

