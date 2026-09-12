#include <bits/stdc++.h>
using namespace std;

void checkPinLength(string pin)
{
    if (pin.length() != 4)
        cout << "Invalid PIN — must be exactly 4 digits." << endl;
    else
        cout << "PIN length OK." << endl;
}

int main()
{
    string pin;

    cout << "Enter PIN: ";
    cin >> pin;

    checkPinLength(pin);

    return 0;
}