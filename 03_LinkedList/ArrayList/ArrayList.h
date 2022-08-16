#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__

#include "Point.h"

#define LIST_LEN 100
typedef Point* LData; // 리스트에 저장되는 데이터의 자료형을 정의 -> cpp에서 템플릿을 이용할 수 있다

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