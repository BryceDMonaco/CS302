#include <iostream>

using namespace std;

template<class itemType>
class RedBlackNode
{
	public:
		RedBlackNode ();
		RedBlackNode (itemType newValue, bool setIsRoot, char color);
		~RedBlackNode ();

		bool IsLeftClear ();
		bool IsRightClear ();
		bool IsRootNode ();
		bool HasChildren ();

		void SetLeftChild (RedBlackNode* newChild);
		void SetRightChild (RedBlackNode* newChild);
		void SetLeftColor (char color);
		void SetRightColor (char color);
		void SetValue (itemType newValue);

		RedBlackNode* GetLeftChild ();
		RedBlackNode* GetRightChild ();
		char GetLeftColor ();
		char GetRightColor ();
		itemType GetValue ();

	private:
		RedBlackNode* leftChild;
		RedBlackNode* rightChild;

		char leftColor;
		char rightColor;

		itemType value;

		bool isRoot;

};

/**
*	@brief The default constructor of a RedBlackNode object
*
*	@details This constructor initializes values of a RedBlackNode object to default values
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
RedBlackNode<itemType>::RedBlackNode ()
{
	leftChild = NULL;
	rightChild = NULL;

	leftColor = 'X'; //I will use X as the default, R is red, B is black
	rightColor = 'X';

}

/**
*	@brief The parameterized constructor of a RedBlackNode object
*
*	@details This constructor initializes values of a RedBlackNode object to sent values
*
*	@par Algorithm None.
*
*	@param[in] newValue The value to store in the node
*
*	@param[in] setIsRoot Tells the node if it is the root node or not
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
RedBlackNode<itemType>::RedBlackNode (itemType newValue, bool setIsRoot, char color)
{
	leftChild = NULL;
	rightChild = NULL;

	leftColor = 'X'; //I will use X as the default, R is red, B is black
	rightColor = 'X';

	value = newValue;
	isRoot = setIsRoot;

}

/**
*	@brief The destructor of a RedBlackNode object
*
*	@details Removes a RedBlackNode from memory.
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
RedBlackNode<itemType>::~RedBlackNode ()
{
	//Nothing to see here.
	//Move along.

}

/**
*	@brief Checks if this node has a left child.
*
*	@details Checks if this node has a left child by checking its pointer value.
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
bool RedBlackNode<itemType>::IsLeftClear ()
{
	if (leftChild == NULL)
	{
		return true;

	} else
	{
		return false;

	}
}

/**
*	@brief Checks if this node has a right child.
*
*	@details Checks if this node has a right child by checking its pointer value.
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
bool RedBlackNode<itemType>::IsRightClear ()
{
	if (rightChild == NULL)
	{
		return true;

	} else
	{
		return false;

	}
}

/**
*	@brief Checks if this node is the root.
*
*	@details Checks if this node is the root node by checking the private boolean isRoot.
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
bool RedBlackNode<itemType>::IsRootNode ()
{
	return isRoot;

}

/**
*	@brief Checks if this node has any children.
*
*	@details Checks if this node has a left or right child by checking its pointer value.
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
bool RedBlackNode<itemType>::HasChildren ()
{
	if (leftChild != NULL || rightChild != NULL)
	{
		return true; //At least one child exists

	} else
	{
		return false;

	}
}


/**
*	@brief Sets this node's left child to the sent node
*
*	@details Sets the leftChild pointer to the sent RedBlackNode pointer.
*
*	@par Algorithm None.
*
*	@param[in] newChild The RedBlackNode to assign as the left child.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void RedBlackNode<itemType>::SetLeftChild (RedBlackNode* newChild)
{
	leftChild = newChild;

	return;

}

/**
*	@brief Sets this node's right child to the sent node
*
*	@details Sets the rightChild pointer to the sent RedBlackNode pointer.
*
*	@par Algorithm None.
*
*	@param[in] newChild The RedBlackNode to assign as the right child.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void RedBlackNode<itemType>::SetRightChild (RedBlackNode* newChild)
{
	rightChild = newChild;

	return;

}


/**
*	@brief Sets this node's left child color to the sent color
*
*	@details Sets the leftChild color to the sent color
*
*	@par Algorithm None.
*
*	@param[in] color The color to set the child to
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void RedBlackNode<itemType>::SetLeftColor (char color)
{
	if (color == 'R' || color == 'B')
	{
		leftColor = color;

	} else
	{
		cout << "Error: SetLeftColor recieved invalid color: " << color << endl;

	}

	return;

}

/**
*	@brief Sets this node's right child color to the sent color
*
*	@details Sets the rightChild color to the sent color
*
*	@par Algorithm None.
*
*	@param[in] color The color to set the child to
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void RedBlackNode<itemType>::SetRightColor (char color)
{
	if (color == 'R' || color == 'B')
	{
		rightColor = color;

	} else
	{
		cout << "Error: SetRightColor recieved invalid color: " << color << endl;

	}

	return;

}

/**
*	@brief Sets this node's stored value to the sent value
*
*	@details Sets the node's value to the value sent as an argument.
*
*	@par Algorithm None.
*
*	@param[in] newValue The new value to store in the node.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void RedBlackNode<itemType>::SetValue (itemType newValue)
{
	value = newValue; //If non-standard data type then an operator= overload is needed

	return;

}

/**
*	@brief Gets the address of the left child
*
*	@details Returns the pointer stored in leftChild
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns a pointer to the left child node.
*
*	@note None.
*
*/
template<class itemType>
RedBlackNode<itemType>* RedBlackNode<itemType>::GetLeftChild ()
{
	return leftChild;

}

/**
*	@brief Gets the address of the right child
*
*	@details Returns the pointer stored in rightChild
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns a pointer to the right child node.
*
*	@note None.
*
*/
template<class itemType>
RedBlackNode<itemType>* RedBlackNode<itemType>::GetRightChild ()
{
	return rightChild;

}

/**
*	@brief Gets this node's value
*
*	@details Gets the value stored in this node.
*
*	@par Algorithm None.
*
*	@param[in] None.
*
*	@param[out] None.
*
*	@return Returns the value stored in this node.
*
*	@note None.
*
*/
template<class itemType>
itemType RedBlackNode<itemType>::GetValue ()
{
	return value;

}