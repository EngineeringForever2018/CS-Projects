/** Link-based implementation of the ADT binary search tree.
@file BinarySearchTree.h */
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include <memory>
#include <iostream>
#include <exception>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class BinarySearchTree : public BinaryNode<ItemType>
{
private:
 BinaryNode<ItemType>* rootPtr;
protected:
 //------------------------------------------------------------
 // Protected Utility Methods Section:
 // Recursive helper methods for the public methods.
 //------------------------------------------------------------

 BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode);

 // Removes the given target value from the tree while maintaining a
 // binary search tree.
 BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);

 // Removes a given node from a tree while maintaining a binary search tree.
 BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);

 // Removes the leftmost node in the left subtree of the node
 // pointed to by nodePtr.
 // Sets inorderSuccessor to the value in this node.
 // Returns a pointer to the revised subtree.
 BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor);

 // Returns a pointer to the node containing the given value,
 // or nullptr if not found.
 BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target) const;
 // Recursively deletes all nodes from the tree.
 void destroyTree(BinaryNode<ItemType>* subTreePtr);
 int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
 // Recursive traversal helper methods:
 void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
 void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
 void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

public:
 //------------------------------------------------------------
 // Constructor and Destructor Section.
 //------------------------------------------------------------
 BinarySearchTree();
 BinarySearchTree(const ItemType& rootItem);
 BinarySearchTree(const BinarySearchTree<ItemType>& tree);
 virtual ~BinarySearchTree();

 //------------------------------------------------------------
 // Public Methods Section.
 //------------------------------------------------------------
 bool isEmpty() const;
 int getHeight() const;
 int getNumberOfNodes() const;
 ItemType getRootData() const throw(PrecondViolatedExcept);
 void setRootData(const ItemType& newData) const throw(PrecondViolatedExcept);
 bool add(const ItemType& newEntry);
 bool remove(const ItemType& anEntry);
 void clear();
 ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
 bool contains(const ItemType& anEntry) const;

 //------------------------------------------------------------
 // Public Traversals Section.
 //------------------------------------------------------------
 void preorderTraverse(void visit(ItemType &)) const;
 void inorderTraverse(void visit(ItemType &)) const;
 void postorderTraverse(void visit(ItemType &)) const;

 //------------------------------------------------------------
 // Overloaded Operator Section.
 //------------------------------------------------------------
 BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"
#endif
