#include <bits/stdc++.h>
using namespace std;

vector<int> findTopThreeScores(vector<int> scores)
{
    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;

    for (int score : scores)
    {
        if (score >= first)
        {
            third = second;
            second = first;
            first = score;
        }
        else if (score >= second)
        {
            third = second;
            second = score;
        }
        else if (score > third)
        {
            third = score;
        }
    }

    return {first, second, third};
}

int main()
{
    vector<int> scores = {
        45, 82, 79, 90, 33, 90, 61
    };

    vector<int> result = findTopThreeScores(scores);

    cout << "[";

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;

    return 0;
}