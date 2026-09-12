#include <bits/stdc++.h>
using namespace std;

string maskPhoneNumber(string phone)
{
    if (phone.size() != 10)
        return "Invalid phone number";

    for (char ch : phone)
    {
        if (!isdigit(ch))
            return "Invalid phone number";
    }

    stringBuilder:
    string masked = "XXXXXX-" + phone.substr(6);

    return masked;
}

int main()
{
    string phone;

    cout << "Enter phone number: ";
    cin >> phone;

    cout << maskPhoneNumber(phone) << endl;

    return 0;
}