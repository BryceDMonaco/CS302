#include <iostream>

#include "LeafNode.cpp"

using namespace std;

template<class itemType>
class BinarySearchTree
{
	public:
		BinarySearchTree ();
		~BinarySearchTree ();
		//No parameterized const. because I want the items to be pushed into the tree one at a time

		bool IsEmpty ();

		bool Add (itemType entry); //Itegrated SetRootData
		bool Remove (itemType target); //Remove the node with the target value

		int GetHeight ();
		int GetNodeCount ();
		itemType GetRootData ();

		void Clear ();

	private:
		//Values
		LeafNode<itemType>* rootPtr;
		int nodeCount;

		//Functions, Recursive
		LeafNode<itemType>* PlaceNode (LeafNode<itemType>* subtreePtr, LeafNode<itemType>* newNode);

};

/////////////////////////////////////////////////////////////////////////////////
///////////// 					End Header File 					/////////////
/////////////////////////////////////////////////////////////////////////////////

template<class itemType>
BinarySearchTree<itemType>::BinarySearchTree ()
{
	rootPtr = NULL;

	nodeCount = 0;

}

template<class itemType>
BinarySearchTree<itemType>::~BinarySearchTree ()
{
	delete rootPtr;
	rootPtr = NULL;

}

template<class itemType>
bool BinarySearchTree<itemType>::IsEmpty ()
{
	if (rootPtr == NULL)
	{
		return true;

	} else
	{
		return false;

	}
}

template<class itemType>
bool BinarySearchTree<itemType>::Add (itemType entry)
{
	if (IsEmpty())
	{
		rootPtr = new LeafNode<itemType>(entry, true);

		return true;

	} else
	{


	}

}

/////////////////////////////////////////////////////////////////////////////////
///////////// 				End Public Functions 					/////////////
/////////////////////////////////////////////////////////////////////////////////

//Adapted from pg 492-493 Pseudocode
template<class itemType>
LeafNode<itemType>* BinarySearchTree<itemType>::PlaceNode (LeafNode<itemType>* subtreePtr, LeafNode<itemType>* newNode);
{
	if (subtreePtr == NULL)
	{
		return newNode;

	} else if ((*subtreePtr).GetValue() > (*newNode).GetValue()) //Go to the left branch
	{
		tempPtr = PlaceNode((*subtreePtr).GetLeftChild(), newNode);

		(*subtreePtr).SetLeftChild(tempPtr);

	} else if ((*subtreePtr).GetValue() < (*newNode).GetValue()) //Go to the right branch
	{
		tempPtr = PlaceNode((*subtreePtr).GetRightChild(), newNode);

		(*subtreePtr).SetRightChild(tempPtr);

	}

	return subtreePtr;

}