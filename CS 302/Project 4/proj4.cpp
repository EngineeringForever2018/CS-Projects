#include <iostream>
#include <cstdlib> //rand
#include <fstream>
#include <ctime>
#include "BinarySearchTree.h"

using namespace std;

int main() {
  srand(time(NULL)); //seed random
  int temp;
  int number[100];
  int number2[10];
  fstream files;
  files.open("unique_random_numbers.txt");
  BinarySearchTree<int> tree;
  for(int i = 0; i < 100; i++) {
    temp = rand() % 200 + 1;
    tree.add(temp);
  }
  cout << "The height is: " << tree.getHeight() << endl;
  tree.preorderTraverse();
  tree.inorderTraverse();
  tree.postorderTraverse();
  return 0;
}
