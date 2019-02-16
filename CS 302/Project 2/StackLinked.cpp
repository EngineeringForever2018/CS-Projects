//Implementation for StackLinked
#include <iostream>

using namespace std;

template <typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber) {
  top = NULL;
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked<DataType>& other) {
  if(other.top == NULL) {
    top = NULL;
  }
  else {
    top = new StackNode(other.top->dataItem, NULL);
    StackNode * src = other.top;
    StackNode * dest = top;
    while(src->next != NULL) {
      src = src -> next;
      dest -> next = new StackNode(src->dataItem, NULL);
      dest = dest -> next;
    }
  }
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked<DataType>& other) {
  if(this != &other) {
    clear();
    if(other.top == NULL) {
      top = NULL;
    }
    else {
      top = new StackNode(other.top->dataItem, NULL);
      StackNode * src = other.top;
      StackNode * dest = top;
      while(src->next != NULL) {
        src = src -> next;
        dest -> next = new StackNode(src->dataItem, NULL);
        dest = dest -> next;
      }
    }
  }
  return *this;
}

template <typename DataType>
StackLinked<DataType>::~StackLinked() {
  clear();
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error) {
  top = new StackNode(newDataItem, top);
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error) {
  if(isEmpty()) {
    throw(logic_error("Warning"));
  }
  else {
    StackNode * temp = top;
    top = top -> next;
    DataType mountain = temp -> dataItem;
    delete temp;
    return mountain;
  }
}

template <typename DataType>
void StackLinked<DataType>::clear() {
  if(isEmpty()) {
    return;
  }
  else {
    StackNode * temp = top;
    while(temp != NULL) {
      StackNode * regular = temp -> next;
      delete temp;
      temp = regular;
    }
    top = NULL;
  }
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const {
  return top == NULL;
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const {
  return false;
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const {
  StackNode * temp = top;
  while(temp != NULL) {
    cout << temp -> dataItem;
    if(temp -> next != NULL) {
      cout << endl;
    }
    temp = temp -> next;
  }
}

template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr) {
  dataItem = nodeData;
  next = nextPtr;
}
