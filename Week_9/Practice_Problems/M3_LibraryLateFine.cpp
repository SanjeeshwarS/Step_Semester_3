#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <algorithm>
using namespace std;

class LibraryItem {
protected:
    string title;
    int daysLate;

public:
    LibraryItem(string t, int days) : title(t), daysLate(days) {
    }

    virtual ~LibraryItem() {
    }

    string getTitle() const {
        return title;
    }

    virtual double fine() const = 0;
};

class Book : public LibraryItem {
public:
    Book(string t, int days) : LibraryItem(t, days) {
    }

    double fine() const override {
        return 2.0 * daysLate;
    }
};

class Dvd : public LibraryItem {
public:
    Dvd(string t, int days) : LibraryItem(t, days) {
    }

    double fine() const override {
        return min(5.0 * daysLate, 50.0);
    }
};

class Magazine : public LibraryItem {
public:
    Magazine(string t, int days) : LibraryItem(t, days) {
    }

    double fine() const override {
        return 1.0 * daysLate;
    }
};

int main() {
    map<string, function<unique_ptr<LibraryItem>(string, int)>> factory = {
        {"BOOK", [](string t, int d) { return unique_ptr<LibraryItem>(new Book(t, d)); }},
        {"DVD", [](string t, int d) { return unique_ptr<LibraryItem>(new Dvd(t, d)); }},
        {"MAGAZINE", [](string t, int d) { return unique_ptr<LibraryItem>(new Magazine(t, d)); }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<LibraryItem>> items;

    for (int i = 0; i < n; i++) {
        string type, title;
        int days;
        cin >> type >> title >> days;
        items.push_back(factory[type](title, days));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& item : items) {
        double fine = item->fine();
        cout << item->getTitle() << ": " << fine << endl;
        total += fine;
    }

    cout << "Total Fines: " << total << endl;

    return 0;
}
