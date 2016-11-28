/**
*	@file BinarySearchTree.cpp
*
*	@brief This is the header and implmentation of BinarySearchTree
*
*	@author Bryce Monaco
*
*	@details This file contains the header and implementation of BinarySearchTree
*
*	@version 1.0
*
*	@note Header and implementation are in one file to fix some templating issues.
*/

#include <iostream>

#include "LeafNode.cpp"

using namespace std;

template<class itemType>
class BinarySearchTree
{
	public:
		BinarySearchTree ();
		~BinarySearchTree ();
		//No parameterized constructor because I want the items to be pushed into the tree one at a time

		bool IsEmpty ();

		bool Add (itemType entry); //Itegrated SetRootData
		bool Remove (itemType target); //Remove the node with the target value

		int GetHeight ();
		int GetNodeCount ();
		//itemType GetRootData ();

		void DoTraversal (int type); //0 = Pre, 1 = In, 2 = Post

		void Clear ();
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

		//Traversal Functions
		void PreorderTraverse (LeafNode<itemType>* subtreePtr);
		void InorderTraverse (LeafNode<itemType>* subtreePtr);
		void PostorderTraverse (LeafNode<itemType>* subtreePtr);

		int CountChildren (LeafNode<itemType>* subtreePtr);
		int CountHeight (LeafNode<itemType>* subtreePtr);

		void DebugPrint (LeafNode<itemType>* subtreePtr); //A print function meant only for debug purposes

};

/////////////////////////////////////////////////////////////////////////////////
///////////// 					End Header File 					/////////////
/////////////////////////////////////////////////////////////////////////////////

/**
*	@brief The default constructor of a BinarySearchTree object
*
*	@details This constructor initializes values of a BinarySearchTree object to default values
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
BinarySearchTree<itemType>::BinarySearchTree ()
{
	rootPtr = NULL;

	nodeCount = 0;

}

/**
*	@brief The destructor of a BinarySearchTree object
*
*	@details This removes the BinarySearchTree from memory
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
BinarySearchTree<itemType>::~BinarySearchTree ()
{
	delete rootPtr;
	rootPtr = NULL;

}

/**
*	@brief Checks if the tree is empty
*
*	@details Checks if the tree is empty by checking the root pointer
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns a bool signifying whether or not the tree is empty
*
*	@note None.
*
*/
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

/**
*	@brief Adds a value to the tree
*
*	@details Adds the sent value to the tree
*
*	@par Algorithm Recursively finds the proper position for the new node 
*
*	@param[in] entry The value to store in the tree
*
*	@param[out] None.
*
*	@return Returns a bool signifying if the node could be added, always true
*
*	@note None.
*
*/
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

/**
*	@brief Removes the target value from the tree
*
*	@details Seaches for the target value and removes it if it is found
*
*	@par Algorithm Recursively finds the value and then removes it
*
*	@param[in] target The value to remove from the tree
*
*	@param[out] None.
*
*	@return Returns a bool signifying if the node could be removed, false if the value doesn't exist
*
*	@note None.
*
*/
template<class itemType>
bool BinarySearchTree<itemType>::Remove (itemType target)
{
	bool isSuccessful = false;

	rootPtr = RemoveValue(rootPtr, target, isSuccessful);

	return isSuccessful;

}

/**
*	@brief Gets the height of the tree.
*
*	@details Gets the height of the tree by counting the longest branch.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns an int which is the height of the tree.
*
*	@note None.
*
*/
template<class itemType>
int BinarySearchTree<itemType>::GetHeight ()
{
	return 1 + CountHeight(rootPtr);

}

/**
*	@brief Gets the node count of the tree.
*
*	@details Gets the node count of the tree by counting each node.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns an int which is the node count of the tree.
*
*	@note None.
*
*/
template<class itemType>
int BinarySearchTree<itemType>::GetNodeCount ()
{
	return CountChildren(rootPtr);

}

/**
*	@brief Performs a specific traversal of the tree.
*
*	@details Expects a value 0-2 which picks the type of traversal to do.
*
*	@par Algorithm None.
*
*	@param[in] type An int which is the type of traversal to do. 0 = Pre, 1 = In, 2 = Post
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void BinarySearchTree<itemType>::DoTraversal (int type)
{
	if (type == 0) //Pre
	{
		PreorderTraverse(rootPtr);

	} else if (type == 1) //In
	{
		InorderTraverse(rootPtr);

	} else if (type == 2) //Post
	{
		PostorderTraverse(rootPtr);

	} else
	{
		cout << "Invalid traversal type requested. Traversal failed." << endl;

	}

	return;

}

/**
*	@brief Empties the tree.
*
*	@details Clears the tree by deleting the root and then setting it to null.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void BinarySearchTree<itemType>::Clear ()
{
	delete rootPtr;
	rootPtr = NULL;

	nodeCount = 0;

	return;

}

/**
*	@brief A debug function to print the tree.
*
*	@details Prints the tree, used for debugging.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
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

/**
*	@brief Places a new node at the first available and proper position.
*
*	@details Goes down the tree until it finds a position where the node can be stored.
*
*	@par Algorithm Recursively traverses the tree to find a valid position for the new node.
*
*	@param[in] subTreePtr The pointer to the current subtree
*
*	@param[in] newNode The pointer to the new node to be placed
*
*	@param[out] None.
*
*	@return Returns a pointer to the newly placed node.
*
*	@note if the entry data type does not have a definition for '>' and '<' that the function will fail
*
*/
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

