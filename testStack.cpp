#include <iostream>
#include <string>
#include "ArrayStack.h"
#include "LinkedStack.h"




using namespace std;

int main()
{
    StackInterface<string> *stackPtr = new ArrayStack<string>();
    string anItem = "";
    string str = "";
    while (str != "0")
    {
        cout << "Enter a String (press 0 to stop typein) : " << endl;
        cin >> str;
        if (str != "0")
        {
            anItem = str;
            stackPtr->push(anItem);
        }
    }
    cout << "pop: " << endl;
    // cout << stackPtr->isEmpty() << endl;
    while (!stackPtr->isEmpty())
    {
        cout << stackPtr->peek() << endl;
        stackPtr->pop();
    }
    // stackPtr->peek();
    cout << "After pop\n" << stackPtr->isEmpty() << endl;

    return 0;
}