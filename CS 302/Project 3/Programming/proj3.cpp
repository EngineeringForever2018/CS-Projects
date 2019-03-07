//Jared Lam CS 302 homework 3 3/4/19
//Our assignment is to get a lot of random number from each 3 file then we have to sorted by using these types of sorting algorithm
#include <iostream>
#include <cstdlib> //rand or srand
#include <ctime>
#include <fstream>
#include "quickSort.cpp"
#include "bubblesort.cpp"


using namespace std;

int main() {
  int number[10000];
  fstream files;
  //files.open("100000.txt");
  files.open("10000.txt");
  //files.open("1000.txt");
  for(int i = 0; i < 10000; i++) {
     //reading the files
     files >> number[i];
  }
  files.close();
  clock_t start = clock();
  quicksort(number, 0, 9999);
  clock_t end = clock();
  for(int j = 0; j <= 9999; j++) {
    cout << number[j] << endl;
  }
  cout << "CPU time: " << ((float)(end - start))/CLOCKS_PER_SEC << endl;
  cout << "Compare: " << COMPARE << endl;
  cout << "Swap: " << SWAP << endl;
  //files.open("100000.txt");
  files.open("10000.txt");
  //files.open("1000.txt");
  for(int i = 0; i < 10000; i++) {
     //reading the files
     files >> nmber[i];
  }
  files.close();
  start = clock();
  bubbleSort(number, 10000);  //wait for 30 second for the compile to read and sorted the size of the length
  end = clock();
  for(int j = 0; j <= 9999; j++) {
    cout << number[j] << endl;
  }
  cout << "CPU time: " << ((float)(end - start))/CLOCKS_PER_SEC << endl;
  cout << "Comparison: " << COMPARISON << endl;
  cout << "Swapped: " << SWAPPED << endl;
  return 0;
}
