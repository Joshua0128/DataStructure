/** ADT list: Link-based implementation
 *  @file LinkedList.h     */

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template <T>
class LinkedList : public ListInterface<T>
{
  private:
    Node<T> *headPtr;
    int itemCount;
    Node<T> *getNodeAt(int position) const;

  public:
    LinkedList();
    LinkedList(const LinkedList<T> &aList);
    virtual ~Linkedlist();

    bool isEmpty() const;
    int getLength(const;) bool insert(int position, const T &newEntry);
    bool remove(int position);
    void clear();

    T getEntry(int position) const throw(PrecondViolatedExcep);

    void setEntry(int position, const T &newEntry) throw(PrecondViolatedExcep);
};

#include "LinkedList.cpp"
#endif