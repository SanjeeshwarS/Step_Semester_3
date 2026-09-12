#include <bits/stdc++.h>
using namespace std;

void checkArmstrong(int number)
{
    int origNumber = number;
    int sum = 0;

    while (number != 0)
    {
        int digit = number % 10;

        sum += digit * digit * digit;

        number /= 10;
    }

    if (sum == origNumber)
        cout << "Is the number " << origNumber
             << " an Armstrong number? Yes" << endl;
    else
        cout << "Is the number " << origNumber
             << " an Armstrong number? No" << endl;
}

int main()
{
    int number;

    cout << "Enter number: ";
    cin >> number;

    checkArmstrong(number);

    return 0;
}