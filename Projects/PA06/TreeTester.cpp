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

	intTree.Print();

	cout << "Attempting to remove " << *(values + 3) << endl;

	if (intTree.Remove(*(values + 3)))
	{
		//Should be successful
		cout << "Value was removed." << endl;

	} else
	{
		cout << "Removal failed." << endl;

	}

	cout << "After first removal tree is now: " << endl;
	intTree.Print();

	cout << "Attempting to remove 3 (static value)" << endl;

	if (intTree.Remove(3))
	{
		//Should be successful
		cout << "Value was removed." << endl;

	} else
	{
		cout << "Removal failed." << endl;

	}

	cout << "After second removal tree is now: " << endl;
	intTree.Print();

	delete[] values;

	return 0;

}