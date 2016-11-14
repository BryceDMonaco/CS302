#include <iostream>

using namespace std;

class NodeBank
{
	public:
		NodeBank ();
		NodeBank (int sentArr, int sentTran, NodeBank* nextNodeBank);
		~NodeBank ();

		int GetArrival ();
		int GetTransaction ();
		NodeBank* GetNext();
		
		void SetArrival (int sentVal);
		void SetTransaction (int sentVal);
		void SetNext (NodeBank* nextPtr);

		void Print ();

	private:
		int arrival;
		int transaction;

		NodeBank* next;
};