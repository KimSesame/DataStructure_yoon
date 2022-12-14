#include <iostream>
#include "Point.h"

using namespace std;

void SetPointPos(Point *ppos, int xpos, int ypos)
{
    ppos->xpos = xpos;
    ppos->ypos = ypos;
}

void ShowPointPos(Point *ppos)
{
    cout << "[" << ppos->xpos << ", " << ppos->ypos << "]" << endl;
}

int PointCmp(Point *pos1, Point *pos2)
{
    if (pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)
        return 0;
    else if (pos1->xpos == pos2->xpos)
        return 1;
    else if (pos1->ypos == pos2->ypos)
        return 2;
    else
        return -1;
}