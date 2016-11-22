#include <iostream>

#include "BinarySearchTree.cpp"

#include <cstdlib>
#include <time.h>

using namespace std;

int main ()
{
	BinarySearchTree<int> intTree;

	int* values = new int[11];

	int* valueTrav = values;

	srand(time(0));

	for (int ii = 0; ii < 11; ii++)
	{
		*(valueTrav + ii) = rand() % 100;

	}

	for (int ii = 0; ii < 11; ii++)
	{
		intTree.Add(*(valueTrav + ii));

		cout << "Adding " << *(valueTrav + ii) << endl;

	}

	valueTrav = NULL;

	intTree.Print();

	delete[] values;

	return 0;

}