#include <bits/stdc++.h>
using namespace std;

void checkVotingEligibility(int age)
{
    bool eligible = age >= 18;

    if (eligible)
        cout << "Eligible to vote" << endl;
    else
        cout << "Not eligible to vote" << endl;
}

int main()
{
    int age;

    cout << "Enter age: ";
    cin >> age;

    checkVotingEligibility(age);

    return 0;
}