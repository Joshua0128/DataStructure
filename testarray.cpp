#include <iostream>

using namespace std;

int main() {
    int arraysize = 10;
    int* anArray = new int[arraysize];
    int Arr[10]; 

    for (int i = 0;i < arraysize; i++) {
        Arr[i] = i;
    }

    for (int i = 0;i < arraysize; i++) {
        cout << Arr[i] << endl;
    }
    
    int* oldarray = Arr;
    Arr = new int[2 * arraysize];

    for (int i = 0;i < arraysize; i++) {
        Arr[i] = oldarray[i];
    }

    delete [ ] oldarray;

    for (int i = arraysize;i < 2 * arraysize; i++) {
        Arr[i] = i * 10;
    }

    arraysize = 2 * arraysize;

    for (int i = 0;i < arraysize; i++) {
        cout << Arr[i] << endl;
    }

    return 0;
}