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
		void RotateLeft (RedBlackNode<itemType>* subtreePtr);
		void RotateRight (RedBlackNode<itemType>* subtreePtr);

		//Fix Functions
		void InsertFix (RedBlackNode<itemType>* subtreePtr, RedBlackNode<itemType>* targetNode);
		void RotateLeft (RedBlackNode<itemType>* subtreePtr, RedBlackNode<itemType>* targetNode);
		void RotateRight (RedBlackNode<itemType>* subtreePtr, RedBlackNode<itemType>* targetNode);

		void Insert (RedBlackNode<itemType>* subtreePtr, itemType value);

		RedBlackNode<itemType>* GetNodeParent (RedBlackNode<itemType>* targetNode);
		char GetNodeColor (RedBlackNode<itemType>* targetNode);

		//Functions, Recursive
		//RedBlackNode<itemType>* PlaceNode (RedBlackNode<itemType>* subtreePtr, RedBlackNode<itemType>* newNode);
		//RedBlackNode<itemType>* RemoveValue (RedBlackNode<itemType>* subtreePtr, itemType target, bool &isSuccessful);
		//RedBlackNode<itemType>* RemoveNode (RedBlackNode<itemType>* nodePtr);
		//RedBlackNode<itemType>* RemoveLeftmostNode (RedBlackNode<itemType>* nodePtr, itemType &successorValue);

		//Traversal Functions
		//void PreorderTraverse (RedBlackNode<itemType>* subtreePtr);
		int InorderTraverse (RedBlackNode<itemType>* subtreePtr);
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
	Insert(rootPtr, entry);

	return true;

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
	if (type == 1) //In
	{
		int total = InorderTraverse(rootPtr);

		cout << "Sum of all values in the RB Tree: " << total << endl;

	} else
	{
		cout << "Invalid traversal type requested. Traversal failed. Must be 1." << endl;

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

	//cout << "Print job ended." << endl;

	return;

}


/////////////////////////////////////////////////////////////////////////////////
///////////// 				End Public Functions 					/////////////
/////////////////////////////////////////////////////////////////////////////////

