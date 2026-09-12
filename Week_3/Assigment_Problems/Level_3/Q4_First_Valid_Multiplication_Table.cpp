#include <bits/stdc++.h>
using namespace std;

void generateFirstValidTable(int candidates[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (candidates[i] < 1)
        {
            cout << "Skipping invalid number: "
                 << candidates[i] << endl;

            continue;
        }

        for (int j = 1; j <= 10; j++)
        {
            cout << candidates[i]
                 << " x " << j
                 << " = " << candidates[i] * j
                 << endl;
        }

        break;
    }
}

int main()
{
    int candidates[] = {-3, 0, 7, 9};

    int n = sizeof(candidates) / sizeof(candidates[0]);

    generateFirstValidTable(candidates, n);

    return 0;
}
