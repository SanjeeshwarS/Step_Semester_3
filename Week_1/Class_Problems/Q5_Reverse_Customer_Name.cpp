#include <bits/stdc++.h>
using namespace std;

string reverseCustomerName(string customerName)
{
    string reversed;

    for (int i = customerName.size() - 1; i >= 0; i--)
    {
        reversed += customerName[i];
    }

    return reversed;
}

int main()
{
    string customerName;

    cout << "Enter customer name: ";
    getline(cin, customerName);

    string reversedName = reverseCustomerName(customerName);

    cout << "Original Name: " << customerName << endl;
    cout << "Reversed Name: " << reversedName << endl;

    return 0;
}