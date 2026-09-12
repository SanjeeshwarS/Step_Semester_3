#include <bits/stdc++.h>
using namespace std;

void parseStudentRecord(string csvLine)
{
    stringstream ss(csvLine);
    string name, rollNumber, department;

    getline(ss, name, ',');
    getline(ss, rollNumber, ',');
    getline(ss, department, ',');

    if (name.empty() || rollNumber.empty() || department.empty())
    {
        cout << "Invalid Record" << endl;
        return;
    }

    string extra;

    if (getline(ss, extra, ','))
    {
        cout << "Invalid Record" << endl;
        return;
    }

    cout << "Name: " << name
         << " | Roll No: " << rollNumber
         << " | Dept: " << department << endl;
}

int main()
{
    string csvLine;

    cout << "Enter student record: ";
    getline(cin, csvLine);

    parseStudentRecord(csvLine);

    return 0;
}