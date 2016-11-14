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
*	@note Modified version of PA04's CountingSort
*/

#include <iostream>
#include <ctime>

#include "Client.h"

using namespace std;

class CountingSort
{
	public:
		CountingSort ();
		CountingSort (Client* data, int size, int max);
		~CountingSort ();

		Client* DoSort ();	//Run a sort with the current data, returns NULL if no data or size
		Client* DoSort (Client* data, int size, int max); 

	private:
		int size;
		Client* data;
		int max;

};