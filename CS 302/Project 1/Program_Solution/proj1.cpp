/*
 CS 302 Project 1 - LinkedList class
 By: Jared Lam (jaredlam@nevada.unr.edu)
 2/3/19
*/
/*
This is for linked list Project which has menu for the user to choose what they
want to do with the data.
*/

#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"

using namespace std;

int main() {

  int choice, array;
  LinkedList<int> items;

  while(1) {
    cout << "Options: " << endl;
    cout << "1 - Adding a new item" << endl;
    cout << "2 - Delete an item" << endl;
    cout << "3 - Show the number of items" << endl;
    cout << "4 - Show all items" << endl;
    cout << "5 - Exit the program" << endl;
    cout << "Please enter your option: " << endl;
    cin >> choice;
    switch(choice) {
      case 1:
         cout << "Enter a number: ";
         cin >> array;
         items.push(array);
         break;
      case 2:
         items.pop();
         break;
      case 3:
         cout << "The size of the linked list is: " << items.length() << endl;
         break;
      case 4:
         items.show();
         break;
      case 5:
         return 0;
         break;
      default:
         cout << "Invalid option" << endl;
         break;
    }
  }
  return 0;
}
