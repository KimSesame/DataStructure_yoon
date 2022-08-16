#include <iostream>
#include "ArrayList.h"
#include "Point.h"

using namespace std;

int main(void)
{
    List list;
    Point cmpPos;
    Point *ppos;

    ListInit(&list);

    // Insert 4 points
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);

    // PRINT
    cout << "Current num of data: " << LCount(&list) << endl;

    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while (LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    cout << endl;

    // Remove data whose xpos is 2
    cmpPos.xpos = 2;
    cmpPos.ypos = 0;

    if (LFirst(&list, &ppos))
    {
        do
        {
            if (PointCmp(ppos, &cmpPos) == 1)
            {
                ppos = LRemove(&list);
                free(ppos);
            }
        } while (LNext(&list, &ppos));
    }

    // PRINT
    cout << "Current num of data: " << LCount(&list) << endl;

    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while (LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    cout << endl;

    return 0;
}