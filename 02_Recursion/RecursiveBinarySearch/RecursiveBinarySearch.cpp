#include <iostream>
using namespace std;

int BSearchRecur(int ar[], int first, int last, int target);

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx = 0;

    idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
    if (idx == -1)
        cout << "탐색 실패" << endl;
    else
        cout << idx << "번 위치" << endl;

    idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 6);
    if (idx == -1)
        cout << "탐색 실패" << endl;
    else
        cout << idx << "번 위치" << endl;

    return 0;
}

int BSearchRecur(int ar[], int first, int last, int target)
{
    // Base Case
    if (first > last) // Unvalid search range
        return -1;

    // Recursive Case
    int mid = (first + last) / 2;

    if (ar[mid] == target)
        return mid; // return index of target

    if (target < ar[mid])
        return BSearchRecur(ar, first, mid - 1, target);
    else if (target > ar[mid])
        return BSearchRecur(ar, mid + 1, last, target);
    return -1;
}