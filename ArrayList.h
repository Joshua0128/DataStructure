/** ADT List: Array-based implementation.
 *  @file ArrayList.h */

#ifndef _ARRAY_LIST
#define _ARRAY_LIST

#include "ListInterface.h"
#include "PrecondViolatedExcep.h"

template <class T>
class ArrayList : public ListInterface<T>
{
  private:
    static const int DEFAULT_CAPACITY = 100;
    T items[DEFAULT_CAPACITY];
    int itemCount;
    int maxItems;

  public:
    ArrayList();
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const T& newEntry);
    bool remove(int position);
    void clear();

    T getEntry(int position) const throw (PrecondViolatedExcep);

    void setEntry(int position, const T& newEntry) throw(PrecondViolatedExcep);

};

#include "ArrayList.cpp"
#endif
