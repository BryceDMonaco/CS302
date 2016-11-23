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

		//int GetHeight ();
		int GetNodeCount ();
		//itemType GetRootData ();

		//void Clear ();
		void Print ();

	private:
		//Values
		LeafNode<itemType>* rootPtr;
		int nodeCount;

		//Functions, Recursive
		LeafNode<itemType>* PlaceNode (LeafNode<itemType>* subtreePtr, LeafNode<itemType>* newNode);
		LeafNode<itemType>* RemoveValue (LeafNode<itemType>* subtreePtr, itemType target, bool &isSuccessful);
		LeafNode<itemType>* RemoveNode (LeafNode<itemType>* nodePtr);
		LeafNode<itemType>* RemoveLeftmostNode (LeafNode<itemType>* nodePtr, itemType &successorValue);

		int CountChildren (LeafNode<itemType>* subtreePtr);

		void DebugPrint (LeafNode<itemType>* subtreePtr); //A print function meant only for debug purposes

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
		LeafNode<itemType>* newLeaf = new LeafNode<itemType>(entry, false); //Tom Nook would be proud

		PlaceNode(rootPtr, newLeaf);

	}

}

template<class itemType>
bool BinarySearchTree<itemType>::Remove (itemType target)
{
	bool isSuccessful = false;

	rootPtr = RemoveValue(rootPtr, target, isSuccessful);

	return isSuccessful;

}

template<class itemType>
int BinarySearchTree<itemType>::GetNodeCount ()
{
	int count = CountChildren(rootPtr);

	return count;

}

template<class itemType>
void BinarySearchTree<itemType>::Print ()
{
	DebugPrint(rootPtr);

	cout << "Print job ended." << endl;

	return;

}


/////////////////////////////////////////////////////////////////////////////////
///////////// 				End Public Functions 					/////////////
/////////////////////////////////////////////////////////////////////////////////

//Adapted from pg 492-493 Pseudocode
//Note that if the entry data type does not have a definition for '>' and '<' that the function will fail
template<class itemType>
LeafNode<itemType>* BinarySearchTree<itemType>::PlaceNode (LeafNode<itemType>* subtreePtr, LeafNode<itemType>* newNode)
{
	if (subtreePtr == NULL)
	{
		return newNode;

	} else if ((*subtreePtr).GetValue() > (*newNode).GetValue()) //Go to the left branch
	{
		LeafNode<itemType>* tempPtr = PlaceNode((*subtreePtr).GetLeftChild(), newNode);

		(*subtreePtr).SetLeftChild(tempPtr);

	} else if ((*subtreePtr).GetValue() < (*newNode).GetValue()) //Go to the right branch
	{
		LeafNode<itemType>* tempPtr = PlaceNode((*subtreePtr).GetRightChild(), newNode);

		(*subtreePtr).SetRightChild(tempPtr);

	}

	return subtreePtr;

}

template<class itemType>
LeafNode<itemType>* BinarySearchTree<itemType>::RemoveValue (LeafNode<itemType>* subtreePtr, itemType target, bool &isSuccessful)
{
	if (subtreePtr == NULL) //End of this branch
	{
		isSuccessful = false;

	} else if ((*subtreePtr).GetValue() == target) //Target found
	{
		subtreePtr = RemoveNode(subtreePtr);

		isSuccessful = true;

	} else if ((*subtreePtr).GetValue() > target) //The target could be to the left
	{
		LeafNode<itemType>* tempPtr = RemoveValue((*subtreePtr).GetLeftChild(), target, isSuccessful);
		(*subtreePtr).SetLeftChild(tempPtr);

	} else //The target could be to the right
	{
		LeafNode<itemType>* tempPtr = RemoveValue((*subtreePtr).GetRightChild(), target, isSuccessful);
		(*subtreePtr).SetRightChild(tempPtr);

	}

	return subtreePtr;

}

template<class itemType>
LeafNode<itemType>* BinarySearchTree<itemType>::RemoveNode (LeafNode<itemType>* nodePtr)
{
	if (!(*nodePtr).IsRootNode() && !(*nodePtr).HasChildren()) //Checks if the node is a leaf
	{
		delete nodePtr;
		nodePtr = NULL;

		return nodePtr;

	} else if ((*nodePtr).GetLeftChild() != NULL && (*nodePtr).GetRightChild() == NULL) //Has left child but not right
	{
		LeafNode<itemType>* nodeToConnect = (*nodePtr).GetLeftChild();

		delete nodePtr;
		nodePtr = NULL;

		return nodeToConnect;

	} else if ((*nodePtr).GetLeftChild() == NULL && (*nodePtr).GetRightChild() != NULL) //Has right child but not left
	{
		LeafNode<itemType>* nodeToConnect = (*nodePtr).GetRightChild();

		delete nodePtr;
		nodePtr = NULL;

		return nodeToConnect;

	} else //Has two children 
	{
		itemType newValue;

		LeafNode<itemType>* tempPtr = RemoveLeftmostNode ((*nodePtr).GetRightChild(), newValue);

		(*nodePtr).SetRightChild(tempPtr);
		(*nodePtr).SetValue(newValue);

		return nodePtr;

	}
}

template<class itemType>
LeafNode<itemType>* BinarySearchTree<itemType>::RemoveLeftmostNode (LeafNode<itemType>* nodePtr, itemType &successorValue)
{
	if ((*nodePtr).GetLeftChild() == NULL) //Found leftmost node
	{
		successorValue = (*nodePtr).GetValue();

		return RemoveNode(nodePtr);

	} else
	{
		LeafNode<itemType>* tempPtr = RemoveLeftmostNode((*nodePtr).GetLeftChild(), successorValue);

		(*nodePtr).SetLeftChild(tempPtr);

		return nodePtr;

	}
}

template<class itemType>
int BinarySearchTree<itemType>::CountChildren (LeafNode<itemType>* subtreePtr)
{
	if ((*subtreePtr).GetLeftChild() != NULL && (*subtreePtr).GetRightChild() == NULL) //Has left child but not right
	{
		return 1 + CountChildren((*subtreePtr).GetLeftChild());

	} else if ((*subtreePtr).GetLeftChild() == NULL && (*subtreePtr).GetRightChild() != NULL) //Has right child but not left
	{
		return 1 + CountChildren((*subtreePtr).GetRightChild());		

	} else if ( !(*subtreePtr).HasChildren()) //Has no children
	{
		return 1;

	} else //Has two children 
	{
		int count = 0;

		count += CountChildren((*subtreePtr).GetLeftChild());
		count += CountChildren((*subtreePtr).GetRightChild());

		return 1 + count; 

	}
}

template<class itemType>
void BinarySearchTree<itemType>::DebugPrint (LeafNode<itemType>* subtreePtr)
{
	if (subtreePtr == NULL)
	{
		//cout << "~NULL~";

	} else
	{
		cout << (*subtreePtr).GetValue() << " has children: ";

		if ((*subtreePtr).GetLeftChild() == NULL)
		{
			cout << "NULL";

		} else
		{
			cout << (*((*subtreePtr).GetLeftChild())).GetValue();

		}

		cout << " and ";

		if ((*subtreePtr).GetRightChild() == NULL)
		{
			cout << "NULL";

		} else
		{
			cout << (*((*subtreePtr).GetRightChild())).GetValue();

		}

		cout << endl;

		DebugPrint((*subtreePtr).GetLeftChild());
		DebugPrint((*subtreePtr).GetRightChild());

	}

	return;

}