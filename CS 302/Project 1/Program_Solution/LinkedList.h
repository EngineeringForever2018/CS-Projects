/*
 CS 302 Project 1 - LinkedList class
 By: Jared Lam (jaredlam@nevada.unr.edu)
 2/3/19
*/
#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <vector>

using namespace std;

//We are just making a template class for LinkedList with all the function required for this Project
template <typename T>
class LinkedList;
/* We are making friend class for LinkedList class, so that LinkedList
class can access their friend class's private data and their function as well */
template <typename T>
class Node {
  template <typename U>
  friend class LinkedList;
  public:
    Node() : m_next( NULL ), m_data(T())
    {
    }
    Node(const T data) : m_next( NULL ), m_data(data)
    {
    }

    T& GetData() {
      return m_data;
    }
    //This will return the data where it was originally from
    Node<T>* GetNext() {
      return m_next;
    }
    //This will return to where the m_next was pointing and go to the next data
  private:
    //Showing how to declare template inside the class
    Node <T>* m_next;
    T m_data;
};

template <typename T>
class LinkedList {
  template <typename U>
  friend std::ostream& operator<<(std:: ostream& os, const LinkedList<U> & LinkedList);

  public:
    //Default Constructor of LinkedList
    LinkedList() : pfirst( NULL ), plast( NULL )
    {
    }

    void push(T information);
    void pop();
    void Getpfirst();
    void Getplast();
    void show();
    int length();

  private:
    Node<T> *pfirst;
    Node<T> *plast;

};

template <typename T>
std::ostream& operator<<(std::ostream & os, const LinkedList<T> & LinkedList) {
  Node<T> *current = LinkedList.pfirst;

  while(current != NULL) {
    os << current->GetData() << " ";
    current = current->GetNext();
  }
  return os;
}

//Push function for linked list
template <typename T>
void LinkedList<T>::push(T information) {
  Node<T> * fast = new Node<T>; //Create fast
  fast -> m_data = information; //get the value
  if(pfirst) {
    plast -> m_next = fast;
    plast = fast; //get a new plast
  }
  else {
    pfirst = fast;
    plast = fast;
  }
}

//Pop function
template <typename T>
void LinkedList<T>::pop() {
  if(pfirst) {
    Node<T> * fast = pfirst; //Move fast to the head of the linked list
    pfirst = pfirst -> m_next; //Move to the next value
    delete fast;
  }
}
//Get the head of linked list
template <typename T>
void LinkedList<T>::Getpfirst() {
  Node<T> * fast = pfirst; // gain the information to fast
  cout << "First element: " << fast -> m_data << endl; //print out the first element
}

template <typename T>
void LinkedList<T>::Getplast() {
  Node<T> * fast = plast;
  cout << "Last element: " << fast -> m_data << endl; //print out the last element
}
template <typename T>
void LinkedList<T>::show() {
  Node<T> * display = pfirst;
  while(display) {
   cout << "The Element of linked list are: " << display -> m_data << endl;
   display = display -> m_next;
  }
}

template <typename T>
int LinkedList<T>::length() {
  int size = 0;
  Node<T> * reverse = pfirst;
  while(reverse) {
    size++;
    reverse = reverse -> m_next;
  }
  return size;
}
#endif // LinkedList_h
