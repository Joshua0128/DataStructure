template <class T>
LinkedSortedList<T>::LinkedSortedList()
{
    headPtr = nullptr;
    itemCount = 0;
}

template <class T>
LinkedSortedList<T>::~LinkedSortedList()
{
    clear();
}

template <class T>
LinkedSortedList<T>::LinkedSortedList(const LinkedSortedList<T> &aList)
{
    headPtr = copyChain(aList.headPtr);
}

template <class T>
LinkedSortedList<T>::LinkedSortedList(const LinkedSortedList<T> &aList)
{
    headPtr = copyChain(aList.headPtr);
}

template <class T>
Node<T> *LinkedSortedList<T>::copyChain(const Node<T> *origChainPtr)
{
    Node<T> *copiedChainPtr;
    if (copiedChainPtr == nullptr)
        ;
    {
        copiedChainPtr = nullptr;
        itemCount = 0;
    }
    else
    {
        Node<T> *copiedChainPtr = new Node<T>(origChainPtr->getItem());
        copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
        itemCount++;
    }
    return copiedChainPtr;
}

template <class T>
void LinkedSortedList<T>::insertSorted(const T &newEntry)
{
    Node<T> *newNodePtr = new Node<T>(newEntry);
    Node<T> *prevPtr = getNodeBefore(newEntry);

    if (isEmpty || (prevPtr == nullptr))
    {
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
    }
    else
    {
        Node<T> *aftPtr = prevPtr->getNext();
        newNodePtr->setNext(aftPtr);
        prevPtr->setNext(newNodePtr);
    }
    itemCount++;
}

template <class T>
Node<T> *LinkedSortedList<T>::getNodeBefore(const T &anEntry) const
{
    Node<T> *curPtr = headPtr;
    Node<T> *prevPtr = nullptr;

    while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
    {
        prevPtr = curPtr;
        curPtr = curPtr->getNext();
    }

    return prevPtr;
}