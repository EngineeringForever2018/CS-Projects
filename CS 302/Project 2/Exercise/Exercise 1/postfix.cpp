//Create a menu for this Excerise using one of the StackArray or StackLinked
//Project 2 by Jared Lam
//CS 302 2/13/19
#include <iostream>
#include <string>
#include "StackArray.h"

using namespace std;

int main() {
  StackArray<float> position;
  char temp = ' ';
  cout << "Enter your equation: ";
  while(temp != '\n') {
    cin.get(temp);
    if(temp >= '0' && temp <= '9') {
      position.push(temp - '0'); // Transfer char to int
     // position.showStructure();
    }
    if(temp == '+' || temp == '-' || temp == '*' || temp == '/') {
      float operand1 = position.pop();
      float operand2 = position.pop();
      if(temp == '+') {
        position.push(operand2 + operand1);
      }
      if(temp == '-') {
        position.push(operand2 - operand1);
      }
      if(temp == '*') {
        position.push(operand2 * operand1);
      }
      if(temp == '/') {
        position.push(operand2 / operand1);
      }

    }
  }
  cout << position.pop() << endl;
}
