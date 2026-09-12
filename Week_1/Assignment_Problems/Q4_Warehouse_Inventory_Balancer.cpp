#include <bits/stdc++.h>
using namespace std;

void analyzeInventory(int sectionA[], int sectionB[], int n)
{
    int totalA = 0;
    int totalB = 0;

    for (int i = 0; i < n; i++)
    {
        totalA += sectionA[i];
        totalB += sectionB[i];
    }

    int highest = sectionA[0];
    char section = 'A';
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (sectionA[i] > highest)
        {
            highest = sectionA[i];
            section = 'A';
            index = i;
        }

        if (sectionB[i] > highest)
        {
            highest = sectionB[i];
            section = 'B';
            index = i;
        }
    }

    cout << "Section A Total: " << totalA
         << " | Section B Total: " << totalB;

    if (totalA == totalB)
    {
        cout << " | Status: Balanced";
    }
    else
    {
        cout << " | Status: Not Balanced";
    }

    cout << " | Highest Quantity: "
         << highest
         << " (Section " << section
         << ", Item " << index + 1
         << ")" << endl;
}

int main()
{
    int sectionA[] = {20, 15, 30};
    int sectionB[] = {25, 10, 30};

    int n = sizeof(sectionA) / sizeof(sectionA[0]);

    analyzeInventory(sectionA, sectionB, n);

    return 0;
}