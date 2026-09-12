#include <bits/stdc++.h>
using namespace std;

void printFilteredWordFrequency(string feedback)
{
    for (char &ch : feedback)
    {
        ch = tolower(ch);

        if (ch == '.' || ch == ',' || ch == '!' ||
            ch == '?' || ch == ';' || ch == ':')
        {
            ch = ' ';
        }
    }

    set<string> stopWords = {
        "the", "was", "and", "a", "is", "of", "in"
    };

    map<string, int> frequency;

    stringstream ss(feedback);
    string word;

    while (ss >> word)
    {
        if (stopWords.find(word) == stopWords.end())
        {
            frequency[word]++;
        }
    }

    vector<pair<string, int>> words;

    for (auto item : frequency)
    {
        words.push_back(item);
    }

    sort(words.begin(), words.end(),
         [](const pair<string, int> &a,
            const pair<string, int> &b)
         {
             return a.second > b.second;
         });

    for (auto item : words)
    {
        cout << item.first << ": "
             << item.second << endl;
    }
}

int main()
{
    string feedback;

    cout << "Enter feedback: ";
    getline(cin, feedback);

    printFilteredWordFrequency(feedback);

    return 0;
}