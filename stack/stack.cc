/*
* Course: CS 100 Fall 2013
*
* First Name: Alex
* Last Name: Feinland
* Username: afein001
* email address: afein001@ucr.edu
*
*
* Assignment: HW1
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

#include "stack.h"
#include <iostream>


using namespace std;


int main()
{

    Stack stack;
    string str;
    
    while(getline(cin, str))
    {
        stack.addString(str);
        stack.printNpop();
        cout << endl;
    }

    cout << endl;
    return 0;
}

