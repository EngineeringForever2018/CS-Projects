#include <iostream>

using namespace std;

template< class ItemType>
BinaryNode<ItemType>::BinaryNode() {
  leftChildPtr = NULL;
  rightChildPtr = NULL;
  item = 0;
}

template< class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) {
  //data assigned, set left and right to null
  item = anItem;
  leftChildPtr = NULL;
  rightChildPtr = NULL;
}

template< class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr) {
  //data assigned, set left and right pointer to specificed trees
  item = anItem;
  leftChildPtr = leftPtr;
  rightChildPtr = rightPtr;
} //end constructor

//Sets the data stored by the node to the specified value.
template< class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem) {
  item = anItem;
}

//Returns the data stored in the node's list data memeber.
template< class ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
  return item;
}

//Checks to see if the node is a leaf.
template< class ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
  if(leftChildPtr == NULL) {
    if(rightChildPtr == NULL) {
      return true;
    }
    return false;
  }
  else {
    return false;
  }
}

//BinaryNode getLeftChildPtr function
template< class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
  return leftChildPtr;
} //end getLeftChildPtr

//BinaryNode getRightChildPtr function
template< class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
  return rightChildPtr;
} //end getRightChildPtr

//BinaryNode setLeftChildPtr function
template< class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr) {
  leftChildPtr = leftPtr;
}

//BinaryNode setRightChildPtr function
template< class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr) {
  rightChildPtr = rightPtr;
}
