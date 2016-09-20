//Node.h

/**
 * @file Node.h
 *
 * @brief This is the header file for the Node class
 * 
 * @author Bryce Monaco
 * 
 * @details Lists the various components of the Node class
 *
 * @version 1.0
 *
 * @Note Adapted from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 *		 Listing 4-1
 */

 #ifndef NODE_
 #define NODE_

 #endif

 #ifndef NODE_H
 #define NODE_H

 template<class ItemType>
 class Node
 {
 private:
 	ItemType item;
 	Node<ItemType> next;

 public:

	//@pre None
	//@post The node is created
	//@param None
	//@return None

 	Node();

	//@pre None
	//@post The node is created with the value
	//@param anItem  The value to be stored in the node
	//@return None

 	Node(const ItemType& anItem);

	//@pre None
	//@post None
	//@param anItem  The value to be stored in the node
	//@param nextNodePtr  The pointer to the next node in the list
	//@return None

 	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);

	//@pre anItem will replace the current value in the node
	//@post The new value in the node is anItem
	//@param anItem  The new value to be stored
	//@return None

 	void setItem(const ItemType& anItem);

	//@pre Used to set the next node pointer
	//@post The next node pointer is set to the sent node
	//@param nextNodePtr A pointer to the node that is meant to be next
	//@return None

 	void setNext(Node<ItemType>* nextNodePtr);

 	//@pre Used to return the value in a node
	//@post The value is returned
	//@param None
	//@return Returns the value stored in the node

 	ItemType getItem() const;

	//@pre Used to return the position in memory of the next node
	//@post A pointer to the next node is returned
	//@param None
	//@return Returns a pointer to the next node in the list, can be NULL if at the end

 	Node<ItemType>* getNext() const;

 };

 #include "Node.cpp"
 #endif