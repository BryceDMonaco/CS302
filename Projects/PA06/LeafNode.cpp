/**
*	@file LeafNode.cpp
*
*	@brief This is the header and implmentation of LeafNode
*
*	@author Bryce Monaco
*
*	@details This file contains the header and implementation of LeafNode
*
*	@version 1.0
*
*	@note Header and implementation are in one file to fix some templating issues.
*/

#include <iostream>

using namespace std;

template<class itemType>
class LeafNode
{
	public:
		LeafNode ();
		LeafNode (itemType newValue, bool setIsRoot);
		~LeafNode ();

		bool IsLeftClear ();
		bool IsRightClear ();
		bool IsRootNode ();
		bool HasChildren ();

		void SetLeftChild (LeafNode* newChild);
		void SetRightChild (LeafNode* newChild);
		void SetValue (itemType newValue);

		LeafNode* GetLeftChild ();
		LeafNode* GetRightChild ();
		itemType GetValue ();

	private:
		LeafNode* leftChild;
		LeafNode* rightChild;

		itemType value;

		bool isRoot;

};

/////////////////////////////////////////////////////////////////////////////////
///////////// 					End Header File 					/////////////
/////////////////////////////////////////////////////////////////////////////////


/**
*	@brief The default constructor of a LeafNode object
*
*	@details This constructor initializes values of a LeafNode object to default values
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
LeafNode<itemType>::LeafNode ()
{
	leftChild = NULL;
	rightChild = NULL;

	isRoot = false;

}

/**
*	@brief The parameterized constructor of a LeafNode object
*
*	@details This constructor initializes values of a LeafNode object to sent values
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
LeafNode<itemType>::LeafNode (itemType newValue, bool setIsRoot)
{
	leftChild = NULL;
	rightChild = NULL;

	value = newValue;

	isRoot = setIsRoot;

}

/**
*	@brief The destructor of a LeafNode object
*
*	@details Removes a LeafNode from memory.
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
LeafNode<itemType>::~LeafNode ()
{
	//Nada

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
bool LeafNode<itemType>::IsLeftClear ()
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
bool LeafNode<itemType>::IsRightClear ()
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
bool LeafNode<itemType>::IsRootNode ()
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
bool LeafNode<itemType>::HasChildren ()
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
*	@details Sets the leftChild pointer to the sent LeafNode pointer.
*
*	@par Algorithm None.
*
*	@param[in] newChild The LeafNode to assign as the left child.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void LeafNode<itemType>::SetLeftChild (LeafNode* newChild)
{
	leftChild = newChild;

	return;

}

/**
*	@brief Sets this node's right child to the sent node
*
*	@details Sets the rightChild pointer to the sent LeafNode pointer.
*
*	@par Algorithm None.
*
*	@param[in] newChild The LeafNode to assign as the right child.
*
*	@param[out] None.
*
*	@return None.
*
*	@note None.
*
*/
template<class itemType>
void LeafNode<itemType>::SetRightChild (LeafNode* newChild)
{
	rightChild = newChild;

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
void LeafNode<itemType>::SetValue (itemType newValue)
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
LeafNode<itemType>* LeafNode<itemType>::GetLeftChild ()
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
LeafNode<itemType>* LeafNode<itemType>::GetRightChild ()
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
itemType LeafNode<itemType>::GetValue ()
{
	return value;

}