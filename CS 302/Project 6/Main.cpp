//This is Jared Lam CS 302 Project 6 4/19/19
#include "LeftLeaningRedBlack.h"
#include <ctime>
#include <cstdlib> //rand

using namespace std;

const int NUMBER_VALUE = 10;

int main() {
  VoidRef_t temp;
	LeftLeaningRedBlack tree;
  bool* IsRed;
	for(int i = 0; i < NUMBER_VALUE; i++) {
		temp.Key = i;
		temp.pContext = new int;
		*((int*) (temp.pContext)) = rand() % 100 + 1;
		cout << "Random number: " << *((int*)(temp.pContext)) << endl;
		cout << "Print the keys: "<< i << endl; //to print the keys
		tree.Insert(temp, IsRed); //we need the color for the tree
		cout << *IsRed << endl; //to print out which color is number at
	}
		tree.Delete(3);
		cout << "Red-black Tree" << endl;
		for(int i = 0; i < NUMBER_VALUE; i++) {
			if(i != 3) {
				cout << "Random number: "<< *((int*)tree.LookUp(i)) << endl;
				cout << "Print the keys: "<< i << endl; //to print the keys
			}
		}
	return 0;
}
