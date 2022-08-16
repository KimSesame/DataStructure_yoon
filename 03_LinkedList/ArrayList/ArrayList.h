#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__

#include "Point.h"
#include "NameCard.h"

#define LIST_LEN 100
typedef NameCard* LData; // ����Ʈ�� ����Ǵ� �������� �ڷ����� ���� -> cpp���� ���ø��� �̿��� �� �ִ�

typedef struct _arrayList
{
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;
} ArrayList;

typedef ArrayList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

#endif