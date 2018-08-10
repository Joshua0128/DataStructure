#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
    int target;
    vector<int> boxVector;
    int Arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index = 0;

    for (int i = 0; i < 10; i++)
    {
        boxVector.push_back(Arr[i]);
    }

    cin >> target;
    bool found = false;
    while (!found && (index < boxVector.size()))
    {
        if (target == boxVector[index])
            found = true;
        else
            index++;
    }
    //  assert(found);
    if(!found)
        throw logic_error("Target not found in box!");
    

    return 0;
}