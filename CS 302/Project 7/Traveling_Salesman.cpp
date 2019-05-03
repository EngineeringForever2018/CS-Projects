//This is Jared Lam Project 7 CS 302
//I am using Traveling Salesman Problem (tsp()) which includes an algorithm step to solve this problem

#include <iostream>
#include <vector>
using namespace std;

int travel_cities[5], cities = 5, cost = 0; //cost is the distance
int matrix[5][5] = { {0, 218, 512, 705, 439}, //Reno to any city that mention in this Project
                     {218, 0, 736, 808, 57}, //SF to any city that mention in this Project
                     {512, 736, 0, 840, 421}, // Salt Lake City to any city that mention in this Project
                     {705, 808, 840, 0, 1117}, //Seattle to any city that mention in this Project
                     {439, 57, 421, 1117, 0} }; //Las Vegas to any city that mention in this Project
int tsp(int point); //tsp stands for traveling salesman problem
void min_cost(int city);

int tsp(int point) {
  int count = 0;
  int nc = 999; //nc = near city that goes to another city
  //int Reno = 0;
  int minimum = 999, temp;
  while(count < cities) {
    if((matrix[point][count] != 0) && (travel_cities[count] == 0)) {
      if(matrix[point][count] < minimum) {
        minimum = matrix[count][0] + matrix[point][count];
      }
      temp = matrix[point][count];
      nc = count;
    }
    count++;
  }
  if(minimum != 999) {
    cost = cost + temp;
  }
  return nc;
}

void min_cost(int city) { //goes through each city to hit all the city and goes back to the original city which is Reno
  int nc = tsp(city);
  travel_cities[city] = 1;
  cout << city + 1 << ' ';
  if(nc == 999) {
    nc = 0;
    cout << nc + 1 << ' ';
    cost = cost + matrix[city][nc];
    return;
  }
  min_cost(nc);
}

// driver program to test above function
int main()
{
    int i = 0, j = 0;
    cout << "Enter the Cost Matrix" << endl;
    while(i < cities) {
      travel_cities[i] = 0;
      i++;
    }
    cout << "Entered Cost Matrix: ";
    while(i < cities) {
      cout << endl;
      while(j < cities) {
         cout << matrix[i][j] << ' '; //space character in there and goes through each city to find the shortest path to visited each city possible route
         j++;
      }
      i++;
    }
    cout << endl;
    cout << "Possible route (path): ";
    min_cost(0);
    cout << endl << "Minimum Cost: \t" << endl;
    cout << cost << endl;
    return 0;
}
