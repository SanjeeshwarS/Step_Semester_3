#include <bits/stdc++.h>
using namespace std;

void findLongestStreak(string signalLog)
{
    int current = 1;
    int longest = 1;
    char color = signalLog[0];

    for (int i = 1; i < signalLog.size(); i++)
    {
        if (signalLog[i] == signalLog[i - 1])
        {
            current++;
        }
        else
        {
            current = 1;
        }

        if (current > longest)
        {
            longest = current;
            color = signalLog[i];
        }
    }

    cout << "Longest Streak: '"
         << color
         << "' repeated "
         << longest
         << " times" << endl;
}

int main()
{
    string signalLog = "RRGGGYRR";

    findLongestStreak(signalLog);

    return 0;
}