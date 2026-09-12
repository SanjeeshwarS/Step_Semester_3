#include <bits/stdc++.h>
using namespace std;

void applyMultipliers(vector<double>& playerScores,
                      int captainIndex,
                      int viceCaptainIndex)
{
    playerScores[captainIndex] *= 2.0;
    playerScores[viceCaptainIndex] *= 1.5;
}

int main()
{
    vector<double> scores = {40, 55, 30, 62};

    applyMultipliers(scores, 1, 3);

    cout << "[";

    for (int i = 0; i < scores.size(); i++)
    {
        cout << fixed << setprecision(1) << scores[i];

        if (i != scores.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;

    return 0;
}