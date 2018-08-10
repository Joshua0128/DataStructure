#ifndef _PLAIN_BOX
#define _PLAIN_BOX

template <class ItemType>

class PlainBox
{
  protected:
    ItemType item;

  public:
    PlainBox();

    PlainBox(const ItemType &theItem);

    virtual void setItem(const ItemType &theItem);

    ItemType getItem() const;
};

#include "PlainBox.cpp"
#endif