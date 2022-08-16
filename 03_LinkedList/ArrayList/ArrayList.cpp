#include <iostream>
#include "ArrayList.h"

using namespace std;

void ListInit(List *plist)
{
    plist->numOfData = 0;
    plist->curPosition = -1;
}

void LInsert(List *plist, LData data)
{
    if (plist->numOfData > LIST_LEN)
    {
        cout << "FULL!" << endl;
        return;
    }

    plist->arr[(plist->numOfData)++] = data;
}

int LFirst(List *plist, LData *pdata)
{
    if (plist->numOfData == 0)
        return false;

    plist->curPosition = 0;
    *pdata = plist->arr[0];

    return true;
}

int LNext(List *plist, LData *pdata)
{
    if (plist->curPosition >= plist->numOfData - 1)
        return false;

    *pdata = plist->arr[++(plist->curPosition)];

    return true;
}

LData LRemove(List *plist)
{
    int rpos = plist->curPosition;
    int num = plist->numOfData;
    LData rdata = plist->arr[rpos];

    for(int i=rpos; i<num-1; i++)
        plist->arr[i] = plist->arr[i+1];

    (plist->numOfData)--;
    (plist->curPosition)--;

    delete rdata;
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}
