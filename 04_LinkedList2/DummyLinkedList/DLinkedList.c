#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist)
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void FInsert(List *plist, LData data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;

    new_node->next = plist->head->next;
    plist->head->next = new_node;

    (plist->numOfData)++;
}

void SInsert(List *plist, LData data)
{
}

void LInsert(List *plist, LData data)
{
    if (plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));
