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


	private:
		int size;
		int* data;

		int lastComparisonCount;
		int lastSwapCount;

};