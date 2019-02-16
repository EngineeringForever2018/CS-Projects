//Implementation for StackArray
//CS 302 Jared Lam 2/15/19
//Excerise 2 for Assignment 1 and 2
#include <iostream>

using namespace std;

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber) {
  top = 0;
  dataItems = new DataType[maxNumber];
}
//Copy Destuctor
//We make sure all the dataItems are somewhere safe so then we can used it
template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other) {
  top = other.top;
   for(size_t m = 0; m < top; m++) {
     dataItems[m] = other.dataItems[m];
   }
}
//Same thing as copy contructor
//We make sure we return the item
template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray<DataType>& other) {
  top = other.top;
  for(size_t e = 0; e < top; e++) {
    dataItems[e] = other.dataItems[e];
  }
  return *this;
}
//Destructor construtor
//Delete it once it is done
template <typename DataType>
StackArray<DataType>::~StackArray() {
  clear();
}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error) {
   dataItems[top++] = newDataItem;
}

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error) {
  if(isEmpty()) {
    throw(logic_error("Warning"));
  }
  else {
    --top;
    return dataItems[top];
  }
}

template <typename DataType>
void StackArray<DataType>::clear() {
  top = 0;
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const {
 if(top == 0) {
   return true;
 }
 else {
   return false;
 }
}

template <typename DataType>
bool StackArray<DataType>::isFull() const {
  if(top == StackArray<DataType>::MAX_STACK_SIZE - 1) {
     return true;
   }
   else {
     return false;
   }
}

template <typename DataType>
void StackArray<DataType>::showStructure() const {
  if(isEmpty()) {
    cout << "Empty stack" << endl;
  }
  else {
    for(int i = 0; i < top; i++) {
      cout << dataItems[i];
    }
    cout << endl;
  }
}
