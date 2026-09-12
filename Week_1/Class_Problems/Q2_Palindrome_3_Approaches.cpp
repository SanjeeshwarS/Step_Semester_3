#include <bits/stdc++.h>
using namespace std;

bool isPalindromeIterative(string text)
{
    int left = 0;
    int right = text.size() - 1;

    while (left < right)
    {
        if (text[left] != text[right])
            return false;

        left++;
        right--;
    }

    return true;
}

bool isPalindromeRecursive(string text, int left, int right)
{
    if (left >= right)
        return true;

    if (text[left] != text[right])
        return false;

    return isPalindromeRecursive(text, left + 1, right - 1);
}

bool isPalindromeArrayReversal(string text)
{
    string reversed = text;

    reverse(reversed.begin(), reversed.end());

    return text == reversed;
}

int main()
{
    string text;

    cout << "Enter a string: ";
    getline(cin, text);

    bool iterative = isPalindromeIterative(text);
    bool recursive = isPalindromeRecursive(text, 0, text.size() - 1);
    bool reversed = isPalindromeArrayReversal(text);

    cout << "Iterative: "
         << (iterative ? "Palindrome" : "Not Palindrome")
         << endl;

    cout << "Recursive: "
         << (recursive ? "Palindrome" : "Not Palindrome")
         << endl;

    cout << "Array Reversal: "
         << (reversed ? "Palindrome" : "Not Palindrome")
         << endl;

    return 0;
}