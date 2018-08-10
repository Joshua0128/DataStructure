template <class ItemType>

PlainBox<ItemType>::PlainBox()
{
}

template <class ItemType>
PlainBox<ItemType>::PlainBox(const ItemType &theItem)
{
    item = theItem;
}

template <class ItemType>
void PlainBox<ItemType>::setItem(const ItemType &theItem)
{
    std::cout << "Invoke PlainBox.setItem()" << std::endl;
    item = theItem;
}

template <class ItemType>
ItemType PlainBox<ItemType>::getItem()const
{
    return item;
}
