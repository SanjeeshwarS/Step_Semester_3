#include <iostream>
#include <vector>
using namespace std;

void countEvenOdd(const vector<int>& numbers) {
    int even = 0;
    int odd = 0;

    for (int num : numbers) {
        if (num % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    cout << "Even: " << even << endl;
    cout << "Odd: " << odd << endl;
}

int main() {
    vector<int> numbers = {3, 8, 12, 5, 7, 10};

    countEvenOdd(numbers);

    return 0;
}
