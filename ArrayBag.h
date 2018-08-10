#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include "BagInterface.h"

using namespace std;

template <class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
  private:
    static const int DEFAULT_CAPACITY = 6;
    ItemType* items = new ItemType[DEFAULT_CAPACITY];
    int itemCount;
    int maxItems;
    int getIndexOf(const ItemType &target) const;

  public:
    ArrayBag<ItemType>();
    int getCurrentSize() const;
    int getCurrentCapacity() const;
    bool isEmpty() const;
    bool add(const ItemType &newEntry);
    bool remove(const ItemType &anEntry);
    void clear();
    bool contains(const ItemType &anEntry) const;
    int getFrequencyOf(const ItemType &anEntry) const;
    vector<ItemType> toVector() const;
};
#endif
