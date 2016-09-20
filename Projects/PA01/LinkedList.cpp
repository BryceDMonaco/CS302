//LinkedList.cpp

/**
 * @file LinkedList.cpp
 *
 * @brief This is the implementation file for the linked list class
 * 
 * @author Bryce Monaco
 * 
 * @details Implements the various components of the LinkedList class
 *
 * @version 1.0
 *
 * @Note Adapted from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 *		 Listing 9-2
 */

 #include "LinkedList.h"
 #include "Node.cpp"
 
 #ifndef LINKED_LIST_CPP
 #define LINKED_LIST_CPP

 template <class ItemType>
 LinkedList<ItemType> :: LinkedList () : headPtr(nullptr), itemCount(0)
 {

 }

 template <class ItemType>
 ItemType LinkedList<ItemType> :: getEntry (int position) const throw (PrecondViolatedExcept)
 {
 	bool ableToGet = (position >= 1) && (position <= itemCount);

 	if (ableToGet)
 	{
 		Node<ItemType>* nodePtr = getNodeAt(position);

 		return nodePtr -> getItem();

 	} else
 	{
 		std::string message = "getEntry() called within an empty list or ";
 		message = message + "invalid position.";

 		throw(PrecondViolatedExcept(message));

 	}
 }

 template<class ItemType>
 Node<ItemType>* LinkedList<ItemType> :: getNodeAt (int position) const
 {
 	//assert((position >= 1) && (position <= itemCount));

 	Node<ItemType>* curPtr = headPtr;

 	for (int skip = 1; skip < position; skip++)
 	{
 		curPtr = curPtr -> getNext();

 	}

 	return curPtr;

 }
 
 template<class ItemType>
 bool LinkedList<ItemType> :: isEmpty () const
 {
 	return itemCount == 0;

 }

 template<class ItemType>
 int LinkedList<ItemType> :: getLength () const
 {
 	return itemCount;

 }

 /*template<class ItemType>
 bool LinkedList<ItemType> :: replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept)
 {
 	return true;

 } */

//Constructor, insert, getentry, is empty, getlength 

 /*
 bool LinkedList<ItemType> :: insert(int newPosition, const ItemType& newEntry)
 {
 	Node<ItemType>* onPtr = headPtr;

 	for (int i = 0, i < newPosition, i++)
 	{
 		onPtr = onPtr -> getNext(); //Go to the next node

 	}

 	Node<ItemType>* prevPtr = onPtr;
 	node<ItemType>* curPtr = onPtr -> getNext();
 	Node<ItemType>* newNodePtr = new Node<ItemType>();
 	newNodePtr -> setItem (newEntry);

 	newNodePtr -> setNext(curPtr);
 	prevPtr -> setNext (newNodePtr);

 	prevPtr = setNext (curPtr);
 	curPtr	= prevPtr -> getNext();

 	newNodePtr -> setNext (curPtr);
 	prevPtr -> setNext (newNodePtr);

 	return true; 

 } */

#endif