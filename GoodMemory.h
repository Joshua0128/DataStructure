/** @file GoodMemory.h */
#include <string>
#include <vector> 

using namespace std;

class GoodMemory {
    private:
        vector<int>* intVtrPtr;
    public:
        GoodMemory();
        ~GoodMemory();
        void fixedLeak(const int);
};
