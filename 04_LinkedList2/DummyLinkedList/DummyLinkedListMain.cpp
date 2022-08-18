#include <cstdio>
#include "DLinkedList.h"

int WhoisPrecede(int d1, int d2)
{
    if(d1 < d2)
        return 0;
    else
        return 1;
}

int main(void)
{
    // Initialize List
    List list;
    int data;
    ListInit(&list);

    SetSortRule(&list, WhoisPrecede);

    // Insert 5 datas
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    // Print whole datas
    printf("Current Data Counts: %d\n", LCount(&list));
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    //  Delete All 22
    if (LFirst(&list, &data))
    {
        if (data == 22)
            LRemove(&list);

        while (LNext(&list, &data))
        {
            if (data == 22)
                LRemove(&list);
        }
    }

    // Print whole datas
    printf("Current Data Counts: %d\n", LCount(&list));
    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    return 0;
}