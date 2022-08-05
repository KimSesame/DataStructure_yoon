#include <iostream>
using namespace std;

void hanoi(int n, int start, int end);
void move(int n, int start, int end);

int main(void)
{
    int n = 0;
    int start, end;

    cout << "Enter the number of disks of hanoi: ";
    cin >> n;
    cout << "Enter the number of start and end: ";
    cin >> start >> end;

    hanoi(n, start, end);

    return 0;
}

void hanoi(int n, int start, int end)
{
    // Base Case
    if (n == 0)
        return;

    // Recursive Case
    int mid = 6 - (start + end);

    hanoi(n - 1, start, mid);
    move(n, start, end);
    hanoi(n - 1, mid, end);

    return;
}

void move(int n, int start, int end)
{
    cout << "Move disk no." << n << " from " << start << " to " << end << endl;
}