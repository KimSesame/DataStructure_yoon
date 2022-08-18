#include <cstdio>
#include <cstdlib>
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
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;

    new_node->next = plist->head->next;
    plist->head->next = new_node;

    (plist->numOfData)++;
}

void SInsert(List *plist, LData data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *pred = plist->head;
    new_node->data = data;

    while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
        pred = pred->next;

    new_node->next = pred->next;
    pred->next = new_node;

    (plist->numOfData)++;
}

void LInsert(List *plist, LData data)
{
    if (plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

int LFirst(List *plist, LData *pdata)
{
    if (plist->head->next == NULL)
        return false;

    plist->before = plist->head;    // before points dummy
    plist->cur = plist->head->next; // cur points first node

    *pdata = plist->cur->data;

    return true;
}

int LNext(List *plist, LData *pdata)
{
    if (plist->cur->next == NULL)
        return false;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;

    return true;
}

LData LRemove(List *plist)
{
    LData target = plist->cur->data;

    plist->before->next = plist->cur->next;
    free(plist->cur);
    plist->cur = plist->before;

    (plist->numOfData)--;

    return target;
}

int LCount(List *plist)
{
    return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}
