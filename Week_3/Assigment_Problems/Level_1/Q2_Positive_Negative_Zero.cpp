#include <bits/stdc++.h>
using namespace std;

void classifyNumber(int number)
{
    if (number > 0)
        cout << "Positive" << endl;
    else if (number < 0)
        cout << "Negative" << endl;
    else
        cout << "Zero" << endl;
}

int main()
{
    int number;

    cout << "Enter number: ";
    cin >> number;

    classifyNumber(number);

    return 0;
}