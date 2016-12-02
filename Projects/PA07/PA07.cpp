/**
*	@file PA07.cpp
*
*	@brief This is the main file to run the tree.
*
*	@author Bryce Monaco
*
*	@details This file runs the tree and performs the required operations.
*
*	@version 1.0
*
*	@note GenerateUniqueValues() is adapted from PA06
*/

#include <iostream>

#include <cstdlib>
#include <time.h>

using namespace std;

void GenerateUniqueValues (int* destination, int amount);

int main ()
{
	int* values = new int[1000];

	srand(time(0));

	GenerateUniqueValues(values, 1000);

	int sum = 0;

	for (int i = 0; i < 1000; i++)
	{
		sum += *(values + i);

	}

	cout << "Sum of 1000 unique values: " << sum << endl;

	delete[] values;

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
*	@note Adapted from code written for PA06 in PA06.cpp
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
			int tempVal = rand() % 10000;

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

	//delete[] occurs; //Causes an occasional crash for some reason
	//occurs = NULL;

	return;

}