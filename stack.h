#include <iostream>

using namespace std;


#define STACK_CAPACITY 1000

class Stack
{
    char *buf;
    int size; //size == next open index

public:
    Stack()
    :buf(new char[STACK_CAPACITY]), size(0) 
    {}

    ~Stack()
    {
        delete[] buf;
    }

    void push(char c)
    {
        if(size >= STACK_CAPACITY)
            error_Push_on_Full_Stack();
        buf[size++] = c;
    }

    char pop()
    {
        if(size == 0)
            error_Pop_on_Empty_Stack();
        return buf[--size];
    }

    char top()
    {
        return buf[size - 1]; 
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void addString(string str)
    {
        int strlen = str.length();
        for(int i = 0; i < strlen; ++i)
            this -> push(str.at(i));
    }

    void print() //for testing purposes
    {
        int sz = size;
        for(int i = 0; i < sz; ++i)
        {
            cout << buf[i];
        }
    }

    void printNpop()
    {
        int sz = size;
        for(int i = 0; i < sz; ++i)
        {
            cout << this -> pop();
        }
    }


private:

    void error_Push_on_Full_Stack()
    {
        cerr << "ERROR: push(char ) called on full stack. " << endl;
    }

    void error_Pop_on_Empty_Stack()
    {
        cerr << "ERROR: pop() called on empty stack. " << endl;
    }

};


