#include <bits/stdc++.h>
using namespace std;

double rowAverage(vector<int> row)
{
    double sum = 0;

    for (int value : row)
    {
        sum += value;
    }

    return sum / row.size();
}

string classifyMatches(vector<vector<int>> runsPerOver,
                       int threshold)
{
    string result;

    for (int i = 0; i < runsPerOver.size(); i++)
    {
        double average = rowAverage(runsPerOver[i]);

        if (average >= threshold)
        {
            result += "Match " + to_string(i) +
                      ": Power Surge";
        }
        else
        {
            result += "Match " + to_string(i) +
                      ": Normal";
        }

        if (i != runsPerOver.size() - 1)
            result += " | ";
    }

    return result;
}

int main()
{
    vector<vector<int>> runsPerOver = {
        {4, 6, 8},
        {10, 12, 14},
        {2, 3, 1}
    };

    int threshold = 8;

    cout << classifyMatches(runsPerOver, threshold)
         << endl;

    return 0;
}