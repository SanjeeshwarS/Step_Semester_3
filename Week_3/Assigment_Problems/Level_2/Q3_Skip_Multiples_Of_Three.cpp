#include <bits/stdc++.h>
using namespace std;

void printSkippingMultiplesOfThree()
{
    for (int i = 1; i <= 20; i++)
    {
        if (i % 3 == 0)
            continue;

        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    printSkippingMultiplesOfThree();

    return 0;
}