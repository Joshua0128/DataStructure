/** ADT sorted list: Link-based implementation.
 *  @file LinkedSortedList.h
 */

#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template <class T>
class LinkedSortedList : public SortedListInterface<T>
{
  private:
    Node<T> *headPtr;
    int itemCount;
    Node<T> *getNodeBefore(const T &anEntry) const;
    Node<T> *getNodeAt(int position) const;
    Node<T> *copyChain(const Node<T> *origChainPtr);

  public:
    LinkedSortedList();
    LinkedSortedList(const LinkedSortedList<T> &aList);
    virtual ~LinkedSortedList();
    void insertSorted(const T &newEntry);
    bool removeSorted(const T &anEntry);
    int getPosition(const T &newEntry) const;

    // The following methods are the same as given in SortedListInterface:
    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();
    T getEntry(int position) const throw(PrecondViolatedExcep);
};
#include "LinkedSortedList.cpp"
#endif