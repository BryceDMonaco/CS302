/*
#include <string>
#include <fstream>

class CityDataInput
{
	public:
		string getName ();
		void getNamePair (); //The book wants it to return a pair, instead I'm having it modify the two pointers
		int GetDataAmount (ifstream *sentFile);


};
*/

#include "CityDataInput.h"

using namespace std;

int CityDataInput::GetDataAmount (ifstream *sentFile)
