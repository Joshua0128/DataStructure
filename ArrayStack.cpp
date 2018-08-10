/** @file ArrayStack.cpp */

#include <cassert>
#include "ArrayStack.h"

template <class T>
ArrayStack<T>::ArrayStack() : top(-1)
{
}

template <class T>
bool ArrayStack<T>::isEmpty() const
{
    return top < 0;
}

template <class T>
bool ArrayStack<T>::push(const T &newEntry)
{
    bool result = false;
    if (top < MAX_STACK - 1)
    {
        top++;
        items[top] = newEntry;
        result = true;
    }
    return result;
}

template <class T>
bool ArrayStack<T>::pop()
{
    bool result = false;
    if (!isEmpty())
    {
        top--;
        result = true;
    }
    return result;
}

template <class T>
T ArrayStack<T>::peek() const throw(PrecondViolatedExcep)
{
    if (isEmpty())
        throw PrecondViolatedExcep("peek() called with empty stack");
    return items[top];
}