/**
*	@brief removes the node with the value
*
*	@details Removes the node with the specific value and then fixes the leaves.
*
*	@par Algorithm none.
*
*	@param[in] subTreePtr The pointer to the current subtree
*
*	@param[in] target The value to remove
*
*	@param[in] isSuccessful The bool to signify if the node could be found and removed
*
*	@param[out] None.
*
*	@return Returns a pointer to the subtree
*
*	@note None.
*
*/
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

/**
*	@brief removes the sent node
*
*	@details Removes the sent node and fixes the children
*
*	@par Algorithm none.
*
*	@param[in] nodePtr The pointer to the node to remove
*
*	@param[out] None.
*
*	@return Returns a pointer to the subtree
*
*	@note None.
*
*/
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

/**
*	@brief removes the leftmost node in a tree
*
*	@details Removes the leftmost node in the sent branch
*
*	@par Algorithm none.
*
*	@param[in] nodePtr The pointer to the node to remove
*
*	@param[in] successorValue The value of the previous node
*
*	@param[out] None.
*
*	@return Returns a pointer to the subtree
*
*	@note None.
*
*/
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

/**
*	@brief Counts the nodes in the tree
*
*	@details Runs through the tree and counts each node.
*
*	@par Algorithm none.
*
*	@param[in] subtreePtr The pointer to the tree to traverse
*
*	@param[out] None.
*
*	@return Returns the count of the nodes.
*
*	@note None.
*
*/
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

/**
*	@brief Finds the longest branch of the tree
*
*	@details Runs through the tree and returns the height of the longest branch.
*
*	@par Algorithm none.
*
*	@param[in] subtreePtr The pointer to the tree to traverse
*
*	@param[out] None.
*
*	@return Returns the height of the tree.
*
*	@note None.
*
*/
template<class itemType>
int BinarySearchTree<itemType>::CountHeight (LeafNode<itemType>* subtreePtr)
{
	int leftHeight = 0;
	int rightHeight = 0;

	if ((*subtreePtr).GetLeftChild() != NULL)
	{
		leftHeight = 1 + CountHeight((*subtreePtr).GetLeftChild());

	}

	if ((*subtreePtr).GetRightChild() != NULL)
	{
		rightHeight = 1 + CountHeight((*subtreePtr).GetRightChild());
	
	}

	if (leftHeight >= rightHeight)
	{
		return leftHeight;

	} else
	{
		return rightHeight;

	}
}

/**
*	@brief A debug function to print the tree.
*
*	@details Prints the tree, used for debugging.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
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

/**
*	@brief Does a preorder traversal of the tree
*
*	@details Traverses the tree by printing the current root, then the left, and then the right child.
*
*	@par Algorithm None.
*
*	@param[in] subtreePtr Pointer to the current subtree.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void BinarySearchTree<itemType>::PreorderTraverse (LeafNode<itemType>* subtreePtr)
{
	if (subtreePtr == NULL)
	{
		//Tree is empty, end recursive calls

	} else
	{
		cout << (*subtreePtr).GetValue() << ", ";

		PreorderTraverse((*subtreePtr).GetLeftChild());
		PreorderTraverse((*subtreePtr).GetRightChild());

	}

	return;

}

/**
*	@brief Does an inorder traversal of the tree
*
*	@details Traverses the tree by printing the left, current root, and then the right child.
*
*	@par Algorithm None.
*
*	@param[in] subtreePtr Pointer to the current subtree.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void BinarySearchTree<itemType>::InorderTraverse (LeafNode<itemType>* subtreePtr)
{
	if (subtreePtr == NULL)
	{
		//Tree is empty, end recursive calls

	} else
	{
		InorderTraverse((*subtreePtr).GetLeftChild());
		cout << (*subtreePtr).GetValue() << ", ";
		InorderTraverse((*subtreePtr).GetRightChild());

	}

	return;

}

/**
*	@brief Does a postorder traversal of the tree
*
*	@details Traverses the tree by printing the left, the right child, and the current root.
*
*	@par Algorithm None.
*
*	@param[in] subtreePtr Pointer to the current subtree.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void BinarySearchTree<itemType>::PostorderTraverse (LeafNode<itemType>* subtreePtr)
{
	if (subtreePtr == NULL)
	{
		//Tree is empty, end recursive calls

	} else
	{
		PostorderTraverse((*subtreePtr).GetLeftChild());
		PostorderTraverse((*subtreePtr).GetRightChild());
		cout << (*subtreePtr).GetValue() << ", ";

	}

	return;

}