#include <bits/stdc++.h>
using namespace std;

void checkPalindrome(int number)
{
    int origNumber = number;
    int reversedNumber = 0;

    while (number != 0)
    {
        int digit = number % 10;

        reversedNumber = reversedNumber * 10 + digit;

        number /= 10;
    }

    if (reversedNumber == origNumber)
        cout << "Is the number " << origNumber
             << " a Palindrome? Yes" << endl;
    else
        cout << "Is the number " << origNumber
             << " a Palindrome? No" << endl;
}

int main()
{
    int number;

    cout << "Enter number: ";
    cin >> number;

    checkPalindrome(number);

    return 0;
}