#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include <iostream>

//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
   if (subTreePtr == nullptr)
      return 0;
   else
      return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                     getHeightHelper(subTreePtr->getRightChildPtr()));
}  // end getHeightHelper

template<class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
   if (subTreePtr == nullptr)
      return 0;
   else
      return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())
               + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}  // end getNumberOfNodesHelper

template<class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                           std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
   if (subTreePtr == nullptr)
      return newNodePtr;
   else
   {
      auto leftPtr = subTreePtr->getLeftChildPtr();
      auto rightPtr = subTreePtr->getRightChildPtr();

      if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
      {
         rightPtr = balancedAdd(rightPtr , newNodePtr);
         subTreePtr->setRightChildPtr(rightPtr );
      }
      else
      {
         leftPtr = balancedAdd(leftPtr, newNodePtr);
         subTreePtr->setLeftChildPtr(leftPtr);
      }  // end if

      return subTreePtr;
   }  // end if
}  // end balancedAdd

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
   auto  leftPtr = subTreePtr->getLeftChildPtr();
   auto  rightPtr = subTreePtr->getRightChildPtr();
   int leftHeight = getHeightHelper(leftPtr);
   int rightHeight = getHeightHelper(rightPtr);
   if (leftHeight > rightHeight)
   {
      subTreePtr->setItem(leftPtr->getItem());
      leftPtr = moveValuesUpTree(leftPtr);
      subTreePtr->setLeftChildPtr(leftPtr);
      return subTreePtr;
   }
   else
   {
      if (rightPtr != nullptr)
      {
         subTreePtr->setItem(rightPtr->getItem());
         rightPtr =moveValuesUpTree(rightPtr);
         subTreePtr->setRightChildPtr(rightPtr);
         return subTreePtr;
      }
      else
      {
         //this was a leaf!
         // value not important
         return nullptr;
      }  // end if
   }  // end if
}  // end moveValuesUpTree

/** Depth-first search of tree for item.
 @param subTreePtr  tree to search.
 @param target  target item to find.
 @param success  communicate to client we found it.
 @returns  A pointer to node containing the item. */
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                                            const ItemType target,
                                                            bool& success)
{
   if(subTreePtr == nullptr) // not found here
      return subTreePtr;

   if (subTreePtr->getItem() == target) // found it
   {
      subTreePtr = moveValuesUpTree(subTreePtr);
      success = true;
      return subTreePtr;
   }
   else
   {
      auto targetNodePtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
      subTreePtr->setLeftChildPtr(targetNodePtr);
      if (!success) // no need to search right subTree
      {
         targetNodePtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
         subTreePtr->setRightChildPtr(targetNodePtr);
      }  // end if

      return subTreePtr;
   }  // end if
}  // end removeValue

template<class ItemType>
auto BinaryNodeTree<ItemType>::findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                                                                  const ItemType& target,
                                                                  bool& success) const
{
   if (treePtr == nullptr) // not found here
      return treePtr;

   if (treePtr->getItem() == target) // found it
   {
      success = true;
      return treePtr;
   }
   else
   {
      std::shared_ptr<BinaryNode<ItemType>> targetNodePtr = findNode(treePtr->getLeftChildPtr(), target, success);
      if (!success) // no need to search right subTree
      {
         targetNodePtr = findNode(treePtr->getRightChildPtr(), target, success);
      }  // end if

      return targetNodePtr;
   }  // end if
}  // end findNode

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinaryNodeTree<ItemType>::copyTree(const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const
{
   std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

   // Copy tree nodes during a preorder traversal
   if (oldTreeRootPtr != nullptr)
   {
      // Copy node
      newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(), nullptr, nullptr);
	   newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
      newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
   }  // end if

   return newTreePtr;
}  // end copyTree

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
   if (subTreePtr != nullptr)
   {
      destroyTree(subTreePtr->getLeftChildPtr());
      destroyTree(subTreePtr->getRightChildPtr());
      subTreePtr.reset(); // decrement reference count to node
   }  // end if
}  // end destroyTree

//////////////////////////////////////////////////////////////
//      Protected Tree Traversal Sub-Section
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      ItemType theItem = treePtr->getItem();
      visit(theItem);
//      visit(treePtr->getItem());
      preorder(visit, treePtr->getLeftChildPtr());
      preorder(visit, treePtr->getRightChildPtr());
   }  // end if
}  // end preorder

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      inorder(visit, treePtr->getLeftChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);
      inorder(visit, treePtr->getRightChildPtr());
   }  // end if
}  // end inorder

template<class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      postorder(visit, treePtr->getLeftChildPtr());
      postorder(visit, treePtr->getRightChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);
   } // end if
}  // end postorder