template<class itemType>
void RedBlackTree<itemType>::InsertFix (RedBlackNode<itemType>* subtreePtr, RedBlackNode<itemType>* targetNode)
{
	//cout << "Starting InsertFix...." << endl;

	char parentColor = 'U';// GetNodeColor(GetNodeParent(targetNode)); //U is not used anywhere else

	if (GetNodeParent(targetNode) == rootPtr)
	{
		parentColor = 'B';

	} else
	{
		parentColor = GetNodeColor(GetNodeParent(targetNode)); //Get the color of the parent node

	}

	//cout << "Parent found." << endl;

	RedBlackNode<itemType>* currentTargetNode = targetNode;

	int count = 0;

	while ((parentColor == 'R' || parentColor == 'U') && currentTargetNode != rootPtr && currentTargetNode != NULL && count < 3)
	{
		//cout << "Starting new while loop iteration in InsertFix..." << endl;
		//cout << "In current iteration parentColor is " << parentColor << endl;

		RedBlackNode<itemType>* parentTargetNode = GetNodeParent(currentTargetNode);

		//cout << "Got parentTargetNode..." << endl;

		RedBlackNode<itemType>* grandfatherNode = GetNodeParent(parentTargetNode);

		//cout << "Got grandfatherNode..." << endl;

		if (grandfatherNode == NULL)
		{
			//cout << "grandfatherNode is NULL!!!" << endl;

		}

		if (grandfatherNode != NULL && (*grandfatherNode).GetLeftChild() == parentTargetNode)
		{
			parentColor = (*grandfatherNode).GetLeftColor();

		} else if (grandfatherNode != NULL) //It is the right child
		{
			parentColor = (*grandfatherNode).GetRightColor();

		}

		//cout << "Got new parentColor..." << endl;

		if (grandfatherNode != NULL && (*grandfatherNode).GetLeftChild() == parentTargetNode)
		{
			//cout << "Parent is the left child of grandparent..." << endl;

			RedBlackNode<itemType>* yNode = (*grandfatherNode).GetRightChild(); //y is the Uncle node

			//cout << "yNode set..." << endl;

			if (GetNodeColor(yNode) == 'R') //Case 1
			{
				//cout << "Detected Case 1 in top clause..." << endl;

				(*grandfatherNode).SetLeftColor('B');
				(*grandfatherNode).SetRightColor('B');

				RedBlackNode<itemType>* greatGrandNode = GetNodeParent(grandfatherNode);

				//cout << "Got greatGrandNode..." << endl;

				if (greatGrandNode != NULL && (*greatGrandNode).GetLeftChild() == grandfatherNode)
				{
					(*greatGrandNode).SetLeftColor('R');

				} else if (greatGrandNode != NULL)
				{
					(*greatGrandNode).SetRightColor('R');

				}

				currentTargetNode = grandfatherNode;

				//cout << "currentTargetNode updated..." << endl;

			} else if (currentTargetNode == (*parentTargetNode).GetRightChild())
			{
				//cout << "Detected Case 3->2 in top clause..." << endl;

				//Case 3 then immediately followed by
				//Case 2

				//currentTargetNode = parentTargetNode;

				RotateLeft(subtreePtr, parentTargetNode);

				currentTargetNode = parentTargetNode;

				parentTargetNode = GetNodeParent(currentTargetNode); //Should be the previous target node
				grandfatherNode = GetNodeParent(parentTargetNode);

				if ((*grandfatherNode).GetLeftChild() == parentTargetNode)
				{
					(*grandfatherNode).SetLeftColor('B');

				} else if ((*grandfatherNode).GetRightChild() == parentTargetNode)
				{
					(*grandfatherNode).SetRightColor('B');

				}

				RedBlackNode<itemType>* greatGrandNode = GetNodeParent(grandfatherNode);

				if (grandfatherNode == rootPtr)
				{
					//cout << "grandfatherNode is root so: " << endl;

				}

				if (greatGrandNode == NULL)
				{
					//cout << "WARNING: greatGrandNode is NULL!!!!" << endl;

				} 

				if (greatGrandNode != NULL && (*greatGrandNode).GetLeftChild() == grandfatherNode)
				{
					(*greatGrandNode).SetLeftColor('R');

				} else if (greatGrandNode != NULL)
				{
					(*greatGrandNode).SetRightColor('R');

				}

				RotateRight(subtreePtr, grandfatherNode);

			}
		} else if (grandfatherNode != NULL && (*grandfatherNode).GetRightChild() == parentTargetNode)
		{
			//cout << "Parent is the right child of grandfatherNode..." << endl;

			RedBlackNode<itemType>* yNode = (*grandfatherNode).GetLeftChild();

			//cout << "Got yNode..." << endl;

			if (GetNodeColor(yNode) == 'R') //Case 1
			{
				//cout << "Detected Case 1 in bottom clause..." << endl;

				(*grandfatherNode).SetLeftColor('B');
				(*grandfatherNode).SetRightColor('B');

				//cout << "Colors set..." << endl;

				RedBlackNode<itemType>* greatGrandNode = GetNodeParent(grandfatherNode);

				//cout <<"greatGrandNode got..." << endl;

				if (greatGrandNode == NULL)
				{
					//cout << "GGN is NULL!!!" << endl;

				}

				if (greatGrandNode != NULL && (*greatGrandNode).GetLeftChild() == grandfatherNode)
				{
					(*greatGrandNode).SetLeftColor('R');

				} else if (greatGrandNode != NULL)
				{
					(*greatGrandNode).SetRightColor('R');

				}

				currentTargetNode = grandfatherNode;

			} else if (currentTargetNode == (*parentTargetNode).GetRightChild())
			{	
				//cout << "Detected Case 3->2 in bottom clause..." << endl; 

				//Case 3 then immediately followed by
				//Case 2

				//currentTargetNode = parentTargetNode;

				RotateLeft(subtreePtr, parentTargetNode);

				currentTargetNode = parentTargetNode;

				//cout << "Set currentTargetNode..." << endl;

				parentTargetNode = GetNodeParent(currentTargetNode); //Should be the previous target node
				grandfatherNode = GetNodeParent(parentTargetNode);

				//cout << "Elder nodes set..." << endl;

				if ((*grandfatherNode).GetLeftChild() == parentTargetNode)
				{
					(*grandfatherNode).SetLeftColor('B');

				} else if ((*grandfatherNode).GetRightChild() == parentTargetNode)
				{
					(*grandfatherNode).SetRightColor('B');

				}

				RedBlackNode<itemType>* greatGrandNode = GetNodeParent(grandfatherNode);

				if (grandfatherNode == rootPtr)
				{
					//cout << "grandfatherNode is root so: " << endl;

				}

				if (greatGrandNode == NULL)
				{
					//cout << "WARNING: greatGrandNode is NULL!!!!" << endl;

				} 

				if (greatGrandNode != NULL && (*greatGrandNode).GetLeftChild() == grandfatherNode)
				{
					(*greatGrandNode).SetLeftColor('R');

				} else if (greatGrandNode != NULL) //Should just be the right
				{
					(*greatGrandNode).SetRightColor('R');

				}

				RotateRight(subtreePtr, grandfatherNode);

			}
		}

		//cout << "End left/right check..." << endl;

		count++;
	}

	return;
	
}

