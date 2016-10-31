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


	private:
		int size;
		int* data;
		int max;

};