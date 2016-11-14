#include <iostream>

#include "ArrayQueue.h"
#include "LinkQueue.h"

using namespace std;

int main ()
{
	ArrayQueue tester;

	tester.Print();

	for (int i = 0; i < 10; i++)
	{
		tester.Enqueue(i + 3);

	}

	tester.Print();

	for (int i = 0; i < 3; i++)
	{
		tester.Dequeue();

	}

	tester.Print();

	for (int i = 0; i < 5; i++)
	{
		tester.Enqueue(i + 19);

	}

	tester.Print();

	return 0;

}