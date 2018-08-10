/** @file InternalSort.cpp */

#include <iostream>
#include <random>

const int MAX_SIZE = 100000;
using namespace std;

/** Finds the larget item in an array.
 *  @pre The size of the array is >= 1.
 *  @post The arguments are unchanged.
 *  @param theArray The given array.
 *  @param size The number o elements in the array. 
 **/

int findIndexOfLargest(const int theArray[], int size);

void selectionSort(int theArray[], int n)
{
    for (int last = n - 1; last >= 1; last--)
    {
        int largest = findIndexOfLargest(theArray, last + 1);
        swap(theArray[largest], theArray[last]);
    }
}

int findIndexOfLargest(const int theArray[], int size)
{
    int indexSoFar = 0;
    for (int currentindex = 1; currentindex < size; currentindex++)
    {
        if (theArray[currentindex] > theArray[indexSoFar])
            indexSoFar = currentindex;
    }
    return indexSoFar;
}
/** Sorts the items in an array into ascending order.
 *  @pre None.
 *  @post theArray is sorted into ascending order; n is unchanged/
 *  @param theArray The given array.
 *  @param size The number o elements in the array. 
 **/

void bubbleSort(int theArray[], int size)
{
    bool sorted = false;
    int pass = 1;
    while (!sorted && (pass < size))
    {
        sorted = true;
        for (int index = 0; index < size - pass; index++)
        {
            int nextIndex = index + 1;
            if (theArray[index] > theArray[nextIndex])
            {
                swap(theArray[index], theArray[nextIndex]);
                sorted = false;
            }
        }

        pass++;
    }
}

/** Sorts the items in an array into ascending order. 
 *  @pre None.
 *  @post the Array is sorted into ascending order; n is unchanged.
 *  @param the Array The given array.
 *  @param size The size of theArray.   
 **/

void insertionSort(int theArray[], int size)
{
    for (int unsorted = 1; unsorted < size; unsorted++)
    {
        int nextItem = theArray[unsorted];
        int loc = unsorted;

        while ((loc > 0) && (theArray[loc - 1] > nextItem))
        {
            theArray[loc] = theArray[loc - 1];
            loc--;
        }

        theArray[loc] = nextItem;
    }
}

int main()
{
    random_device rd;
    default_random_engine gen = std::default_random_engine(rd());
    uniform_int_distribution<int> dis(1, MAX_SIZE);

    int Arr[MAX_SIZE];
    int size = MAX_SIZE;
    cout << "unsort: ";
    for (int i = 0; i < size; i++)
    {
        Arr[i] = dis(gen);
        cout << Arr[i] << " ";
    }
    cout << endl;

    // selectionSort(Arr, size);
    // bubbleSort(Arr, size);
    insertionSort(Arr, size);

    cout << "sorted: ";
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;

    return 0;
}