#include <bits/stdc++.h>
using namespace std;

string normalizeCode(string raw)
{
    raw = raw.substr(
        raw.find_first_not_of(' '),
        raw.find_last_not_of(' ') -
        raw.find_first_not_of(' ') + 1
    );

    if (raw.length() < 3)
        return raw;

    string publisher = raw.substr(0, 3);
    string remaining = raw.substr(3);

    for (char &ch : publisher)
        ch = toupper(ch);

    return publisher + remaining;
}

string validateAndFormat(string code)
{
    if (code.length() != 13)
        return "Invalid: wrong length";

    for (int i = 0; i < 3; i++)
    {
        if (!isalpha(code[i]))
            return "Invalid: publisher code must be 3 letters";
    }

    for (int i = 3; i < 13; i++)
    {
        if (!isdigit(code[i]))
            return "Invalid: body must contain only digits";
    }

    string publisher = code.substr(0, 3);
    string year = code.substr(3, 4);
    string catalog = code.substr(7, 6);

    string result = "[" + publisher + "] YEAR: ";
    result += year;
    result += " | CATALOG: ";
    result += catalog;

    return result;
}

int main()
{
    string raw;

    cout << "Enter ISBN-style code: ";
    getline(cin, raw);

    string code = normalizeCode(raw);

    cout << validateAndFormat(code) << endl;

    return 0;
}