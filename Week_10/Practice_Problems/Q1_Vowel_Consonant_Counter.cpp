#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    string word;
    cin >> word;

    int vowels = 0;
    int consonants = 0;

    for (char ch : word) {
        if (isVowel(ch)) {
            vowels++;
        } else {
            consonants++;
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;

    return 0;
}
