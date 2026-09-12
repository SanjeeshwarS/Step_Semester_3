#include <bits/stdc++.h>
using namespace std;

void checkDuplicateSeats(int seatNumbers[], int n)
{
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (seatNumbers[i] == seatNumbers[j])
            {
                bool alreadyPrinted = false;

                for (int k = 0; k < i; k++)
                {
                    if (seatNumbers[k] == seatNumbers[i])
                    {
                        alreadyPrinted = true;
                        break;
                    }
                }

                if (!alreadyPrinted)
                {
                    cout << "Duplicate Seat Number Found: "
                         << seatNumbers[i] << endl;

                    found = true;
                }
            }
        }
    }

    if (!found)
    {
        cout << "No Duplicate Seats Found" << endl;
    }
}

int main()
{
    int seatNumbers[] = {101, 102, 103, 102, 105};

    int n = sizeof(seatNumbers) / sizeof(seatNumbers[0]);

    checkDuplicateSeats(seatNumbers, n);

    return 0;
}