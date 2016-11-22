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

template<class itemType>
LeafNode<itemType>::LeafNode ()
{
	leftChild = NULL;
	rightChild = NULL;

	isRoot = false;

}

template<class itemType>
LeafNode<itemType>::LeafNode (itemType newValue, bool setIsRoot)
{
	leftChild = NULL;
	rightChild = NULL;

	value = newValue;

	isRoot = setIsRoot;

}

template<class itemType>
LeafNode<itemType>::~LeafNode ()
{
	//Nada

}

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

template<class itemType>
bool LeafNode<itemType>::IsRootNode ()
{
	return isRoot;

}

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

template<class itemType>
void LeafNode<itemType>::SetLeftChild (LeafNode* newChild)
{
	leftChild = newChild;

	return;

}

template<class itemType>
void LeafNode<itemType>::SetRightChild (LeafNode* newChild)
{
	rightChild = newChild;

	return;

}

template<class itemType>
void LeafNode<itemType>::SetValue (itemType newValue)
{
	value = newValue; //If non-standard data type then an operator= overload is needed

	return;

}

template<class itemType>
LeafNode<itemType>* LeafNode<itemType>::GetLeftChild ()
{
	return leftChild;

}

template<class itemType>
LeafNode<itemType>* LeafNode<itemType>::GetRightChild ()
{
	return rightChild;

}

template<class itemType>
itemType LeafNode<itemType>::GetValue ()
{
	return value;

}