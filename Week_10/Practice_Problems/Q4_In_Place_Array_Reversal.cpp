#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void reverseInPlace(vector<int>& tokens) {
    int left = 0;
    int right = tokens.size() - 1;

    while (left < right) {
        swap(tokens[left], tokens[right]);
        left++;
        right--;
    }
}

void printList(const vector<int>& values) {
    cout << "[";

    for (size_t i = 0; i < values.size(); i++) {
        cout << values[i];

        if (i != values.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

int main() {
    vector<int> tokens = {11, 22, 33, 44};

    reverseInPlace(tokens);
    printList(tokens);

    return 0;
}
