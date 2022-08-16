#include <iostream>
#include <cstdlib>
#include "ArrayList.h"
#include "NameCard.h"

using namespace std;

int main(void)
{
    ArrayList List;
    NameCard *pNamecard;

    ListInit(&List);

    // 1. Insert 3 namecards
    pNamecard = new NameCard(string("KHJ"), string("010-1111-2222"));
    LInsert(&List, pNamecard);

    pNamecard = new NameCard(string("GMS"), string("010-2222-3333"));
    LInsert(&List, pNamecard);

    pNamecard = new NameCard(string("IDS"), string("010-3333-4444"));
    LInsert(&List, pNamecard);

    // 2. Show NameCard Info
    if (LFirst(&List, &pNamecard))
    {
        do
        {
            if (NameCompare(pNamecard, string("IDS")))
                ShowNameCardInfo(pNamecard);
        } while (LNext(&List, &pNamecard));
    }

    // 3. Change Phone Number
    if (LFirst(&List, &pNamecard))
    {
        do
        {
            if (NameCompare(pNamecard, string("IDS")))
                ChangePhoneNum(pNamecard, string("010-9999-9999"));
        } while (LNext(&List, &pNamecard));
    }

    // 4. Delete Namecard
    if (LFirst(&List, &pNamecard))
    {
        do
        {
            if (NameCompare(pNamecard, string("GMS")))
                LRemove(&List);
        } while (LNext(&List, &pNamecard));
    }

    // 5. Print All Info
    if (LFirst(&List, &pNamecard))
    {
        do
            ShowNameCardInfo(pNamecard);
        while (LNext(&List, &pNamecard));
    }

    return 0;
}