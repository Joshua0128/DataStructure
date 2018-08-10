#include <iostream>
#include <string>
#include "PlainBox.h"
#include "MagicBox.h"

using namespace std;

int main()
{
    // MagicBox<string> myMagicBox("Volleyball");
    // string magicBoxItem = myMagicBox.getItem();
    // cout << magicBoxItem << endl;
    // PlainBox<string>* cardBoxPtr1 = new PlainBox<string>("ACE");
    PlainBox<string>* cardBoxPtr2 = new MagicBox<string>("ACE");
    // cardBoxPtr1->setItem("King");
    cardBoxPtr2->setItem("King");
    
    // string head1 = cardBoxPtr1->getItem();
    string head2 = cardBoxPtr2->getItem();
    // cout << head1 << endl;
    cout << head2 << endl;

    return 0;
}
