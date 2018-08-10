/* @file BagInterface.h */
#ifndef _BAG_INTERFACE
#define _BAG_INTERFACE

#include <vector>
using namespace std;

template <class ItemType>
class BagInterface
{
  public:
    /*  Gets the current number if entries in this bag.
            @return The interger number of entries currently in the bag. */

    virtual int getCurrentSize() const = 0;

    /*  Gets whether the bag is empty.
        @return True if the bag is empty, or false if not */
    virtual bool isEmpty() const = 0;

    /* Add a new entry to this bag.
        @post If successful, newEntry is stored in the bag amd the count if items in the bag has increased by 1.
        @param newEntry  The object to be added as a new entry.
        @return True if addition was successful, or false if not. */
    virtual bool add(const ItemType &newEntry) = 0;

    /* Remove one occurence of a given entry from this bag, if possible.
        @post If succeddful, anEntry has been removed from the bag and the count of items in the bag has decreased by 1.
        @param anEntry The entry to be removed
        @return True id removal was successful, or false if not.*/
    virtual bool remove(const ItemType &anEntry) = 0;

    /* Removes all entries from this bag.
        @post Bag contains no items, and the count of items is 0.*/
    virtual void clear() = 0;

    virtual int getFrequencyOf(const ItemType &anEntry) const = 0;

    virtual bool contains(const ItemType &anEntry) const = 0;

    virtual vector<ItemType> toVector() const = 0;
};
#endif