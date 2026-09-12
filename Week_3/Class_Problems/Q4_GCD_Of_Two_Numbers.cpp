#include <bits/stdc++.h>
using namespace std;

void findGCD(int number1, int number2)
{
    int original1 = number1;
    int original2 = number2;

    while (number2 != 0)
    {
        int remainder = number1 % number2;

        number1 = number2;
        number2 = remainder;
    }

    cout << "The GCD of "
         << original1 << " and "
         << original2 << " is "
         << number1 << endl;
}

int main()
{
    int number1, number2;

    cout << "Enter first number: ";
    cin >> number1;

    cout << "Enter second number: ";
    cin >> number2;

    findGCD(number1, number2);

    return 0;
}