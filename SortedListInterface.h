/** The Interface of ADT sorted list
 *  @file SortedListInterface.h
 */

#ifndef _SORTED_LIST_INTERFACE
#define _SORTED_LIST_INTERFACE

template <class T>
class SortedListInterface
{
  public:
    virtual void insertSorted(const T &newEntry) = 0;
    virtual bool removeSorted(const T &anEntry) = 0;
    virtual int getPosition(const T &anEntry) = 0;
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual bool remove(int position) = 0;
    virtual void clear() = 0;
    virtual T getEntry(int positoin) const = 0;
};

#endif