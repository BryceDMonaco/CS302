//LinkedList.h

/**
 * @file LinkedList.h
 *
 * @brief This is the header file for the linked list class
 * 
 * @author Bryce Monaco
 * 
 * @details Lists the various components of the LinkedList class
 *
 * @version 1.0
 *
 * @Note Adapted from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 *		 Listing 9-2
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifndef LINKED_LIST_
#define LINKED_LIST_

#endif

#include "ListInterface.h"
#include "Node.cpp"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; //Points to the first node in the list

	int itemCount; //Counts the amount of objects in the list

	//@pre position is the number of the desired node; position >= 1 and position <= itemCount.
	//@post The node is found and a pointer to it is returned.
	//@param position is the number of the node to locate.
	//@return A pointer to the node at the given position.

	Node<ItemType>* getNodeAt (int position) const;

public:

	//@pre None
	//@post The List is created
	//@param None
	//@return None

	LinkedList();

	//@pre aList is the list to copy
	//@post A new list is made as a copy of another
	//@param aList  A currently existing list which will be copied
	//@return None

	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();

	//@pre None
	//@post None
	//@param None
	//@return Returns if the list is empty or not

	bool isEmpty() const;

	//@pre None
	//@post None
	//@param None
	//@return The length of the list, the number of nodes within the list

	int getLength() const;

	//@pre newPosition is the number of the desired node; newEntry is the value to be stored
	//@post The node is placed at the position with the value
	//@param newPosition  The position of the new node
	//@param newEntry  The value to be stored
	//@return Returns true if the node could be created, false otherwise.

	bool insert(int newPosition, const ItemType& newEntry);

	//@pre position is the number of the desired node; position >= 1 and position <= itemCount.
	//@post The node is found and removed from the list
	//@param position  The number of the node to locate.
	//@return True if the node could be removed, false otherwise.

	bool remove(int position);

	//@pre None
	//@post The entire list is erased and emptied.
	//@param None
	//@return None

	void clear();

	/** @throw PrecondViolatedExcept if position < 1 or position > getLength().
	*/

	//@pre position is the number of the desired node; position >= 1 and position <= itemCount.
	//@post The node is found and the value it holds its returned
	//@param position is the number of the node to locate.
	//@return The value of the desired node

	ItemType getEntry(int position) const throw(PrecondViolatedExcept);

	/** @throw PrecondViolatedExcept if position < 1 or position > getLength().
	*/

	//bool replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept);

};

#include "LinkedList.cpp"
#endif