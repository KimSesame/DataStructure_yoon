#include <iostream>
#include "NameCard.h"

NameCard::_namecard(string name, string phone)
{
    this->name = name;
    this->phone = phone;
}

void ShowNameCardInfo(NameCard *pcard)
{
    cout << "Name: " << pcard->name << endl;
    cout << "Phone: " << pcard->phone << endl;
    cout << endl;

    return;
}

bool NameCompare(NameCard *pcard, string name)
{
    return (pcard->name == name);
}

void ChangePhoneNum(NameCard *pcard, string phone)
{
    pcard->phone = phone;

    return;
}
