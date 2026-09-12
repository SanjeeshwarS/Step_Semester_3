#include <bits/stdc++.h>
using namespace std;

void simulateLogin(string correctCode, string attempts[])
{
    bool granted = false;

    for (int i = 0; i < 3; i++)
    {
        if (attempts[i] == correctCode)
        {
            cout << "Access granted on attempt "
                 << i + 1 << endl;

            granted = true;
            break;
        }
    }

    if (!granted)
        cout << "Access denied — all attempts used" << endl;
}

int main()
{
    string correctCode = "1234";

    string attempts[] = {
        "0000",
        "1234",
        "9999"
    };

    simulateLogin(correctCode, attempts);

    return 0;
}