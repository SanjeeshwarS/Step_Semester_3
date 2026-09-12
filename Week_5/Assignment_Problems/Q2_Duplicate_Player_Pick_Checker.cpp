#include <bits/stdc++.h>
using namespace std;

string findDuplicatePick(vector<string> playerNames)
{
    for (int i = 0; i < playerNames.size(); i++)
    {
        for (int j = i + 1; j < playerNames.size(); j++)
        {
            if (playerNames[i] == playerNames[j])
            {
                return "Duplicate Found: " + playerNames[i];
            }
        }
    }

    return "No Duplicates Found";
}

int main()
{
    vector<string> playerNames = {
        "Kohli",
        "Bumrah",
        "Kohli",
        "Rohit"
    };

    cout << findDuplicatePick(playerNames) << endl;

    return 0;
}