#include <iostream>
#include <string>
using namespace std;

string reverseWord(const string& word) {
    string reversed;
    reversed.reserve(word.size());

    for (int i = word.size() - 1; i >= 0; i--) {
        reversed += word[i];
    }

    return reversed;
}

int main() {
    string word;

    while (cin >> word) {
        string reversed = reverseWord(word);

        cout << reversed << " - "
             << (reversed == word ? "palindrome" : "not a palindrome") << endl;
    }

    return 0;
}
