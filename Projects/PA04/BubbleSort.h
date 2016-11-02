/**
*	@file BubbleSort.h
*
*	@brief This is the header of the BubbleSort class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the BubbleSort class
*
*	@version 1.0
*
*	@note None.
*/

#include <iostream>
#include <ctime>

using namespace std;

class BubbleSort
{
	public:
		BubbleSort ();
		BubbleSort (int* data, int size);
		~BubbleSort ();

		int* DoSort ();	//Run a sort with the current data, returns NULL if no data or size
		int* DoSort (int* data, int size); 
		void Swap (int* firstVal, int* secondVal);
		void PrintFinal (int swapCount, int compCount);

		int GetSwaps ();
		int GetComps ();


	private:
		int size;
		int* data;

		int lastSwap;
		int lastComp;

};