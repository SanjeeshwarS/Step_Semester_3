#include <bits/stdc++.h>
using namespace std;

string getBmiStatus(double bmi)
{
    if (bmi < 18.5)
        return "Underweight";
    else if (bmi <= 24.9)
        return "Normal";
    else if (bmi <= 29.9)
        return "Overweight";
    else
        return "Obese";
}

void printWellnessReport(double heights[], double weights[], int n)
{
    cout << left
         << setw(10) << "Person"
         << setw(15) << "Height"
         << setw(15) << "Weight"
         << setw(10) << "BMI"
         << "Status" << endl;

    for (int i = 0; i < n; i++)
    {
        double bmi = weights[i] / (heights[i] * heights[i]);

        cout << left
             << setw(10) << i + 1
             << setw(15) << heights[i]
             << setw(15) << weights[i]
             << setw(10) << fixed << setprecision(2) << bmi
             << getBmiStatus(bmi)
             << endl;
    }
}

int main()
{
    double heights[] = {
        1.75, 1.60, 1.68, 1.72, 1.80,
        1.65, 1.70, 1.58, 1.77, 1.62
    };

    double weights[] = {
        70, 90, 60, 85, 95,
        50, 78, 48, 82, 68
    };

    int n = sizeof(heights) / sizeof(heights[0]);

    printWellnessReport(heights, weights, n);

    return 0;
}