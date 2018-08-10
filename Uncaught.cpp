#include <iostream>
#include <string>

using namespace std;

// string contain [ch][ch][ch][/0] so the bug appear when we input the index is the size of the string

void encodeChar(int i, string &str, int sh)
{
    // cout << i << " = " <<str[i] << " - " <<static_cast<int>(str[i]) << endl;
    int base = static_cast<int>('a');
    if (isupper(str[i]))
    {
        base = int('A');
    }
    char newChar = (static_cast<int>(str[i]) + base + sh) % 26 + base;
    str.replace(i, 1, 1, newChar);
}

void encodeString(int numChar, string &str,int shift)
{
    try
    {
        cout << "s:" << shift << endl;
        for (int j = numChar - 1; j >= 0; j--)
            encodeChar(j, str, shift);
        
        
    }
    catch (out_of_range e)
    {
        cout << "The string does not contain " << numChar;
        cout << " characters." << endl;
        cout << e.what() << endl;
    }
}

int main()
{
    string str1 = "joshua";
    // cout << str1.size() << endl;
    for (int s = 0; s < 27; s++) {
        encodeString(str1.size(), str1, s);
        cout << str1 << endl;
    }

    return 0;
}