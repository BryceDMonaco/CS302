/**
*	@file CountingSort.h
*
*	@brief This is the header of the CountingSort class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the CountingSort class
*
*	@version 1.0
*
*	@note None.
*/

#include <iostream>
#include <ctime>

using namespace std;

class CountingSort
{
	public:
		CountingSort ();
		CountingSort (int* data, int size, int max);
		~CountingSort ();

		int* DoSort ();	//Run a sort with the current data, returns NULL if no data or size
		int* DoSort (int* data, int size, int max); 
		void PrintFinal (int swapCount, int compCount);

		int GetSwaps ();
		int GetComps ();


	private:
		int size;
		int* data;
		int max;

		int lastSwap;
		int lastComp;

};