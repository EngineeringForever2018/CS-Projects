#include <iostream>

using namespace std;

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr) {
  if(subTreePtr == nullptr) {
    return newNodePtr;
  }
  else if(subTreePtr -> getItem() > newNodePtr -> getItem()) {
    subTreePtr -> setLeftChildPtr(insertInorder(subTreePtr -> getLeftChildPtr(), newNodePtr));
  }
  else {
    subTreePtr -> setRightChildPtr(insertInorder(subTreePtr -> getRightChildPtr(), newNodePtr));
  }
  return subTreePtr;
}

//Removes the given target from the binary search tree to which subTreePtr points.
//Returns a pointer to the node at this tree location after the value is removed.
//Sets success to true if the removal is successful, otherwise false
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success) {
   if(subTreePtr == nullptr) {
     success = false;
     return nullptr;
   }
   if(subTreePtr -> getItem() == target) {
     //Item is in the root of some subtree
     subTreePtr = removeNode(subTreePtr); //Remove the Item
     success = true;
     return subTreePtr;
   }
   if(subTreePtr -> getItem() > target) {
     //Search left subtree
     subTreePtr -> setLeftChildPtr(removeValue(subTreePtr -> getLeftChildPtr(), target, success));
     return subTreePtr;
   }
   else {
     //Search right subtree
     subTreePtr -> setRightChildPtr(removeValue(subTreePtr -> getRightChildPtr(), target, success));
     return subTreePtr;
   }
}

//Removes the item in the node to which nodePtr points.
//Returns a pointer to the node at this tree location after node nodePtr is deleted.
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr) {
   if(nodePtr -> isLeaf()) {
     delete nodePtr;
     nodePtr = nullptr;
     return nodePtr;
   }
   if((nodePtr -> getLeftChildPtr() == nullptr) && (nodePtr -> getRightChildPtr() != nullptr)) {
     BinaryNode<ItemType>* node_connection = nodePtr -> getRightChildPtr();
     delete nodePtr;
     nodePtr = nullptr; //when delete it we always set it equal to NULL/nullptr
     return node_connection;
   }
   if((nodePtr -> getLeftChildPtr() != nullptr) && (nodePtr -> getRightChildPtr()== nullptr)) {
     BinaryNode<ItemType>* node_connection = nodePtr -> getLeftChildPtr();
     delete nodePtr;
     nodePtr = nullptr;
     return node_connection;
   }
   else { //nodePtr has 2 children
     // Find the inorder successor of the entry in nodePtr: it is in the left subtree rooted at nodePtr right child
     ItemType newNodeValue;
     nodePtr -> setRightChildPtr(removeLeftmostNode(nodePtr -> getRightChildPtr(), newNodeValue));
     nodePtr -> setItem(newNodeValue);
     return nodePtr;
   }
}

//Removes the leftmost node in the left subtree of the node pointed to by nodePtr.
//Sets inorderSuccessor to the value in this node.
//Returns a pointer to the revised subtree.
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor) {
   BinaryNode<ItemType>* tempPtr;
   if(subTreePtr->getLeftChildPtr() == nullptr) {
     //This is the node you want; it has no left child, but it might have a right subtree
     inorderSuccessor = subTreePtr->getItem();
     return removeNode(subTreePtr);
   }
   else {
     subTreePtr -> setLeftChildPtr(removeLeftmostNode(subTreePtr -> getLeftChildPtr(), inorderSuccessor));
     return subTreePtr;
   }
}

//Locates the node in the binary search tree top which treePtr points that
//contains the value target. Returns either a pointer to the located node or
//nullptr if such a node isn't found.
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, const ItemType& target) const {
    if(treePtr == nullptr) {
      return nullptr; //Not found
    }
    else if(treePtr -> getItem() == target) {
      return treePtr; //Found
    }
    else if(treePtr -> getItem() > target) {
      //Search left subtree
      return findNode(treePtr -> getLeftChildPtr(), target);
    }
    else {
      //Search right subtree
      return findNode(treePtr -> getRightChildPtr(), target);
    }
}

