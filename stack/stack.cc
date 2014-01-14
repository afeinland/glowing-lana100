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

