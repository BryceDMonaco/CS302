#include <iostream>
#include <vector>

#include "Vertex.cpp"

using namespace std;

template <class itemType>
class GraphMatrix
{
	public:
		GraphMatrix ();
		GraphMatrix (vector<Vertex*> sentVerts, bool sentBool);
		~GraphMatrix ();

		bool SendVertices (vector<Vertex*> sentVerts); //Fails if matrix already generated

		bool Add (Vertex<itemType>* start, Vertex<itemType>* end, bool directed, int weight);
		bool Remove (Vertex<itemType>* start, Vertex<itemType>* end);

		int GetEdgeWeight (Vertex<itemType>* start, Vertex<itemType>* end);
		int GetNumVertices ();
		int GetNumEdges ();


	private:
		bool GenerateMatrix (); //Fails if matrix already generated
		void DestroyMatrix ();

		vector<Vertex*> vertices;

		bool isDirected;
		int vertexCount;

		int** adjMatrix; //Dynamic 2D array, will be made after the graph recieves all vertices

};

/////////////////////////////////////////////////////////////////////////////////
///////////// 					End Header File 					/////////////
/////////////////////////////////////////////////////////////////////////////////

//This constructor should never be called, use the param'ed one 
template <class itemType>
GraphMatrix<itemType>::GraphMatrix ()
{
	isDirected = false; //Assumed indirected if not specified
	vertexCount = 0;

	adjMatrix = nullptr;

}

template <class itemType>
GraphMatrix<itemType>::GraphMatrix (vector<Vertex*> sentVerts, bool sentBool)
{
	vertices = sentVerts;

	isDirected = sentBool;
	vertexCount = vertices.size();

	adjMatrix = nullptr;

	GenerateMatrix();

}

template <class itemType>
GraphMatrix<itemType>::~GraphMatrix ()
{
	DestroyMatrix();

	adjMatrix = nullptr;

	//Vertices vector should destroy itself, nothing else is dynamically allocated

}

/////////////////////////////////////////////////////////////////////////////////
///////////// 				End Public Functions 					/////////////
/////////////////////////////////////////////////////////////////////////////////

template <class itemType>
bool GraphMatrix<itemType>::GenerateMatrix ()
{
	if (adjMatrix != nullptr) //Already generated
	{
		cout << "Error: Matrix already generated." << endl;

		return false;

	} else if (vertexCount == 0)
	{
		cout << "Error: Vertex count invalid." << endl;

		return false;

	} else
	{
		adjMatrix = new int*[vertexCount]; //Create the empty rows

		for (int i = 0; i < vertexCount; i++)
		{
			*(adjMatrix + i) = new int[vertexCount]; //Give each row a length

		}

		//Set all starting values to default
		for (int i = 0; i < vertexCount; i++) //For each row
		{
			int* rowTrav = *(adjMatrix + i); //Pointer to the row, stored in an array

			for (int ii = 0; ii < vertexCount; ii++) //For each column in a row
			{
				*(rowTrav + i) = -1; //-1 means no connection, 0 means connected no weight, 1 to +inf means connected with weight

			}
		}

		return true;
	}
}

template <class itemType>
void GraphMatrix<itemType>::GenerateMatrix ()
{
	if (adjMatrix != nullptr)
	{
		//Clears all memory used
		for (int i = 0; i < vertexCount; i++) //For each row
		{
			int* rowTrav = *(adjMatrix + i); //Pointer to the row, stored in an array

			delete[] (*rowTrav);
		}

		delete[] adjMatrix;
		adjMatrix = nullptr;

	}

	return;
}