#include <iostream>
#include <string>

int endPre(string, int);

using namespace std;

int main()
{
    return 0;
}

int endPre(string strExp, int first)
{
    int last;
    last = strExp.length() - 1;
    if(first < 0 | first > last) {
        return -1;
    }

}