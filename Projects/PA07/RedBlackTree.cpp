/**
*	@file RedBlackTree.cpp
*
*	@brief This is the header and implmentation of RedBlackTree
*
*	@author Bryce Monaco
*
*	@details This file contains the header and implementation of RedBlackTree
*
*	@version 1.0
*
*	@note Header and implementation are in one file to fix some templating issues.
*/

#include <iostream>

#include "RedBlackNode.cpp"

using namespace std;

template<class itemType>
class RedBlackTree
{
	public:
		RedBlackTree ();
		~RedBlackTree ();
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
		RedBlackNode<itemType>* rootPtr;
		int nodeCount; //Doesn't get used

		//Rotations
		void RotateLeft (RedBlackNode* subtreePtr);
		void RotateRight (RedBlackNode* subtreePtr);

		//Fix Functions
		void InsertFix (RedBlackNode* subtreePtr, itemType value);
		void LeftRotate (RedBlackNode* subtreePtr, RedBlackNode* targetNode)

		void Insert (RedBlackNode* subtreePtr, itemType value);

		RedBlackNode<itemType>* GetNodeParent (RedBlackNode* targetNode);

		//Functions, Recursive
		//RedBlackNode<itemType>* PlaceNode (RedBlackNode<itemType>* subtreePtr, RedBlackNode<itemType>* newNode);
		//RedBlackNode<itemType>* RemoveValue (RedBlackNode<itemType>* subtreePtr, itemType target, bool &isSuccessful);
		//RedBlackNode<itemType>* RemoveNode (RedBlackNode<itemType>* nodePtr);
		//RedBlackNode<itemType>* RemoveLeftmostNode (RedBlackNode<itemType>* nodePtr, itemType &successorValue);

		//Traversal Functions
		//void PreorderTraverse (RedBlackNode<itemType>* subtreePtr);
		void InorderTraverse (RedBlackNode<itemType>* subtreePtr);
		//void PostorderTraverse (RedBlackNode<itemType>* subtreePtr);

		int CountChildren (RedBlackNode<itemType>* subtreePtr);
		int CountHeight (RedBlackNode<itemType>* subtreePtr);

		void DebugPrint (RedBlackNode<itemType>* subtreePtr); //A print function meant only for debug purposes

};

/////////////////////////////////////////////////////////////////////////////////
///////////// 					End Header File 					/////////////
/////////////////////////////////////////////////////////////////////////////////

