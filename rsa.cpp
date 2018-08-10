#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
bool isPrime(long n)
{
    if (n <= 1)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    else
    {
        int maxsqr = (long)sqrt(n) + 1;
        for (long i = 3; i < maxsqr; i = i + 2)
        {
            if (n % i == 0)
                return false;
        }
    }
    return true;
}
void prime(long n, vector<long> &vec)
{
    if (n <= 1)
        return;
    for (long i = 2; i <= n; ++i)
    {
        if (isPrime(i))
            vec.push_back(i);
    }
    return;
}

int main()
{
    vector<long> v;
    long n;
    cout << "input the number: " << endl;
    cin >> n;
    prime(n, v);
    while (n != 1)
    {
        long i = 0;
        while (v[i] <= n)
        {
            if (n % v[i] == 0)
            {
                cout << v[i] << " ";
                n = n / v[i];
                break;
            }
            ++i;
        }
    }
    cout << endl;
    return 0;
}
