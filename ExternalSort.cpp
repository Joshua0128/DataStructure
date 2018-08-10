/** @file ExternalSort.cpp */

#include <iostream>
#include <random>

using namespace std;
const int MAX_SIZE = 100000;

/** Merges two sorted array segements theArray[first..mid] and theArray[mid+1..last] into one sorted array.
 *  @pre first <= mide <= last. The subarrays theArray[first..mid] and theArray[mid+1..last] are each sorted in increasing order.
 *  @post theArray[first..last] is sorted
 *  @param first The index of the beginning of the first segment in theArray.
 *  @param mid The index of the end of the first segment in theArray;mid+1 marks the beginning of the second segment.
 *  @param last The index of the last element in the second segment in theArray.
 *  @note This function merges the two subarrays into a temporary array and copy the result into the original array theArray.
 */
void merge(int theArray[], int first, int mid, int last)
{
    int tempArray[MAX_SIZE];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;

    int index = first1;
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
        }
        index++;
    }

    while (first1 <= last1)
    {
        tempArray[index] = theArray[first1];
        first1++;
        index++;
    }

    while (first2 <= last2)
    {
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    }

    for (index = first; index <= last; index++)
    {
        theArray[index] = tempArray[index];
    }
}

void mergeSort(int theArray[], int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;
        mergeSort(theArray, first, mid);
        mergeSort(theArray, mid + 1, last);
        merge(theArray, first, mid, last);
    }
}

/** Sorts an array into ascending order. Uses the quick sort with median-of-three pivot selection
 *  for arrays of at least MIN_SIZE entries, and uses the insertion sort for other arrays. 
 *  @pre theArray[first..last] is an array.
 *  @post theArray[first..last] is sorted.
 *  @param theArray  The given array.
 *  @param first  The first element to consider in theArray.
 *  @param last  The last element to consider in theArray.
 */
int partition(int theArray[], int first, int last)
{
    // pivot
    int pivot = theArray[last];
    // Index of smaller element
    int i = (first - 1);
    int j;
    for (j = first; j < last; j++)
    {
        //If current element is smaller than or equal to pivot
        if (theArray[j] <= pivot)
        {
            i++; //increment index of smaller element
            swap(theArray[i], theArray[j]);
        }
    }
    swap(theArray[i + 1], theArray[last]);
    i++;

    return i;
}

void quickSort(int theArray[], int first, int last)
{
    if (first < last)
    {
        int pivotIndex = partition(theArray, first, last);
        quickSort(theArray, first, pivotIndex - 1);
        quickSort(theArray, pivotIndex + 1, last);
    }
}

/** Sorts an array into ascending order. Uses the radix sort the array.
 *  @pre theArray[first..last] is an array.
 *  @post theArray[first..last] is sorted.
 *  @param theArray  The given array.
 *  @param size  The size of theArray.
 */
// int findMax(int theArray[], int size)
// {
//     int max = theArray[0];

//     for (int i = 0; i < size; i++)
//     {
//         if (theArray[i] > max)
//         {
//             max = theArray[i];
//         }
//     }
//     return max;
// }

// void countSort(int theArray[], int size, int exp)
// {
//     int ouput[size];
//     int i, int count[10] = {0};

//     for(i = 0; i < n; i++) 
//     {
//         count[(theArray[i] / exp) % 10]++;
//     }

//     for(i = 1; i < 10; i++)
//     {
//         count[i] += count[i - 1];
//     }
// }



// void radixSort(int theArray[], int size)
// {
// }


/* main functoin start here */

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

    // mergeSort(Arr, 0, MAX_SIZE - 1);
    quickSort(Arr, 0, MAX_SIZE - 1);

    cout << "sorted: ";
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;

    return 0;
}