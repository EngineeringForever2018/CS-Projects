//--------------------------------------------------------------------
//
//   Stack.h
//
//  Class declaration of the abstract class interface to be used as
//  the basis for implementations of the Stack ADT.
//
//--------------------------------------------------------------------

#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType>
class Stack {
  public:
    static const int MAX_STACK_SIZE = 8;
    Stack(int maxNumber = MAX_STACK_SIZE);
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    virtual ~Stack();
    virtual void push(const DataType& newDataItem) throw (logic_error) = 0;
    virtual DataType pop() throw (logic_error) = 0;

    virtual void clear() = 0;

    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual void showStructure() const = 0;
};

template <typename DataType>
Stack<DataType>::~Stack()
// Not worth having a separate class implementation file for the destuctor
{}

template <typename DataType>
Stack<DataType>::Stack(int maxNumber) {

}

template <typename DataType>
Stack<DataType>::Stack(const Stack<DataType>& other) {

}

template <typename DataType>
Stack<DataType>& Stack<DataType>::operator=(const Stack<DataType>& other) {
  return other;
}
#endif		// #ifndef STACK_H
