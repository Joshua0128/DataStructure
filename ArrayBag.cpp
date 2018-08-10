#include <iostream>
#include <string>
#include "ArrayBag.h"

template <class ItemType>
ArrayBag<ItemType>::ArrayBag()
{
    itemCount = 0;
    maxItems = DEFAULT_CAPACITY;
}

template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType &newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (!hasRoomToAdd)
    {
        ItemType *oldArray = items;
        items = new ItemType[2 * maxItems];
        for (int index = 0; index < maxItems; index++)
        {
            items[index] = oldArray[index];
        }
        delete[] oldArray;
        maxItems = 2 * maxItems;
    }

    items[itemCount] = newEntry;
    itemCount++;

    return hasRoomToAdd;
}

template <class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
    vector<ItemType> bagContents;
    for (int i = 0; i < itemCount; i++)
    {
        bagContents.push_back(items[i]);
    }
    return bagContents;
}

template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
    return itemCount;
}

template <class ItemType>
int ArrayBag<ItemType>::getCurrentCapacity() const
{
    return maxItems;
}

template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &anEntry)
{
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem)
    {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }
    return canRemoveItem;
}

template <class ItemType>
void ArrayBag<ItemType>::clear()
{
    itemCount = 0;
}

template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const
{
    int frequency = 0;
    int curIndex = 0;
    while (curIndex < itemCount)
    {
        if (items[curIndex] == anEntry)
        {
            frequency++;
        }
        curIndex++;
    }
    return frequency;
}

template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &target) const
{
    return getFrequencyOf(target) > 0;
}

template <class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const
{
    bool found = false;
    int result = -1;
    int searchIndex = 0;
    while (!found && (searchIndex < itemCount))
    {
        if (items[searchIndex] == target)
        {
            found = true;
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        }
    }
    return result;
}

void displayBag(ArrayBag<string> &bag)
{
    cout << "The bag contains " << bag.getCurrentSize()
         << " items:" << endl;
    vector<string> bagItems = bag.toVector();

    int numOfEntries = (int)bagItems.size();
    for (int i = 0; i < numOfEntries; i++)
    {
        cout << bagItems[i] << " ";
    }
    cout << endl
         << endl;
}

void bagTester(ArrayBag<string> &bag)
{
    cout << "isEmpty: returns " << bag.isEmpty()
         << "; should be 1 (true) " << endl;
    displayBag(bag);

    string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "add 6 items to the bag: " << endl;
    for (int i = 0; i < 6; i++)
    {
        bag.add(items[i]);
    }
    displayBag(bag);

    cout << "isEmpty: returns " << bag.isEmpty()
         << "; should be 0   (false) " << endl;
    cout << "getCurrentSize: returns " << bag.getCurrentSize()
         << "; should be 6 " << endl;
    cout << "Try to add another entry: add(\"extra\") returns "
         << bag.add("extra") << endl;
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
    displayBag(bag);
    cout << "Current Capacity: " << bag.getCurrentCapacity() << endl;

    cout << "After clear the bag, ";
    bag.clear();

    cout << "isEmpty: returns " << bag.isEmpty()
         << "; should be 1 (true)" << endl;
}

int main()
{
    ArrayBag<string> bag;
    cout << "Testing the Array-Based Bag:" << endl;
    cout << "The initial Bag is empty." << endl;
    bagTester(bag);
    bag.add("test");
    cout << "All done!" << endl;

    return 0;
}