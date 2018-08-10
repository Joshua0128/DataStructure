#include "ArrayList.h"
#include <iostream>
#include <string>

int main()
{
    ListInterface<string> *listPtr = new ArrayList<string>();
    string data[] = {"one", "two", "three", "four", "five", "six"};
    cout << "isEmpty: returns" << listPtr->isEmpty()
    << "; should be 1 (true)" << endl;

    for (int i = 0; i < 6; i++)
    {
        if (listPtr->insert(i + 1, data[i]))
            cout << "Inserted" << listPtr->getEntry(i + 1)
                 << " at position " << (i + 1) << endl;
        else
            cout << "Cannot insert " << data[i] << "at position" << (i + 1)
                 << endl;
    }

    return 0;
}
