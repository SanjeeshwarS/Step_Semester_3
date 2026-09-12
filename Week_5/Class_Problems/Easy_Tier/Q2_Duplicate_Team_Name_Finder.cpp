#include <bits/stdc++.h>
using namespace std;

string findDuplicateTeam(vector<string> teamNames)
{
    for (int i = 0; i < teamNames.size(); i++)
    {
        for (int j = i + 1; j < teamNames.size(); j++)
        {
            if (teamNames[i] == teamNames[j])
            {
                return "Duplicate Found: " + teamNames[i];
            }
        }
    }

    return "No Duplicates Found";
}

int main()
{
    vector<string> teamNames = {
        "ByteForce",
        "CodeCrafters",
        "ByteForce"
    };

    cout << findDuplicateTeam(teamNames) << endl;

    return 0;
}