#include <bits/stdc++.h>
using namespace std;

double rowAverage(const vector<int>& row)
{
    double sum = 0;

    for (int score : row)
    {
        sum += score;
    }

    return sum / row.size();
}

string classifyRows(const vector<vector<int>>& seatingScores,
                    int threshold)
{
    string result;

    for (int i = 0; i < seatingScores.size(); i++)
    {
        double average = rowAverage(seatingScores[i]);

        if (average < threshold)
        {
            result += "Row " + to_string(i) + ": Quiet Zone";
        }
        else
        {
            result += "Row " + to_string(i) + ": Buzzing Zone";
        }

        if (i != seatingScores.size() - 1)
            result += " | ";
    }

    return result;
}

int main()
{
    vector<vector<int>> seatingScores = {
        {40, 50, 45},
        {85, 90, 95},
        {30, 20, 25}
    };

    int threshold = 60;

    cout << classifyRows(seatingScores, threshold)
         << endl;

    return 0;
}