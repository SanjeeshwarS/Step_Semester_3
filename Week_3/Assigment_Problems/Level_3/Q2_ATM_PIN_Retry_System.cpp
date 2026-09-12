#include <bits/stdc++.h>
using namespace std;

void atmPinRetry(string correctPin, string attempts[])
{
    int count = 0;
    bool success = false;

    while (count < 3 && !success)
    {
        if (attempts[count] == correctPin)
        {
            success = true;
            cout << "PIN accepted" << endl;
            break;
        }

        count++;
    }

    if (!success)
        cout << "Card blocked — too many incorrect attempts" << endl;
}

int main()
{
    string correctPin = "4821";

    string attempts[] = {
        "1111",
        "4821",
        "2222"
    };

    atmPinRetry(correctPin, attempts);

    return 0;
}