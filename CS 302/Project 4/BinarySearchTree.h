/** Link-based implementation of the ADT binary search tree.
@file BinarySearchTree.h */
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include <memory>
#include <iostream>
#include <exception>
#include "BinaryNode.h"

template<class ItemType>
class BinarySearchTree : public BinaryNode<ItemType>
{
private:
 std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
 //------------------------------------------------------------
 // Protected Utility Methods Section:
 // Recursive helper methods for the public methods.
 //------------------------------------------------------------
 // Places a given new node at its proper position in this binary
 // search tree.
 void insert(ItemType &put, BinaryNode<ItemType> &node);

 // Removes the given target value from the tree while maintaining a
 // binary search tree.
 void removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool& isSuccessful);

 // Removes a given node from a tree while maintaining a binary search tree.
 void removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);

 // Removes the leftmost node in the left subtree of the node
 // pointed to by nodePtr.
 // Sets inorderSuccessor to the value in this node.
 // Returns a pointer to the revised subtree.
 BinaryNode<ItemType>* removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>>subTreePtr, ItemType& inorderSuccessor);

 // Returns a pointer to the node containing the given value,
 // or nullptr if not found.
 BinaryNode<ItemType>* findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType& target) const;

 // Copies the tree rooted at treePtr 

public:
 //------------------------------------------------------------
 // Constructor and Destructor Section.
 //------------------------------------------------------------
 BinarySearchTree();
 BinarySearchTree(const ItemType& rootItem);
 BinarySearchTree(const BinarySearchTree<ItemType>& tree);
 virtual ~BinarySearchTree();
 void destroyTree(BinaryNode<ItemType>* destroy);
 //------------------------------------------------------------
 // Public Methods Section.
 //------------------------------------------------------------
 bool isEmpty() const;
 int getHeight() const;
 int getNumberOfNodes() const;

 ItemType getRootData() const;
 void setRootData(const ItemType& newData);

 bool add(const ItemType& newEntry);
 bool remove(const ItemType& target);
 void clear();

 ItemType getEntry(const ItemType& anEntry) const;
 bool contains(const ItemType& anEntry) const;

 void show(int x);
 //------------------------------------------------------------
 // Public Traversals Section.
 //------------------------------------------------------------
 void preorderTraverse(void visit(ItemType&)) const;
 void inorderTraverse(void visit(ItemType&)) const;
 void postorderTraverse(void visit(ItemType&)) const;

 //------------------------------------------------------------
 // Overloaded Operator Section.
 //------------------------------------------------------------
 BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"
#endif
