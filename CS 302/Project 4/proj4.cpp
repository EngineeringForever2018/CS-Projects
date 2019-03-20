//CS 302 Project 4 by Jared Lam (jaredlam@nevada.unr.edu) 3/11/19
#include <iostream>
#include <cstdlib> //rand
#include <ctime>
#include <fstream>
#include "BinarySearchTree.h"

using namespace std;

const int NUMBER_VALUE = 100;
template <class ItemType>
void visit(ItemType& value);

int main() {
  srand(time(NULL)); //seed random
  int temp;
  BinarySearchTree<int> tree;
  int count[200] = {0};
  //fstream files;
  //files.open("unique_random_numbers.txt");
  //print the title
  cout << "C++ Binary Search Tree Program" << endl;
  //Generate 100 random values, put it into tree1 array
  cout << "Generating 100 unique random vakues from 1 - 200" << endl;
  cout << "The unique random values are: " << endl;
  for(int i = 0; i < NUMBER_VALUE; i++) {
    temp = (rand() % 200) + 1;
    if(count[temp - 1] == 0) {
      tree.add(temp);
      count[temp - 1] = 1;
    }
    else {
      i--;
    }

  }
  //print the height of the tree
  cout << "The height of Binary Seacrch Tree is: " << tree.getHeight() << endl;
  //print the preorder output of Binary Search Tree
  cout << "Binary Search Tree for preorder is: " << endl;
  tree.preorderTraverse(visit);
  cout << endl;
  //print the inorder output of Binary Search Tree
  cout << "Binary Search Tree for inorder is: " << endl;
  tree.inorderTraverse(visit);
  cout << endl;
  //print the postorder output of Binary Search Tree
  cout << "Binary Search Tree for postorder is: " << endl;
  tree.postorderTraverse(visit);
  cout << endl;

  return 0;
}

template <class ItemType>
void visit(ItemType& value) {
  cout << value << ' ';
}
