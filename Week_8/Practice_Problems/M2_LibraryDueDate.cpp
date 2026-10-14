#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
using namespace std;

struct Date {
    int year;
    int month;
    int day;

    static bool isLeap(int y) {
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }

    static int daysInMonth(int y, int m) {
        static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && isLeap(y)) {
            return 29;
        }
        return days[m - 1];
    }

    Date plusDays(int count) const {
        Date d = *this;
        d.day += count;

        while (d.day > daysInMonth(d.year, d.month)) {
            d.day -= daysInMonth(d.year, d.month);
            d.month++;

            if (d.month > 12) {
                d.month = 1;
                d.year++;
            }
        }

        return d;
    }

    string toString() const {
        stringstream ss;
        ss << year << "-"
           << setw(2) << setfill('0') << month << "-"
           << setw(2) << setfill('0') << day;
        return ss.str();
    }
};

class LibraryItem {
protected:
    string title;

public:
    LibraryItem(string t) : title(t) {
    }

    virtual ~LibraryItem() {
    }

    virtual int loanDays() const = 0;

    string getTitle() const {
        return title;
    }

    Date dueDate(const Date& today) const {
        return today.plusDays(loanDays());
    }
};

class Book : public LibraryItem {
public:
    Book(string t) : LibraryItem(t) {
    }

    int loanDays() const override {
        return 14;
    }
};

class Dvd : public LibraryItem {
public:
    Dvd(string t) : LibraryItem(t) {
    }

    int loanDays() const override {
        return 7;
    }
};

class Magazine : public LibraryItem {
public:
    Magazine(string t) : LibraryItem(t) {
    }

    int loanDays() const override {
        return 3;
    }
};

int main() {
    map<string, function<unique_ptr<LibraryItem>(string)>> factory = {
        {"BOOK", [](string t) { return unique_ptr<LibraryItem>(new Book(t)); }},
        {"DVD", [](string t) { return unique_ptr<LibraryItem>(new Dvd(t)); }},
        {"MAGAZINE", [](string t) { return unique_ptr<LibraryItem>(new Magazine(t)); }}
    };

    const Date today = {2023, 10, 26};

    int n;
    cin >> n;

    vector<unique_ptr<LibraryItem>> items;

    for (int i = 0; i < n; i++) {
        string type, title;
        cin >> type >> quoted(title);
        items.push_back(factory[type](title));
    }

    for (const auto& item : items) {
        cout << item->getTitle() << ": "
             << item->dueDate(today).toString() << endl;
    }

    return 0;
}
