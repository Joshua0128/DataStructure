template <class T>
SortedListHasA<T>::SortListHasA()
{
    listPtr = new LinkedList<T>();
}

template <class T>
SortedListHasA<T>::SortListHasA(const SortedListHasA<T> &sList)
{
    listPtr = new LinkedList<T>();
    for (int position = 1; position <= sList.getLength(); position++)
    {
        listPtr->insert(position, sList.getEntry(position));
    }
}

template <class T>
SortedListHasA<T>::~SortListHasA()
{
    clear();
}

template<class T>
void SortedListHasA<T>::insertSorted(const T& newEntry)
{
    int newPosition = fabs(getPosition(newEntry));
    listPtr->insert(newPosition, newEntry);
}

