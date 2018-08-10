/** ADT stack: array-based implementation.
 @file ArrayStack.h */

#ifndef _ARRAY_STACK
#define _ARRAY_STACK
#include "StackInterface.h"
#include "PrecondViolatedExcep.h"

const int MAX_STACK = 100;

template <class T>
class ArrayStack : public StackInterface<T>
{
  private:
    T items[MAX_STACK];
    int top;

  public:
    ArrayStack();
    bool isEmpty() const;
    bool push(const T &newEntry);
    bool pop();
    T peek() const throw(PrecondViolatedExcep);
};

#include "ArrayStack.cpp"
#endif