template<class itemType>
void RedBlackTree<itemType>::RotateLeft (RedBlackNode<itemType>* subtreePtr, RedBlackNode<itemType>* targetNode)
{
	//cout << "\tRotate Left called." << endl;

	RedBlackNode<itemType>* yNode = (*targetNode).GetRightChild(); //targetNode is x

	if (yNode == NULL)
	{
		//cout << "\tyNode is NULL!!!" << endl;
		//cout << "\tSkipping roataion...." << endl;

	}

	if (yNode != NULL)
	{
		(*targetNode).SetRightChild((*yNode).GetLeftChild()); //y’s left subtree becomes x’s right subtree

		if ((*yNode).GetLeftChild() != NULL)
		{
			//Set Y's left branch's parent as x, I think the nodes are supposed to have a parent field?

		}

		RedBlackNode<itemType>* parentTargetNode = GetNodeParent(targetNode);


		//Set X's parent to now be Y's parent, X is still stored as targetNode
		//Note: Checking if the parent is NULL might need to be its own if statement
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

		//cout << "\tRotate Left done." << endl;

	}

	

	return;
	
}

template<class itemType>
void RedBlackTree<itemType>::RotateRight (RedBlackNode<itemType>* subtreePtr, RedBlackNode<itemType>* targetNode)
{
	//cout << "\tRotate Right called." << endl;

	if (targetNode == NULL)
	{
		//cout << "\t(In RotateRight) targetNode is NULL!!!!" << endl;

	}

	RedBlackNode<itemType>* xNode = (*targetNode).GetLeftChild(); //targetNode is y

	if (xNode == NULL)
	{
		//cout << "\t(In RotateRight) xNode is NULL!!!!" << endl;
		//cout << "\tSkipping rotation..." << endl;

	}

	if (xNode != NULL)
	{
		(*targetNode).SetLeftChild((*xNode).GetRightChild()); //x's right subtree becomes y's left

		RedBlackNode<itemType>* parentTargetNode = GetNodeParent(targetNode);

		//cout << "\tparentTargetNode got..." << endl;

		//Set X's parent to now be Y's parent, X is still stored as targetNode
		//Note: Checking if the parent is NULL might need to be its own if statement
		if (parentTargetNode != NULL && (*parentTargetNode).GetLeftChild() == targetNode) //If x is the left node of the parent
		{
			(*parentTargetNode).SetLeftChild(xNode);

		} else if (parentTargetNode != NULL && (*parentTargetNode).GetRightChild() == targetNode)
		{
			(*parentTargetNode).SetRightChild(xNode);

		} else if (parentTargetNode == NULL) //X was the root
		{
			rootPtr = xNode;

		}

		(*xNode).SetRightChild(targetNode);

		//cout << "\tRotate Right done." << endl;

	}

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
		rootPtr = new RedBlackNode<itemType>(value, true, 'B');

	} else
	{
		RedBlackNode<itemType>* newNode = new RedBlackNode<itemType>(value, false, 'R'); //Fix will determine right color

		if (value < (*parent).GetValue()) //Become left child
		{
			(*parent).SetLeftChild(newNode);
			(*parent).SetLeftColor('R');

		} else //Become right child
		{
			(*parent).SetRightChild(newNode);
			(*parent).SetRightColor('R');

		}

		//newNode = NULL;

		//cout << "Insert Done. Calling Fix." << endl;

		InsertFix(subtreePtr, newNode);

	}

	return;
	
}

