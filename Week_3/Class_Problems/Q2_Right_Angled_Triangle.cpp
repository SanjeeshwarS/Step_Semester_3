#include <bits/stdc++.h>
using namespace std;

void printTriangle(int rows)
{
    cout << "The right-angled triangle pattern for "
         << rows << " rows is" << endl;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

int main()
{
    int rows;

    cout << "Enter number of rows: ";
    cin >> rows;

    printTriangle(rows);

    return 0;
}