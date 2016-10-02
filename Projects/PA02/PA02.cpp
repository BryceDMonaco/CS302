//  Created by Shehryar Khattak for CS302 Spring 2016 class.
//	Updated and modified by Bryce Monaco, CS302 Fall 2016

#include <iostream>
#include <fstream>

using namespace std;

void ReadInData (ifstream *sentFile);

int main (int argc, char *argv[])
{

	//Declerations (insert as needed)
	int kSmall_pos;			//For User Input
	int kSmall_val = 0;		//Populate using your algorithm implementation
	int pivot;		        //Pivot position in array

	int *values = new int[1];

	//User Input DO NOT MODIFY
	cout << "(A data file not named \"data2.txt\" can be opened as a command-line argument)" << endl;
	cout << "Please enter required kth smallest value:";
	cin >> kSmall_pos;

	
	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.
	ifstream dataFile;

	if (argc > 1)
	{
		cout << "Argument: " << argv[1] << endl;

		dataFile.open(argv[1]);

		ReadInData(&dataFile, values);

	} else
	{
		dataFile.open("data2.txt");

		ReadInData(&dataFile, values);

	}


	//kmsall algorithm implementation or function call (insert) - implement using recursion as indicated



	//Log file output (insert) - preferred in .txt format acoording to instructions posted on assignment page



	//Output DO NOT MODIFY
	cout<< "kth smallest value = " << kSmall_val << endl;

	return 0;
}

void ReadInData (ifstream *sentFile, int *arrayStart)
{



	(*sentFile).close();

	return;

}

