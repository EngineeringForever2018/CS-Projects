#include <iostream>

using namespace std;
long COMPARISON = 0;
long SWAPPED = 0;
// Sorts the items in an array into ascending order
template<class ItemType>
void bubbleSort (ItemType theArray[], int n){
  bool sorted = false; // False when swaps occur
  int pass = 1;
  while (!sorted && (pass < n)){
    // At this point, theArray[n+1-pass..n-1] is sorted
    // and all of its entries are > the entries in
    // theArray[0..n-pass]
    sorted = true; // Assume sorted
  for (int index = 0; index < n-pass; index++){
    // At this point, all entries in theArray[0..index-1]
    // are <= theArray[index]
    int nextIndex = index + 1;
    if (theArray[index] > theArray[nextIndex]){
      COMPARISON++;
      // Exchange entries
      swap(theArray[index], theArray[nextIndex]);
      SWAPPED++;
      sorted = false; // Signal exchange
    } // end if
  } // end for
  // Assertion: theArray[0..n-pass-1] < theArray[n-pass]
  pass++;
  } // end while
} // end bubbleSort
