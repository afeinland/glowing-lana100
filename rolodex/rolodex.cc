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

char makeLower(char c);
string makeLower(string s);

class Rolodex // a double linked list sorted alphabetically ascending order by last name
{
    struct Node
    {
        string fname,
            lname,
            address,
            phoneNumber;
        Node *prev, *next;

        Node(string fn, string ln, string adr, string pN, Node *p, Node *n)
        :fname(fn), lname(ln), address(adr), phoneNumber(pN), prev(p), next(n)
        {}

        void printNode()
        {
            cout << "Name: " + lname + ", " + fname << "\tAddress: " + address
                << "\tPhone: " + phoneNumber;
        }



    };

    Node *head, *tail;

public:
    Rolodex()
    :head(NULL), tail(NULL)
    {}

    void insert(string fn, string ln, string adr, string pN) //parameters retrieved from user
    {
        if(!head)
        {
            head = tail = new Node(fn, ln, adr, pN, NULL, NULL);
            return;
        }

        if(findLName(ln))//if last name already exists
        {
            cout << "ERROR: name " << ln << " already exists. Please use a different name." << endl;
            return;
        }

        if(makeLower(ln) < makeLower(head -> lname)) //then push on to front of list
        {
            head -> next = new Node(head -> fname, head -> lname, head -> address, head -> phoneNumber, head, head -> next);
            head -> fname = fn;
            head -> lname = ln;
            head -> address = adr;
            head -> phoneNumber = pN;

            if(head == tail)
                tail = tail -> next;

            return;
        }

        else if(makeLower(ln) > makeLower(tail-> lname)) //then tag on back of list
        {
            tail -> next = new Node(fn, ln, adr, pN, tail, NULL);
            tail = tail -> next;
            return;
        }

        else
        {
            Node *newNode = new Node(fn, ln, adr, pN, findPrev(ln), findNext(ln));
            newNode -> prev -> next = newNode;
            newNode -> next -> prev = newNode;
            return;
        }
        cout << ln << " DID NOT INSERT CORRECTLY" << endl;
    }

    Node *  findLName(string s)
    {
        for(Node *p = head; p != NULL; p = p -> next)
            if(makeLower(p -> lname) == makeLower(s))
                return p;
        return NULL;
    }

    void findLName_andPrint(string s)
    {
        Node * toPrint = findLName(s);
        if(!toPrint)
        {
            cout << "ERROR: Last name not found!" << endl;
            return;
        }
        toPrint -> printNode();
    }


    void printRolodex()
    {
        if(!head)
        {
            cout << "Rolodex is empty!" << endl;
            return;
        }
        for(Node *p = head; p != NULL; p = p -> next)
        {
            p -> printNode();
            cout << endl;
        }
    }

    void removeEntry(string s)
    {
        Node * toRemove = findLName(s);
        if(!toRemove)
        {
            cout << "ERROR: Entry not found!" << endl;
            return;
        }


        if(head == tail)
        {
            delete head;
            head = tail = NULL;
            cout << "Entry Deleted successfully." << endl;
            return;
        }
        else if(toRemove == head)
        {
            head = head -> next;
            head -> prev = NULL;
        }
        else if(toRemove == tail)
        {
            tail = tail -> prev;
            tail -> next = NULL;
        }
        else
        {
            //General Case
            toRemove -> prev -> next = toRemove -> next;
            toRemove -> next -> prev = toRemove -> prev;
        }

        delete toRemove;
        cout << "Entry Deleted successfully." << endl;
    }

private:
    Node * findPrev(string s) //finds soon-to-be previous node of new node with key s (s=lname of new node)
    {
        for(Node *p = head; p != NULL; p = p -> next)
            //if p -> next's last name > new node's last name (s), return p,
            //as p will become our new node's previous node
            if(makeLower(p -> lname) > makeLower(s))
                return p -> prev;
    }
    
    Node * findNext(string s) //find soon-to-be next node of newNode with key s (s=lname of new node)
    {
        for(Node *p = head; p != NULL; p = p -> next)
            //(same if condition as in findPrev()
            //if p -> next's last name > new node's last name, return p -> next,
            //as p -> next will become our new nodes next node
            if(makeLower(p -> lname) > makeLower(s))
                return p;
    }

};


void insertAddress_SW(Rolodex & r)
{
    string fName, lName, address, phoneNumber;
    printHeader("Add Entry");
    cout << "Example Input:" << "\nFirst Name: John\nLast Name: Smith\nAddress: 1234 Main St."
        << "\nPhone Number: 1234456677" << endl;
    
    printStarBanner();

    cout << "\nFirst Name: ";
    cin.ignore(1000, '\n');

    getline(cin, fName);
    cout << "Last Name: ";
    getline(cin, lName);
    cout << "Address: ";
    getline(cin, address);
    cout << "Phone Number: ";
    getline(cin, phoneNumber);

    r.insert(fName, lName, address, phoneNumber);

    cout << "\nEntry Confirmed" << endl;
}

void findAddress_SW(Rolodex r)
{
    string lName;
    printHeader("Find Entry");
    cout << "Please Enter a last name: ";
    cin.ignore(1000, '\n');
    getline(cin, lName);
    r.findLName_andPrint(lName); //prints node with corresponding lName, prints error message if lName not found
    cout << endl;
}

void deleteAddress_SW(Rolodex & r)
{
    string lName;
    printHeader("Delete Entry");
    cout << "Please enter the last name of the entry you wish to remove: ";
    cin.ignore(1000, '\n');
    getline(cin, lName);
    r.removeEntry(lName); //removes entry if it exists; if not, rints error message
    cout << endl;

}

void printRolodex_SW(Rolodex r)
{
    r.printRolodex();
}

void importRolodex_SW(Rolodex & r)
{
}

void exportRolodex_SW(Rolodex r)
{
}

void quit_SW(Rolodex r)
{
}

int main()
{
    Rolodex r;
    char userInput = 'x';

    r.insert("Alex", "Feinland", "address", "phone");
    r.insert("Zlex", "Zeinland", "Zddress", "Zhone");
    r.insert("Plex", "Peinland", "Pddress", "Phone");

    printMenu();
    
    while(cin >> userInput)
    {
        switch(userInput)
        {
            case 'i':
                insertAddress_SW(r);
                break;
            case 'f':
                findAddress_SW(r);
                break;
            case 'd':
                deleteAddress_SW(r);
                break;
            case 'p':
                cin.ignore(1000, '\n');
                printRolodex_SW(r);
                break;
            case 'l':
                importRolodex_SW(r);
                break;
            case 's':
                exportRolodex_SW(r);
                break;
            case 'q':
                quit_SW(r);
        }

        printMenu();
    }


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





char makeLower(char c)
{
    return c | 32;
}

string makeLower(string s)
{
    string toReturn = "";
    string toAdd = "";

    for(int i = 0; i < s.length(); ++i)
    {
        toAdd = makeLower(s.at(i));
        toReturn += toAdd;
    }
    return toReturn;
}

