#include <bits/stdc++.h>
using namespace std;

string normalizeReference(string raw)
{
    raw = raw.substr(raw.find_first_not_of(' '),
                     raw.find_last_not_of(' ') -
                     raw.find_first_not_of(' ') + 1);

    if (raw.size() < 3)
        return raw;

    string bankCode = raw.substr(0, 3);
    string remaining = raw.substr(3);

    for (char &ch : bankCode)
        ch = toupper(ch);

    return bankCode + remaining;
}

string validateAndFormat(string reference)
{
    if (reference.size() != 14)
        return "Invalid: wrong length";

    for (int i = 0; i < 3; i++)
    {
        if (!isalpha(reference[i]))
            return "Invalid: bank code must be 3 letters";
    }

    for (int i = 3; i < 14; i++)
    {
        if (!isdigit(reference[i]))
            return "Invalid: body must contain only digits";
    }

    string bankCode = reference.substr(0, 3);
    string date = reference.substr(3, 6);
    string sequence = reference.substr(9, 5);

    string formattedDate =
        date.substr(0, 2) + "/" +
        date.substr(2, 2) + "/" +
        date.substr(4, 2);

    string result = "[" + bankCode + "] DATE: ";
    result += formattedDate;
    result += " | SEQ: ";
    result += sequence;

    return result;
}

int main()
{
    string raw;

    cout << "Enter transaction reference: ";
    getline(cin, raw);

    string normalized = normalizeReference(raw);

    cout << validateAndFormat(normalized) << endl;

    return 0;
}