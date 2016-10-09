#include <iostream>
#include <string>
#include "Stack.cpp"


using namespace std;

int main ()
{
	Stack<string> testStack;

	for (int i = 0; i < 14; i++)
	{
		string input;

		cout << "Type a string to push: ";
		cin >> input;

		if(testStack.push(input))
		{
			cout << "Current Stack Data: " << endl;

			testStack.print();

		} else
		{
			cout << "Push failed. i = " << i << endl;

		}

		

	}

	return 0;

}