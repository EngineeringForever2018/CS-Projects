#include <iostream>

using namespace std;

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr( nullptr)
{
} // end default constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{
 rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
} // end constructor


template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
 BinaryNode<ItemType>* newTreePtr = nullptr;
// Copy tree nodes during a preorder traversal
 newTreePtr = new BinaryNode<ItemType>(tree.rootPtr->getItem(), nullptr, nullptr);
 newTreePtr->setLeftChildPtr(copyTree(tree.rootPtr->getLeftChildPtr()));
 newTreePtr->setRightChildPtr(copyTree(tree.rootPtr->getRightChildPtr()));
 rootPtr = newTreePtr;
  // end if
// Else tree is empty (newTreePtr is nullptr)
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
     if (rootPtr != nullptr) {
       destroyTree(rootPtr->getLeftChildPtr());
       destroyTree(rootPtr->getRightChildPtr());
       rootPtr = nullptr;
     } // end if
} // end destroyTree

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
  if (rootPtr == nullptr) {
     return 0;
  }
  else {
    return 1 + max(getHeight(rootPtr->getLeftChildPtr()),
    getHeight(rootPtr->getRightChildPtr()));
  }
} // end getHeightHelper

template<class ItemType>
bool BinarySearchTree<ItemType>::add( const ItemType& newData)
{
 BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
 rootPtr = insertInorder(rootPtr, newNodePtr);
 return true;
} // end add



template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  if (rootPtr != nullptr) {
    inorder(visit, rootPtr->getLeftChildPtr());
    ItemType theItem = rootPtr->getItem();
    visit(theItem);
    inorder(visit, rootPtr->getRightChildPtr());
  } // end if
} // end inorder

template<class ItemType>
void BinarySearchTree<ItemType>::insert(ItemType &put, BinaryNode<ItemType> &node) {
   if(node == nullptr) {
     BinaryNode<ItemType> number = new BinaryNode<ItemType> (put);
     node = number;
     return;
   }
   else {
     if(put < node -> getItem()) {
       insert(put, node -> getLeftChildPtr());
     }
     else {
       insert(put, node -> getRightChildPtr());
     } //eventually it would hit Null and then insert the NULL there
   }
}
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
  if (rootPtr != nullptr) {
    preorder(visit, rootPtr->getLeftChildPtr());
    ItemType theItem = rootPtr->getItem();
    visit(theItem);
    preorder(visit, rootPtr->getRightChildPtr());
  } // end if
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
  if (rootPtr != nullptr) {
    postorder(visit, rootPtr->getLeftChildPtr());
    ItemType theItem = rootPtr->getItem();
    visit(theItem);
    postorder(visit, rootPtr->getRightChildPtr());
  } // end if
}

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide) {

}

//Locates the node in the binary search tree top which treePtr points that
//contains the value target. Returns either a pointer to the located node or
//nullptr if such a node isn't found.
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const {
    if(treePtr == nullptr) {
      return nullptr; //Not found
    }
    else if(treePtr->getItem() == target) {
      return treePtr; //Found
    }
    else if(treePtr->getItem() > target) {
      //Search left subtree
      return findNode(treePtr->getLeftChildPtr(), target);
    }
    else {
      //Search right subtree
      return findNode(treePtr->getRightChildPtr(), target);
    }
}

//Removes the item in the node, N,. to which nodePtr points.
//Returns a pointer to the node at this tree location after node N is deleted.
template<class ItemType>
void BinarySearchTree<ItemType>::removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr) {
   BinaryNode<ItemType> node;
   if()
}

//Removes the leftmost node in the left subtree of the node pointed to by nodePtr.
//Sets inorderSuccessor to the value in this node.
//Returns a pointer to the revised subtree.
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr, ItemType& inorderSuccessor) {
   if(subTreePtr->getLeftChildPtr() == nullptr) {
     //This is the node you want; it has no left child, but it might have a right subtree
     inorderSuccessor = subTreePtr->getItem();
     return removeNode(subTreePtr);
   }
   else {
     return removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor);
   }
}

template<class ItemType>
void BinarySearchTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& isSuccessful) {

}

//Removes the given data fron the binary search tree.
template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target) {
    bool success = false;
    rootPtr = removeValue(rootPtr, target, success);
    return success;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear() {

}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const {

}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const {
  bool information = false;
  findNode(rootPtr, anEntry, information);
  return information;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {

}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const {

}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData) {

}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {

}

void BinarySearchTree<ItemType>::show(int x) {
  cout << x << ;
}
