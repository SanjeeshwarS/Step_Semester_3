#include <bits/stdc++.h>
using namespace std;

void sumOfNaturalNumbers(int n)
{
    int sum = 0;
    int i = 1;

    while (i <= n)
    {
        sum += i;
        i++;
    }

    cout << "Sum of numbers from 1 to "
         << n << " = " << sum << endl;
}

int main()
{
    int n;

    cout << "Enter N: ";
    cin >> n;

    sumOfNaturalNumbers(n);

    return 0;
}