//Deallocate all dynamic memory for nodes in the tree.
template<class ItemType>
void BinarySearchTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr) {
  if(subTreePtr != nullptr) {
    destroyTree(subTreePtr -> getLeftChildPtr());
    destroyTree(subTreePtr -> getRightChildPtr());
    delete subTreePtr;
  } //end if
} //end destroyTree

//Find height of the tree. We use recursion to find height of the tree.
template <class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const {
  if(subTreePtr == nullptr) {
    return 0;
  }
  else {
    return (1 + max(getHeightHelper(subTreePtr -> getLeftChildPtr()), getHeightHelper(subTreePtr -> getRightChildPtr())));
  }

} //end getHeightHelper

//Visit the roots, then first, and lastly right. Then perform the action based on the user's vist function
//we used recursion to visit the entire tree.
template<class ItemType>
void BinarySearchTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
  if (treePtr != nullptr) {
    ItemType theItem = treePtr -> getItem();
    visit(theItem);
    preorder(visit, treePtr -> getLeftChildPtr());
    preorder(visit, treePtr -> getRightChildPtr());
  } // end if
} // end preorder

//Visit left, then root, lastly right to perform the action based on the user's vist function
template<class ItemType>
void BinarySearchTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
  if (treePtr != nullptr) {
    inorder(visit, treePtr -> getLeftChildPtr());
    ItemType theItem = treePtr -> getItem();
    visit(theItem);
    inorder(visit, treePtr -> getRightChildPtr());
  } // end if
} // end inorder

//Visit left, then right, lastly root to perform the action based on the user's vist function
template<class ItemType>
void BinarySearchTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
  if (treePtr != nullptr) {
    postorder(visit, treePtr -> getLeftChildPtr());
    postorder(visit, treePtr -> getRightChildPtr());
    ItemType theItem = treePtr -> getItem();
    visit(theItem);
  } // end if
} // end inorder

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr( nullptr)
{
} // end default constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) {
 rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
} // end constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
 rootPtr = this -> copyTree(tree.rootPtr);
} //end copy constructor

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
  this -> destroyTree(rootPtr);
} // end destroyTree

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
  return rootPtr == nullptr;
}

//Deteremine the height of the tree. Uses recursion to find the total height.
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
  return this -> getHeightHelper(rootPtr);
} // end getHeight

//Determine the number of nodes in the tree. Uses recursion to find the total number of number_of_nodes.
template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
   return this -> getNumberOfNodesHelper(rootPtr);
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw(PrecondViolatedExcept) {
  if(isEmpty()) {
    throw PrecondViolatedExcept("getRootData() called empty tree.");
  }
  return rootPtr -> getItem();
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData) const throw(PrecondViolatedExcept) {
  throw PrecondViolatedExcept("We can't do anything with the root value in BST!");
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{
   BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType> (newEntry);
   rootPtr = insertInorder(rootPtr, newNodePtr);
   return true;
} // end add

//Removes the given data fron the binary search tree.
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& anEntry) {
    bool success = false;
    rootPtr = removeValue(rootPtr, anEntry, success);
    return success;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear() {
  this -> destroyTree(rootPtr);
  rootPtr == nullptr;   //There isn't any information at all
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw(NotFoundException) {
  BinaryNode<ItemType>* tempPtr = findNode(rootPtr, anEntry);
  if ( tempPtr != nullptr ) {
    return tempPtr -> getItem();
  }
  else {
    throw NotFoundException("The item can't be found in the tree.");
  }
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const {
  return findNode(rootPtr, anEntry);
}

//Goes through the root then left and lastly right to take action from user's visit function
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType &)) const {
  preorder(visit, rootPtr); //Used the preorder function to help theses function
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType &)) const {
  inorder(visit, rootPtr); //Used the inorder function to help theses function
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType &)) const {
  postorder(visit, rootPtr); //Used the postorder function to help theses function
}

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide) {
  //Copy tree nodes during a preorder traversal
  if(!isEmpty()) {
    clear();
  }
  this = copyTree(&rightHandSide);
  return *this;
} //end operator=
