#include <iostream>
#include <string>
using namespace std;

class BookInventory {
    string title;
    string author;
    int copiesAvailable;

public:
    BookInventory(string t, string a, int c) {
        title = t;
        author = a;
        copiesAvailable = c;
    }

    void printEntry() {
        cout << title << " by " << author << " - "
             << copiesAvailable << " copies available" << endl;
    }
};

int main() {
    BookInventory books[] = {
        BookInventory("Clean Code", "Robert C. Martin", 3),
        BookInventory("Effective Java", "Joshua Bloch", 5),
        BookInventory("Refactoring", "Martin Fowler", 0),
        BookInventory("Design Patterns", "GoF", 2)
    };

    for (int i = 0; i < 4; i++) {
        books[i].printEntry();
    }

    return 0;
}