#include <bits/stdc++.h>
using namespace std;

void printNumbersUpToN(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    int n;

    cout << "Enter N: ";
    cin >> n;

    printNumbersUpToN(n);

    return 0;
}
