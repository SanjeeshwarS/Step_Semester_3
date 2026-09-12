#include <bits/stdc++.h>
using namespace std;

void checkPrime(int number)
{
    bool prime = true;

    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            prime = false;
            break;
        }
    }

    if (prime)
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;
}

int main()
{
    int number;

    cout << "Enter number: ";
    cin >> number;

    checkPrime(number);

    return 0;
}