//Implementation for StackArray
#include <iostream>

using namespace std;

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber) {
  top = 0;
  dataItems = new DataType[maxNumber];
}

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other) {
  top = other.top;
   for(size_t m = 0; m < top; m++) {
     dataItems[m] = other.dataItems[m];
   }
}

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray<DataType>& other) {
  top = other.top;
  for(size_t e = 0; e < top; e++) {
    dataItems[e] = other.dataItems[e];
  }
  return *this;
}

template <typename DataType>
StackArray<DataType>::~StackArray() {
  clear();
}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error) {
   dataItems[top] = newDataItem;
   top++;
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