template<class itemType>
RedBlackNode<itemType>* RedBlackTree<itemType>::GetNodeParent (RedBlackNode<itemType>* targetNode)
{
	RedBlackNode<itemType>* parent = NULL;
	RedBlackNode<itemType>* treeTrav = rootPtr;

	//cout << "\t(In GetNodeParent) Pointers set, getting value..." << endl;

	itemType targetValue;

	if (targetNode == NULL)
	{
		//cout << "\t(In GetNodeParent) NULL targetNode..." << endl;

	} else
	{
		targetValue = (*targetNode).GetValue();

	}

	//cout << "\t(In GetNodeParent) Value got..." << endl;

	if (targetNode == rootPtr)
	{
		//cout << "\t(In GetNodeParent) WARNING: This node has no parent, it is the root." << endl;
		////cout << "The program will probably crash in just a second..." << endl;

	}

	//cout << "\t(In GetNodeParent) starting loop..." << endl;

	while ((*treeTrav).GetValue() != targetValue && targetNode != NULL)
	{
		if (treeTrav == NULL)
		{
			//cout << "\t(In GetNodeParent) Heads up, treeTrav is NULL..." << endl;

		}

		parent = treeTrav;

		if (targetValue < (*treeTrav).GetValue()) //Go left
		{
			treeTrav = (*treeTrav).GetLeftChild();

		} else //Go right
		{
			treeTrav = (*treeTrav).GetRightChild();

		}
	}

	//cout << "\tGNP Done." << endl;

	return parent;
	
}

template<class itemType>
char RedBlackTree<itemType>::GetNodeColor (RedBlackNode<itemType>* targetNode)
{
	//cout << "\t(Inside of GetNodeColor) Getting parent..." << endl;

	RedBlackNode<itemType>* parentNode = GetNodeParent(targetNode);

	//cout << "\tParent got..." << endl;

	char color = 'X';

	if (targetNode == NULL)
	{
		color = 'B';

	}else if ((*parentNode).GetLeftChild() == targetNode)
	{
		color = (*parentNode).GetLeftColor();

	} else if ((*parentNode).GetRightChild() == targetNode)
	{
		color = (*parentNode).GetRightColor();

	}

	//cout << "Got that node color was " << color << endl;

	return color;
	
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
		////cout << "~NULL~";

	} else
	{
		//cout << (*subtreePtr).GetValue() << " has children: ";

		if ((*subtreePtr).GetLeftChild() == NULL)
		{
			//cout << "NULL";

		} else
		{
			//cout << (*((*subtreePtr).GetLeftChild())).GetValue();

		}

		//cout << " and ";

		if ((*subtreePtr).GetRightChild() == NULL)
		{
			//cout << "NULL";

		} else
		{
			//cout << (*((*subtreePtr).GetRightChild())).GetValue();

		}

		//cout << endl;

		DebugPrint((*subtreePtr).GetLeftChild());
		DebugPrint((*subtreePtr).GetRightChild());

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
int RedBlackTree<itemType>::InorderTraverse (RedBlackNode<itemType>* subtreePtr)
{
	int sum = 0;

	if (subtreePtr == NULL)
	{
		//Tree is empty, end recursive calls

		//cout << "Hit end of a branch." << endl;

		return 0;

	} else
	{
		//cout << "Found node with value: " << (*subtreePtr).GetValue();

		sum += InorderTraverse((*subtreePtr).GetLeftChild());
		sum += (*subtreePtr).GetValue();
		sum += InorderTraverse((*subtreePtr).GetRightChild());

	}

	return sum;

}