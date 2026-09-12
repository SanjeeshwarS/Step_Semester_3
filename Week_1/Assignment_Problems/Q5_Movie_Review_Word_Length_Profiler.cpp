#include <bits/stdc++.h>
using namespace std;

void classifyWordLengths(string review)
{
    stringstream ss(review);
    string word;

    int shortCount = 0;
    int mediumCount = 0;
    int longCount = 0;

    while (ss >> word)
    {
        int length = word.size();

        if (length >= 1 && length <= 4)
        {
            shortCount++;
        }
        else if (length >= 5 && length <= 8)
        {
            mediumCount++;
        }
        else
        {
            longCount++;
        }
    }

    cout << "Short: " << shortCount
         << " | Medium: " << mediumCount
         << " | Long: " << longCount << endl;
}

int main()
{
    string review =
        "This movie was absolutely fantastic and thrilling";

    classifyWordLengths(review);

    return 0;
}