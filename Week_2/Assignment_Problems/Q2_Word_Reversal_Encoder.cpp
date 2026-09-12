#include <bits/stdc++.h>
using namespace std;

string reverseEachWord(string sentence)
{
    stringstream ss(sentence);
    string word;
    string result;

    while (ss >> word)
    {
        reverse(word.begin(), word.end());

        if (!result.empty())
            result += " ";

        result += word;
    }

    return result;
}

int main()
{
    string sentence;

    cout << "Enter sentence: ";
    getline(cin, sentence);

    cout << reverseEachWord(sentence) << endl;

    return 0;
}