/** ADT sorted list using the ADT list.
 *  @file SortedListHasA.h
 */

#ifndef _SORTED_LIST_HAS_A
#define _SORTED_LIST_HAS_A

#include "SortedListInterface.h"
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template <class T>
class SortedListHasA : public SortedListInterface<T>
{
  private:
    ListInterface<T> *listPtr;

  public:
    SortedListHasA();
    SortedListHasA(const SortedListHasA<T> &sList);
    virtual ~SortedListHasA();

    void insertSorted(const T& newEntry);
    bool removeSorted(const T& anEntry);
    int getPosition(const T& newEntry) const;
    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();
    T getEntry(int position) const throw (PrecondViolatedExcep);
};
#include "SortedListHasA.cpp"
#endif
