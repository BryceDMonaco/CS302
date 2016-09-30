//  Created by Shehryar Khattak for CS302 Spring 2016 class.
//	Updated and modified by Bryce Monaco, CS302 Fall 2016

#include <iostream>
#include <fstream>

using namespace std;

void ReadInData (int *data);
void ReadInData	(int *data, char *fileName); //Used if a file name is passed in as a command-line argument


int main (int argc, char *argv[])
{

	//Declerations (insert as needed)
	int kSmall_pos;			//For User Input
	int kSmall_val = 0;		//Populate using your algorithm implementation
	int pivot;		        //Pivot position in array

	int *values;

	//User Input DO NOT MODIFY
	cout << "Please enter required kth smallest value:";
	cin >> kSmall_pos;

	
	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.
	if (argc > 1)
	{
		cout << "Argument: " << argv[1] << endl;

		ReadInData (values, argv[1]);

	} else
	{
		ReadInData (values);

	}


	//kmsall algorithm implementation or function call (insert) - implement using recursion as indicated



	//Log file output (insert) - preferred in .txt format acoording to instructions posted on assignment page



	//Output DO NOT MODIFY
	cout<< "kth smallest value = " << kSmall_val << endl;

	return 0;
}

void ReadInData (int *data)
{



}

void ReadInData	(int *data, char *fileName)
{
	cout << fileName << endl;

	return;

}
