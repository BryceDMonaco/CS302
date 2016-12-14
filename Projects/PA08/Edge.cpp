#include <iosteam>

using namespace std;

template <class itemType>
class Edge
{
	public:
		Edge ();
		Edge (Vertex<itemType>* sentStart, Vertex<itemType>* sentDest, bool sentBool, int sentWeight)
		~Edge ();

		void SetStart (Vertex<itemType>* sentStart);
		void SetDestination (Vertex<itemType>* SetDestination);
		void SetDirected (bool sentBool);
		void SetWeight (int sentWeight);

		Vertex<itemType>* GetStart ();
		Vertex<itemType>* GetDestination ();
		bool GetDirected ();
		int GetWeight ();

	private:
		Vertex<itemType>* startPtr;
		Vertex<itemType>* destinationPtr;

		bool isDirected; //If true, the edge only goes from start to destination

		int weight; //-1 means unweighted, any other positive value will be considered a weight

};

template <class itemType>
Edge<itemType>::Edge ()
{
	startPtr = nullptr;
	destinationPtr = nullptr;

	isDirected = false;

	weight = -1;

}

template <class itemType>
Edge<itemType>::Edge (Vertex<itemType>* sentStart, Vertex<itemType>* sentDest, bool sentBool, int sentWeight)
{
	startPtr = sentStart;
	destinationPtr = sentDest;

	isDirected = sentBool;

	weight = sentWeight;

}

template <class itemType>
Edge<itemType>::~Edge ()
{
	startPtr = nullptr;
	destinationPtr = nullptr;

}

template <class itemType>
void Edge<itemType>::SetStart (Vertex<itemType>* sentStart)
{
	startPtr = sentStart;

	return;

}

template <class itemType>
void Edge<itemType>::SetDestination (Vertex<itemType>* sentDest)
{
	destinationPtr = sentDest;

	return;

}

template <class itemType>
void Edge<itemType>::SetDirected (bool sentBool)
{
	isDirected = sentBool;

	return;

}

template <class itemType>
void Edge<itemType>::SetWeight (int sentWeight)
{
	weight = sentWeight;

	return;

}

template <class itemType>
Vertex<itemType>* Edge<itemType>::GetStart ()
{
	return startPtr;

}

template <class itemType>
Vertex<itemType>* Edge<itemType>::GetDestination ()
{
	return destinationPtr;

}

template <class itemType>
bool Edge<itemType>::GetDirected ()
{
	return isDirected;

}

template <class itemType>
int Edge<itemType>::GetWeight ()
{
	return weight;

}