#include <bits/stdc++.h>
using namespace std;

string findMinMaxSpread(vector<int> scores)
{
    int minimum = scores[0];
    int maximum = scores[0];

    for (int i = 1; i < scores.size(); i++)
    {
        minimum = min(minimum, scores[i]);
        maximum = max(maximum, scores[i]);
    }

    int spread = maximum - minimum;

    return "Min: " + to_string(minimum) +
           " | Max: " + to_string(maximum) +
           " | Spread: " + to_string(spread);
}

int main()
{
    vector<int> scores = {
        45, 82, 79, 90, 33, 90, 61
    };

    cout << findMinMaxSpread(scores) << endl;

    return 0;
}