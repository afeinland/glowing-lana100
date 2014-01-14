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

#include <iostream>

using namespace std;

#define WINDOW_LENGTH 80

void printMenu();
void printHeader(string s);
void printStarBanner();
int charCount(string s);
void printMenuOptions();





int main()
{
    
    
    
    printMenu();


}

void printMenu()
{
    printHeader("Menu");
    printMenuOptions();
    cout << endl;
    printStarBanner();
    cout << endl; 
    //TODO: print star banner before endl?

}

void printHeader(string s)
{
    printStarBanner();
    cout << endl;

    for(int i = 0; i < WINDOW_LENGTH/2 - charCount(s)/2; ++i)
        cout << " ";

    cout << "Rolodex: " << s << endl;

    printStarBanner();
    cout << endl;
}

void printStarBanner()
{
    for(int i = 0; i < WINDOW_LENGTH; ++i)
        cout << '*';
}

int charCount(string s)
{
    string str = s + "Rolodex: ";
    int i;

    for(i = 0; i < str.length(); ++i)
    {
        //Do Nothing
    }
    return i + 1;
}

void printMenuOptions()
{
    cout << "    i - insert a new address\n" << "    f - find a given address\n"
        << "    d - delete a given address\n" << "    p - print all cards in the Rolodex\n"
        << "    l - load addresses from a given Rolodex file\n"
        << "    s - save the addresses to a specified Rolodex file\n"
        << "    q - quit Rolodex";
}

