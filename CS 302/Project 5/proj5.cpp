//This is Jared Lam Project 5 for CS 302 3/27/19

#include <iostream>
#include <algorithm> // for heap operations
#include <cstdlib> //rand
#include <ctime>
#include <vector>

using namespace std;

const int NUMBER_VALUE = 100;

int main() {

 vector<int> v1;
 srand(time(NULL));
 int temp;
 for(int i = 0; i < NUMBER_VALUE; i++) {
   v1.push_back(rand());
 }
 // Converting vector into a heap
 // using make_heap()
 make_heap(v1.begin(), v1.end());
 //Find the average of all the values
 for(int i = 0; i < NUMBER_VALUE; i++) {
   temp += v1[i];
 }
 temp /= NUMBER_VALUE;
 // Displaying the maximum element of heap
 // using front()
 cout << "The maximum element of heap is : ";
 cout << v1.front() << endl;

 // using push_back() to enter element
 // in vector
 v1.push_back(temp);

 // using push_heap() to reorder elements
 push_heap(v1.begin(), v1.end());

 // Displaying the maximum element of heap
 // using front()
 cout << "The maximum element of heap after push is : ";
 cout << v1.front() << endl;

 // using pop_heap() to delete maximum element
 pop_heap(v1.begin(), v1.end());
 v1.pop_back();

 // Displaying the maximum element of heap
 // using front()
 cout << "The maximum element of heap after pop is : ";
 cout << v1.front() << endl;

 sort_heap(v1.begin(), v1.end());
 for(int i = 0; i < NUMBER_VALUE; i++) {
    cout << v1[i] << endl;
 }

 return 0;
}
