#include <bits/stdc++.h>
using namespace std;

void checkTypingAccuracy(string original, string typed)
{
    int matched = 0;
    int firstMismatch = -1;

    for (int i = 0; i < original.size(); i++)
    {
        if (original[i] == typed[i])
        {
            matched++;
        }
        else if (firstMismatch == -1)
        {
            firstMismatch = i;
        }
    }

    double accuracy = (matched * 100.0) / original.size();

    cout << fixed << setprecision(2);

    cout << "Matched: " << matched
         << "/" << original.size();

    cout << " | Accuracy: " << accuracy << "%";

    if (firstMismatch == -1)
    {
        cout << " | No Mismatches" << endl;
    }
    else
    {
        cout << " | First Mismatch at position "
             << firstMismatch + 1
             << " ('" << original[firstMismatch]
             << "' vs '" << typed[firstMismatch]
             << "')" << endl;
    }
}

int main()
{
    string original = "hello world";
    string typed = "hello worlt";

    checkTypingAccuracy(original, typed);

    return 0;
}