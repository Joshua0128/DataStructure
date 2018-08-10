/* @file ArrayList.cpp */

template <class T>
ArrayList<T>::ArrayList()
{
    itemCount = 0;
    maxItems = DEFAULT_CAPACITY;
}

template <class T>
bool ArrayList<T>::isEmpty() const
{
    return itemCount == 0;
}

template <class T>
int ArrayList<T>::getLength() const
{
    return itemCount;
}

template <class T>
bool ArrayList<T>::insert(int newPosition, const T &newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1) && (itemCount < maxItems);

    if (ableToInsert)
    {
        for (int pos = itemCount; pos >= newPosition; pos--)
        {
            items[pos] = items[pos - 1];
        }

        items[newPosition - 1] = newEntry;
        itemCount++;
    }
    return ableToInsert;
}

template <class T>
bool ArrayList<T>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        for (int fromIndex = position, toIndex = fromIndex - 1; fromIndex < itemCount; fromIndex++, toIndex++)
            items[toIndex] = items[fromIndex];
        itemCount--;
    }
    return ableToRemove;
}

template <class T>
void ArrayList<T>::clear()
{
    itemCount = 0;
}

template <class T>
T ArrayList<T>::getEntry(int position) const throw(PrecondViolatedExcep)
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
        return items[position - 1];
    else
    {
        string message = "getEntry() called with an empty list or";
        message = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }
}

template <class T>
void ArrayList<T>::setEntry(int position, const T &newEntry) throw(PrecondViolatedExcep)
{
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet)
        items[position - 1] = newEntry;
    else
    {
        string message = "setEntry() called with an empty list or ";
        message = message + "invalid position";
        throw(PrecondViolatedExcep(message));
    }
}