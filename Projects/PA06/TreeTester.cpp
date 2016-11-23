#include <iostream>

#include "BinarySearchTree.cpp"

#include <cstdlib>
#include <time.h>

using namespace std;

void GenerateUniqueValues (int* destination, int amount);

int main ()
{
	BinarySearchTree<int> intTree;

	int* values = new int[11];

	GenerateUniqueValues(values, 11);

	for (int ii = 0; ii < 11; ii++)
	{
		intTree.Add(*(values + ii));

		cout << "Adding " << *(values + ii) << endl;

	}

	intTree.Print();
	cout << "Number of nodes: " << intTree.GetNodeCount() << endl;

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
	cout << "Number of nodes: " << intTree.GetNodeCount() << endl;

	delete[] values;

	return 0;

}

void GenerateUniqueValues (int* destination, int amount)
{
	srand(time(0));

	bool unique = false;

	while (!unique)
	{
		for (int i = 0; i < amount; i++)
		{
			*(destination + i) = rand() % 100;

		}

		unique = true;

		for (int i = 0; i < amount; i++)
		{
			int currentValue = *(destination + i);
			int occurance = 0;

			for (int ii = 0; ii < amount; ii++)
			{
				if (*(destination + ii) == currentValue)
				{
					occurance++;

				}
			}

			if (occurance > 1)
			{
				unique = false; //Regenerate
				break;

			}
		}

	}

	return;

}