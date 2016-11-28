/**
*	@file PA06.cpp
*
*	@brief This is the main file to run the trees.
*
*	@author Bryce Monaco
*
*	@details This file runs the trees and performs the required operations.
*
*	@version 1.0
*
*	@note None.
*/

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

	cout << "Beginning generation process, THIS COULD TAKE A WHILE...." << endl;

	cout << "\tGenerating unique values..." << endl;

	GenerateUniqueValues(valuesFirst, amount1);

	cout << "\tGenerating overlap values... Generated ";

	cout << GenerateUniqueOverlapValues(valuesSecond, valuesFirst, amount1, amount2, minimumOverlaps);

	cout << " overlaps." << endl << "Generation complete." << endl;

	//cout << endl << "Adding to the first tree: " << endl;

	for (int ii = 0; ii < amount1; ii++)
	{
		intTreeFirst.Add(*(valuesFirst + ii));

		//cout << "\tAdding " << *(valuesFirst + ii) << endl;

	}

	//cout << endl << "Adding to the second tree: " << endl;

	for (int ii = 0; ii < amount2; ii++)
	{
		intTreeSecond.Add(*(valuesSecond + ii));

		//cout << "\tAdding " << *(valuesSecond + ii) << endl;

	}

	cout << endl << "Inorder traversal for the main tree: " << endl;
	intTreeFirst.DoTraversal(1);
	cout << endl << endl << "Tree height: " << intTreeFirst.GetHeight();

	cout << endl << endl << "Traversals for the overlap tree: " << endl;
	DoTraversals(&intTreeSecond);

	cout << endl << "Removing overlap values from the main tree..." << endl;

	for (int i = 0; i < amount2; i++)
	{
		if (intTreeFirst.Remove(*(valuesSecond + i)))
		{
			cout << "\tRemoved " << *(valuesSecond + i) << endl;

		}
	}

	cout << endl << "Inorder traversal for the main tree: " << endl;
	intTreeFirst.DoTraversal(1);
	cout << endl << endl << "Tree height: " << intTreeFirst.GetHeight();
	cout << endl << "Number of nodes in main tree: " << intTreeFirst.GetNodeCount() << endl;

	cout << endl << "Clearing Trees..." << endl;

	cout << "Before calling Clear(), the main tree is ";

	if (intTreeFirst.IsEmpty())
	{
		cout << "EMPTY." << endl;

	} else
	{
		cout << "NOT EMPTY." << endl;

	}

	cout << "Before calling Clear(), the secondary tree is ";

	if (intTreeSecond.IsEmpty())
	{
		cout << "EMPTY." << endl;

	} else
	{
		cout << "NOT EMPTY." << endl;

	}

	intTreeFirst.Clear();
	intTreeSecond.Clear();

	cout << "After calling Clear(), the main tree is ";

	if (intTreeFirst.IsEmpty())
	{
		cout << "EMPTY." << endl;

	} else
	{
		cout << "NOT EMPTY." << endl;

	}

	cout << "After calling Clear(), the secondary tree is ";

	if (intTreeSecond.IsEmpty())
	{
		cout << "EMPTY." << endl;

	} else
	{
		cout << "NOT EMPTY." << endl;

	}


	delete[] valuesFirst;
	delete[] valuesSecond;

	return 0;

}

/**
*	@brief Fills an array with unique values
*
*	@details Fills an array with unique random values.
*
*	@par Algorithm Checks if the value has already been generated and then stores it or regenerates it.
*
*	@param[in] destination The integer array to store the data in
*
*	@param[in] amount The number of values to generate, must be the size of the array
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
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

/**
*	@brief Fills an array with unique values with some overlap of another array
*
*	@details Fills an array with unique random values with at least a certain amount of overlaps
*
*	@par Algorithm Checks if there are a certain amount of overlapping values, if there are it stores, if not it regenerates
*
*	@param[in] destination The integer array to store the data in
*
*	@param[in] mainData The integer array of the main data to check for overlaps
*
*	@param[in] amountMain The size of the main array
*
*	@param[in] amountSecond The size of the overlap array and the number of values to generate
*
*	@param[in] overlaps The minimum number of overlapping values to generate
*
*	@param[out] None.
*
*	@return Returns the number of overlaps generated, will be greater than or equal to the sent overlaps value
*
*	@note None.
*
*/
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

/**
*	@brief Does all three traversals with the sent tree
*
*	@details Does all three traversals wit hthe sent tree and formats the output
*
*	@par Algorithm None.
*
*	@param[in] sentTree The tree to do the traversals on.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
void DoTraversals (BinarySearchTree<int>* sentTree)
{
	cout << "Preorder Traversal: " << endl;

	(*sentTree).DoTraversal(0);

	cout << endl << endl;

	cout << "Inorder Traversal" << endl;

	(*sentTree).DoTraversal(1);

	cout << endl << endl;

	cout << "Postorder Traversal" << endl;

	(*sentTree).DoTraversal(2);

	cout << endl << endl;

	cout << "Tree height: " << (*sentTree).GetHeight() << endl;

	return;

}