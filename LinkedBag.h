/** ADT bag: Link0based implementation
 * @file LinkedBag.h */
#ifndef _LINKED_BAG
#define _LINKED_BAG

#include "BagInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
  private:
    Node<ItemType> *headPtr;
    int itemCount;
    Node<ItemType> *getPointerTo(const ItemType &target) const;

  public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType> &aBag);
    virtual ~LinkedBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType &newEntry);
    bool remove(const ItemType &anEntry);
    void clear();
    bool contains(const ItemType &anEntry) const;
    int getFrequencyOf(const ItemType &anEntry) const;
    vector<ItemType> toVector() const;
    void fillVector(vector<ItemType> &bagContents, Node<ItemType> *curPtr) const;
};
#include "LinkedBag.cpp"
#endif