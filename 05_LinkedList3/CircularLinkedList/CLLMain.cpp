#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

int main(void)
{
    CircularList<int> list;
    int data;
    int choice = 0;

    while (choice != 4)
    {
        cout << "(1)Print, (2)Append, (3)Delete, (4)Quit: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.print();
            break;
        case 2:
            cin >> data;
            list.append(data);
            break;
        case 3:
            cin >> data;
            list.del(data);
            break;
        default:
            break;
        }
    }

    return 0;
}