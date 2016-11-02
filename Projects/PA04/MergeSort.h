/**
*	@file MergeSort.h
*
*	@brief This is the header of the MergeSort class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the MergeSort class
*
*	@version 1.0
*
*	@note None.
*/

#include <iostream>
#include <ctime>

using namespace std;

class MergeSort
{
	public:
		MergeSort ();
		MergeSort (int* data, int size);
		~MergeSort ();

		void DoSort (int first, int last);
		int* DoSort (int first, int mid, int last);	//Run a sort with the current data, returns NULL if no data or size
		void DoSort (int* data, int size); 
		void Swap (int* firstVal, int* secondVal);
		void PrintFinal ();

		void ResetCounts ();

		int GetSwaps ();
		int GetComps ();


	private:
		int size;
		int* data;

		int lastComparisonCount;
		int lastSwapCount;

};