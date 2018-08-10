/** Interface for the ADT list 
 *   @file ListInterfce.h   */

#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

template <class T>
class ListInterface {
    public:
        virtual bool isEmpty() const = 0;
        virtual int getLength() const = 0;
        virtual bool insert(int newPosition, const T& newEntry) = 0;
        virtual bool remove(int position) = 0;
        virtual void clear() = 0;
        virtual T getEntry(int position) const = 0;
        virtual void setEntry(int position, const T& newEntry) = 0;
};
#endif
