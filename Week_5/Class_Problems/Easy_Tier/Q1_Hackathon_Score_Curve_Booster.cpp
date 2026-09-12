#include <bits/stdc++.h>
using namespace std;

void curveScores(vector<int>& scores, int bonus)
{
    for (int& score : scores)
    {
        score += bonus;
    }
}

int main()
{
    vector<int> scores = {70, 85, 60};

    curveScores(scores, 10);

    cout << "[";
    for (int i = 0; i < scores.size(); i++)
    {
        cout << scores[i];

        if (i != scores.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}