/** @file TestForLinkedBag.cpp
*  try to test the core method of the LinkedBag
*/

#include "BagInterface.h"
#include "LinkedBag.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void displayBag(BagInterface<string> *bagPtr)
{
    cout << "The bag contains " << bagPtr->getCurrentSize()
         << " items:" << endl;
    vector<string> bagItems = bagPtr->toVector();

    int numOfEntries = (int)bagItems.size();
    for (int i = 0; i < numOfEntries; i++)
    {
        cout << bagItems[i] << " ";
    }
    cout << endl
         << endl;
}

void bagTester(BagInterface<string> *bagPtr)
{
    cout << "isEmpty: returns " << bagPtr->isEmpty()
         << "; should be 1 (true) " << endl;

    string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "add 6 items to the bag: " << endl;
    for (int i = 0; i < 6; i++)
    {
        bagPtr->add(items[i]);
    }
    displayBag(bagPtr);

    cout << "isEmpty: returns " << bagPtr->isEmpty()
         << "; should be 0   (false) " << endl;
    cout << "getCurrentSize: returns " << bagPtr->getCurrentSize()
         << "; should be 6 " << endl;
    cout << "Try to add another entry: add(\"extra\") returns "
         << bagPtr->add("extra") << endl;
    // cout << "contains(\"three\"): returns " << bag.contains("three")
    //      << "; should be 1 (true)" << endl;
    // cout << "contains(\"ten\"): returns " << bag.contains("ten")
    //      << "; should be 0 (false)" << endl;
    // cout << "getFrequencyOf(\"one\"): returns "
    //      << bag.getFrequencyOf("one") << "; should be 2" << endl;
    // cout << "remove(\"one\"): returns "
    //      << bag.remove("one") << "; should be 1 (true)" << endl;
    // cout << "getFrequencyOf(\"one\"): returns "
    //      << bag.getFrequencyOf("one") << "; should be 1" << endl;
    // cout << "remove(\"one\"): returns "
    //      << bag.remove("one") << "; should be 1 (true)" << endl;
    // cout << "remove(\"one\"): returns "
    //      << bag.remove("one") << "; should be 0 (false)" << endl;
    // cout << endl;
    displayBag(bagPtr);
    cout << "Current size: " << bagPtr->getCurrentSize() << endl;
}

int main()
{
    BagInterface<string>* bagPtr = nullptr;
    bagPtr = new LinkedBag<string>();
    cout << "Testing the Link-Based Bag:" << endl;

    cout << "The initial bag is empty." << endl;
    bagTester(bagPtr);
    delete bagPtr;
    bagPtr = nullptr;
    cout << "All done!" << endl;

    return 0;
}