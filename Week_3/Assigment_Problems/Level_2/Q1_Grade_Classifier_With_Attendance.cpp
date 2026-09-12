#include <bits/stdc++.h>
using namespace std;

void classifyWithAttendance(int marks, int attendance)
{
    bool eligible = attendance >= 75 && marks >= 40;

    if (!eligible)
    {
        cout << "Detained" << endl;
        return;
    }

    if (marks >= 90)
        cout << "Grade: A" << endl;
    else if (marks >= 75)
        cout << "Grade: B" << endl;
    else if (marks >= 60)
        cout << "Grade: C" << endl;
    else
        cout << "Grade: D" << endl;
}

int main()
{
    int marks, attendance;

    cout << "Enter marks: ";
    cin >> marks;

    cout << "Enter attendance: ";
    cin >> attendance;

    classifyWithAttendance(marks, attendance);

    return 0;
}