/**
*	@brief The default constructor of a RedBlackTree object
*
*	@details This constructor initializes values of a RedBlackTree object to default values
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
RedBlackTree<itemType>::RedBlackTree ()
{
	rootPtr = NULL;

	nodeCount = 0; 

}

/**
*	@brief The destructor of a RedBlackTree object
*
*	@details This removes the RedBlackTree from memory
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
RedBlackTree<itemType>::~RedBlackTree ()
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
bool RedBlackTree<itemType>::IsEmpty ()
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
bool RedBlackTree<itemType>::Add (itemType entry)
{
	if (IsEmpty())
	{
		rootPtr = new RedBlackNode<itemType>(entry, true, 'B');

		return true;

	} else
	{
		RedBlackNode<itemType>* newLeaf = new RedBlackNode<itemType>(entry, false, 'X'); //Tom Nook would be proud

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
bool RedBlackTree<itemType>::Remove (itemType target)
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
int RedBlackTree<itemType>::GetHeight ()
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
int RedBlackTree<itemType>::GetNodeCount ()
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
void RedBlackTree<itemType>::DoTraversal (int type)
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
void RedBlackTree<itemType>::Clear ()
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
void RedBlackTree<itemType>::Print ()
{
	DebugPrint(rootPtr);

	cout << "Print job ended." << endl;

	return;

}


/////////////////////////////////////////////////////////////////////////////////
///////////// 				End Public Functions 					/////////////
/////////////////////////////////////////////////////////////////////////////////

template<class itemType>
void RedBlackTree<itemType>::InsertFix (RedBlackNode<itemType>* subtreePtr, itemType value)
{
	//Eeeeewwwwwwwwwwwwwwwwwwwwwww, if this were a Pokemon it'd be called Ewwtwo
	
}

template<class itemType>
void RedBlackTree<itemType>::LeftRotate (RedBlackNode* subtreePtr, RedBlackNode* targetNode)
{
	RedBlackNode<itemType>* yNode = (*targetNode).GetRightChild(); //targetNode is x

	(*targetNode).SetRightChild((*yNode).GetLeftChild()); //y’s left subtree becomes x’s right subtree

	if ((*yNode).GetLeftChild() != NULL)
	{
		//Set Y's left branch's parent as x, I think the nodes are supposed to have a parent field?

	}

	RedBlackNode<itemType>* parentTargetNode = GetNodeParent(targetNode);


	//Set X's parent to now be Y's parent, X is still stored as targetNode
	if (parentTargetNode != NULL && (*parentTargetNode).GetLeftChild() == targetNode) //If x is the left node of the parent
	{
		(*parentTargetNode).SetLeftChild(yNode);

	} else if (parentTargetNode != NULL && (*parentTargetNode).GetRightChild() == targetNode)
	{
		(*parentTargetNode).SetRightChild(yNode);

	} else if (parentTargetNode == NULL) //X was the root
	{
		rootPtr = yNode;

	}

	(*yNode).SetLeftChild(targetNode);

	return;
	
}

template<class itemType>
void RedBlackTree<itemType>::Insert (RedBlackNode<itemType>* subtreePtr, itemType value)
{
	RedBlackNode<itemType>* parent = NULL;

	RedBlackNode<itemType>* treeTrav = subtreePtr;

	while (treeTrav != NULL)
	{
		parent = treeTrav;

		if (value < (*treeTrav).GetValue()) //Go left
		{
			treeTrav = (*treeTrav).GetLeftChild();

		} else //Go right
		{
			treeTrav = (*treeTrav).GetRightChild();

		}

	}

	if (parent == NULL) //Tree was empty
	{
		subtreePtr= new RedBlackNode<itemType>(value, true, 'B');

	} else
	{
		RedBlackNode* newNode = new RedBlackNode<itemType>(value, false, 'R'); //Fix will determine right color

		if (value < (*parent).GetValue()) //Become left child
		{
			(*parent).SetLeftChild(newNode);

		} else //Become right child
		{
			(*parent).SetRightChild(newNode);

		}

		//newNode = NULL;

	}

	InsertFix(subtreePtr, value);

	return;
	
}

template<class itemType>
RedBlackNode<itemType>* RedBlackTree<itemType>::GetNodeParent (RedBlackNode* targetNode)
{
	RedBlackNode<itemType>* parent = NULL;
	RedBlackNode<itemType>* treeTrav = rootPtr;

	itemType targetValue = (*targetNode).GetValue();

	while ((*treeTrav).GetValue() != targetValue)
	{
		parent = treeTrav;

		if (targetValue < (*treeTrav).GetValue()) //Go left
		{
			treeTrav = (*treeTrav).GetLeftChild();

		} else //Go right
		{
			treeTrav = (*treeTrav).GetRightChild();

		}
	}

	return parent;
	
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
int RedBlackTree<itemType>::CountChildren (RedBlackNode<itemType>* subtreePtr)
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
int RedBlackTree<itemType>::CountHeight (RedBlackNode<itemType>* subtreePtr)
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
void RedBlackTree<itemType>::DebugPrint (RedBlackNode<itemType>* subtreePtr)
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
void RedBlackTree<itemType>::PreorderTraverse (RedBlackNode<itemType>* subtreePtr)
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
void RedBlackTree<itemType>::InorderTraverse (RedBlackNode<itemType>* subtreePtr)
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
void RedBlackTree<itemType>::PostorderTraverse (RedBlackNode<itemType>* subtreePtr)
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