#include <iostream>

using namespace std;

/* Sorts an array into ascending order. Uses the quick sort with
median-of-three pivot selection for arrays of at least MIN_SIZE
entries, and uses the insertion sort for other arrays.
@pre theArray[first..last] is an array.
@post theArray[first..last] is sorted
@param theArray – the given array
@param first – the index of 1st element to consider in theArray
@param last – the index of last element to cnsdr in theArray */
long COMPARE = 0;
long SWAP = 0;
template<class ItemArray>
int partition(ItemArray theArray, int first, int last);
void swap(int &i, int &j);

void swap(int &i, int &j) {
  int temp;
  temp = i;
  i = j;
  j = temp;
}

template<class ItemArray>
//partition the theArray[first..last]
int partition(ItemArray a[], int first, int last){
  int pivot; //element to be placced at the right position
  int i, j;
  pivot = a[last];
  i = (first - 1);
  //using a loop to find the value
  for(j = first; j <= last - 1; j++) {
    //compare is a[j] is less than or equal to the pivot
    if(a[j] <= pivot) {
      COMPARE++;
      i++;
      swap(a[i], a[j]);
      SWAP++;
    }
  }
  swap(a[i + 1], a[last]);
  SWAP++;
  return (i + 1);
}

template <class ItemType>
void quicksort(ItemType a[], int first, int last){
  int p;
  if (first < last) {
    p = partition(a, first, last);
    quicksort(a, first, p - 1);
    quicksort(a, p + 1, last);
  }
} // end quickSort
