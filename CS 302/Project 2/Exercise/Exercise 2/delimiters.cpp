//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>
#include "StackArray.h"

using namespace std;
//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;

        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below

bool delimitersOk ( const string &expression ) {
  StackArray<char> array;
  char top;
  for(int i = 0; i < expression.size(); i++) {
    if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
      array.push(expression[i]);
    }
    else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}'){
      top = array.pop();
      if((expression[i] == ')' && top == '(') || (expression[i] == ']' && top == '[') || (expression[i] == '}' && top == '{')) {
      }
      else {
        return false;
      }
    }
  }
  return array.isEmpty();
}
