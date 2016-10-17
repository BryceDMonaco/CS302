#include <string>
#include <fstream>

using namespace std;

class CityDataInput
{
	public:
		string getName ();
		void getNamePair (); //The book wants it to return a pair, instead I'm having it modify the two pointers
		int GetDataAmount (ifstream *sentFile);

};