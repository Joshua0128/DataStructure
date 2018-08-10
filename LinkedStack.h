/** ADT Stack: Linked-based implementation.
 @file LinkedStack.h */

#ifndef _LINKED_STACK
#define _LINKED_STACK

#include "StackInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template <class T>
class LinkedStack : public StackInterface<T>
{
  private:
    Node<T> *topPtr;

  public:
    LinkedStack();
    LinkedStack(const LinkedStack<T>& aStack); 
    virtual ~LinkedStack();

    bool isEmpty() const;
    bool push(const T& newItem);
    bool pop();
    T peek() const throw(PrecondViolatedExcep);
};

#include "LinkedStack.cpp"
#endif