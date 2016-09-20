//Node.cpp

/**
 * @file Node.cpp
 *
 * @brief This is the implementation file for the Node class
 * 
 * @author Bryce Monaco
 * 
 * @details Implements the various components of the Node class
 *
 * @version 1.0
 *
 * @Note Adapted from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 *		 Listing 4-2
 */

 #ifndef NODE_CPP
 #define NODE_CPP

 #include "Node.h"

 template<class ItemType>
 Node<ItemType> :: Node () : next(nullptr)
 {


 }

 template<class ItemType>
 Node<ItemType> :: Node (const ItemType& anItem) : item(anItem), next(nullptr)
 {


 }

 template<class ItemType>
 Node<ItemType> :: Node (const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
 {


 }

 template<class ItemType>
 void Node<ItemType> :: setItem (const ItemType& anItem)
 {
 	item = anItem;

 }

 template<class ItemType>
 void Node<ItemType> :: setNext (Node<ItemType>* nextNodePtr)
 {
 	next = nextNodePtr;

 }

 template<class ItemType>
 ItemType Node<ItemType> :: getItem() const
 {
 	return item;

 }

 template<class ItemType>
 Node<ItemType>* Node<ItemType> :: getNext() const
 {
 	return next;

 }

 #endif