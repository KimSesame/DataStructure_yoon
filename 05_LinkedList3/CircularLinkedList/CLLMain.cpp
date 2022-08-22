#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

int main(void)
{
    CircularList<int> list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    list.print();

    list.del(2);
    list.del(4);

    list.print();

    return 0;
}