#include <bits/stdc++.h>
using namespace std;

void simulateTrafficSignal(int cycles)
{
    int state = 0;

    for (int i = 0; i < cycles; i++)
    {
        switch (state)
        {
            case 0:
                cout << "Red - Stop" << endl;
                break;

            case 1:
                cout << "Green - Go" << endl;
                break;

            case 2:
                cout << "Yellow - Prepare to stop" << endl;
                break;
        }

        state = (state + 1) % 3;
    }
}

int main()
{
    int cycles;

    cout << "Enter number of cycles: ";
    cin >> cycles;

    simulateTrafficSignal(cycles);

    return 0;
}