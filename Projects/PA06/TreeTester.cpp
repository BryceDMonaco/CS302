#include <iostream>

#include "BinarySearchTree.cpp"

#include <cstdlib>
#include <time.h>

using namespace std;

void GenerateUniqueValues (int* destination, int amount);
int GenerateUniqueOverlapValues (int* destination, int* mainData, int amountMain, int amountSecond, int overlaps);
void DoTraversals (BinarySearchTree<int>* sentTree);

int main ()
{
	BinarySearchTree<int> intTreeFirst;
	BinarySearchTree<int> intTreeSecond;

	int amount1 = 100;
	int amount2 = 10;
	int minimumOverlaps = 3;
	int* valuesFirst = new int[amount1];
	int* valuesSecond = new int[amount2];

	srand(time(0));

	cout << "Beginning generation process, THIS WILL TAKE A WHILE...." << endl;

	cout << "Generating unique values..." << endl;

	GenerateUniqueValues(valuesFirst, amount1);

	cout << "Generating overlap values... Generated ";

	cout << GenerateUniqueOverlapValues(valuesSecond, valuesFirst, amount1, amount2, minimumOverlaps);

	cout << " overlaps." << endl << "Generation complete." << endl;

	cout << "Adding to the first tree: " << endl;

	for (int ii = 0; ii < amount1; ii++)
	{
		intTreeFirst.Add(*(valuesFirst + ii));

		cout << "\tAdding " << *(valuesFirst + ii) << endl;

	}

	cout << "Adding to the second tree: " << endl;

	for (int ii = 0; ii < amount2; ii++)
	{
		intTreeSecond.Add(*(valuesSecond + ii));

		cout << "\tAdding " << *(valuesSecond + ii) << endl;

	}

	cout << "Traversals for the main tree: " << endl;
	DoTraversals(&intTreeFirst);
	cout << "Traversals for the overlap tree: " << endl;
	DoTraversals(&intTreeSecond);

	delete[] valuesFirst;
	delete[] valuesSecond;

	return 0;

}

void GenerateUniqueValues (int* destination, int amount)
{
	bool* occurs = new bool[amount];

	for (int i = 0; i < amount; i++)
	{
		*(occurs + i) = false;

	}

	for (int i = 0; i < amount; i++)
	{
		bool unique = false;

		while (!unique)
		{
			int tempVal = rand() % 200;

			//cout << "tempVal = " << tempVal << endl;

			if (*(occurs + tempVal) == true) //The value has already been generated
			{
				unique = false;

				//cout << tempVal << " occurs. Regenerating." << endl;

			} else
			{
				//cout << "The value will be stored..." << endl;

				*(occurs + tempVal) = true;

				//cout << "Storing at destination index " << i << endl;

				*(destination + i) = tempVal;

				unique = true;

				//cout << "Stored " << *(destination + i) << endl;

			}

		}
	}

	return;

}

int GenerateUniqueOverlapValues (int* destination, int* mainData, int amountMain, int amountSecond, int overlaps)
{
	int overlapCount = 0;

	while (overlapCount < overlaps)
	{
		//cout << "Attempting new overlap run..." << endl;
		GenerateUniqueValues(destination, amountSecond); //Get a new set of numbers

		overlapCount = 0;

		for (int i = 0; i < amountSecond; i++)
		{
			int currentValue = *(destination + i);

			for (int ii = 0; ii < amountMain; ii++)
			{
				if (currentValue == *(mainData + ii))
				{
					overlapCount++;

					break;

				}
			}
		}

	}

	return overlapCount;

}

void DoTraversals (BinarySearchTree<int>* sentTree)
{
	cout << "Doing Preorder Traversal..." << endl;

	(*sentTree).DoTraversal(0);

	cout << endl << "Preorder Traversal done." << endl;

	cout << "Doing Inorder Traversal..." << endl;

	(*sentTree).DoTraversal(1);

	cout << endl << "Inorder Traversal done." << endl;

	cout << "Doing Postorder Traversal..." << endl;

	(*sentTree).DoTraversal(2);

	cout << endl << "Postorder Traversal done." << endl;

	cout << "Tree height: " << (*sentTree).GetHeight() << endl;

	return;

}