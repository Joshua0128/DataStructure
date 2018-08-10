/** @file LinkedStack.cpp */

#include <cassert>
#include "LinkedStack.h"

template <class T>
LinkedStack<T>::LinkedStack() : topPtr(nullptr)
{
}

template <class T>
LinkedStack<T>::LinkedStack(const LinkedStack<T> &aStack)
{
    Node<T> *origChainPtr = aStack->topPtr;
    if (origChainPtr == nullptr)
        topPtr = nullptr;
    else
    {
        topPtr = new Node<T>();
        topPtr->setItem(origChainPtr->getItem());

        Node<T> *newChainPtr = topPtr;

        while (origChainPtr != nullptr)
        {
            origChainPtr = origChainPtr->getNext();
            T nextItem = origChainPtr->getItem();
            Node<T> *newNodePtr = new Node<T>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}

template <class T>
LinkedStack<T>::~LinkedStack()
{
    while (!isEmpty())
        pop();
}

template <class T>
bool LinkedStack<T>::isEmpty() const
{
    return topPtr == nullptr;
}

template <class T>
bool LinkedStack<T>::push(const T &newItem)
{
    Node<T> *newNodePtr = new Node<T>(newItem, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
}
template <class T>

bool LinkedStack<T>::pop()
{
    bool result = false;
    if (!isEmpty())
    {
        Node<T> *nodeToDeletePtr = topPtr;
        topPtr = topPtr->next();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        result = true;
    }

    return result;
}

template <class T>
T LinkedStack<T>::peek() const throw(PrecondViolatedExcep)
{
    if(isEmpty())
        PrecondViolatedExcep("peek() called with empty stack");
    return topPtr->getItem();
}
