template <class ItemType>
MagicBox<ItemType>::MagicBox()
{
    firstItemStored = false;
}

template <class ItemType>
MagicBox<ItemType>::MagicBox(const ItemType &theItem)
{
    // std::cout << "MagicBox initialation" << std::endl;
    this->item = theItem;
    firstItemStored = true;
}

template <class ItemType>
void MagicBox<ItemType>::setItem(const ItemType &theItem)
{
    // std::cout << "Invoke MagicBox.setItem()" << std::endl;
    if (!firstItemStored)
    {
        this->item = theItem;
        firstItemStored = true;
    }
}