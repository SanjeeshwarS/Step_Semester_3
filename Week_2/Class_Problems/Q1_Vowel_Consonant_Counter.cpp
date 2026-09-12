#include <bits/stdc++.h>
using namespace std;

void countVowelsAndConsonants(string text)
{
    int vowels = 0;
    int consonants = 0;

    for (char ch : text)
    {
        ch = tolower(ch);

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u')
        {
            vowels++;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            consonants++;
        }
    }

    cout << "Vowels: " << vowels
         << " | Consonants: " << consonants << endl;
}

int main()
{
    string text;

    cout << "Enter text: ";
    getline(cin, text);

    countVowelsAndConsonants(text);

    return 0;
}