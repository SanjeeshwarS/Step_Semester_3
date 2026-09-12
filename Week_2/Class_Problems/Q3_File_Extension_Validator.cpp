#include <bits/stdc++.h>
using namespace std;

string validateFileExtension(string filename)
{
    int position = filename.find_last_of('.');

    if (position == string::npos)
        return "Rejected — invalid file type";

    string extension = filename.substr(position + 1);

    if (extension == "pdf" ||
        extension == "PDF" ||
        extension == "docx" ||
        extension == "DOCX" ||
        extension == "zip" ||
        extension == "ZIP")
    {
        return "Accepted";
    }

    return "Rejected — invalid file type";
}

int main()
{
    string filename;

    cout << "Enter filename: ";
    cin >> filename;

    cout << validateFileExtension(filename) << endl;

    return 0;
}