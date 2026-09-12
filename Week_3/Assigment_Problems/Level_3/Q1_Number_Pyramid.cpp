#include <bits/stdc++.h>
using namespace std;

void printNumberPyramid(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << row << " ";
        }

        cout << endl;
    }
}

int main()
{
    int n;

    cout << "Enter number of rows: ";
    cin >> n;

    printNumberPyramid(n);

    return 0;
}