/** @file LinkedList.cpp */

template <T>
LinkedList<T>::LinkedList()
{
    headPtr = nullptr;
    itemCount = 0;
}

template <T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <T>
T LinkedList<T>::getEntry(int position) const throw(PrecondViolatedExcep)
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<T> *nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        string message = "getEntry() called with anempty list or ";
        message = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }
}

template <T>
Node<T> *LinkedList<T>::getNodeAt(int position) const
{
    assert((position >= 1) && (position <= itemCount));
    Node<T> *curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
    {
        curPtr = curPtr.getNext();
    }
    return curPtr;
}

template <T>
bool LinkedList<T>::insert(int newPosition, const T &newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        Node<T> *newNodePtr = new Node<T>(newEntry);

        if (newPosition == 1)
        {
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            Node<T> *prevPtr = getNodeAt(newPosition - 1);
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }
        itemCount++;
    }

    return ableToInsert;
}

template <T>
bool LinkedList<T>::remove(int position)
{
    bool ableToRemove = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToRemove)
    {
        Node<T>* curPtr = nullptr;

        if (position == 1)
        {
            curPtr = headPtr;
            headPtr = headPtr.getNext();
        }
        else 
        {
            Node<T>* prevPtr = getNodeAt(position - 1);
            curPtr = prevPtr->getNext());
            prevPtr->setNext(curPtr->getNext());
        }
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;

        itemCount--;
    }

    return ableToRemove;
}

template <T>
void LinkedList<T>::clear()
{
    while(!isEmpty())
        remove(1);
}

