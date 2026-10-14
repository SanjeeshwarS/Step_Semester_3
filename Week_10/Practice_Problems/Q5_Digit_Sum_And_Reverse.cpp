#include <iostream>
using namespace std;

int main() {
    long long number;
    cin >> number;

    long long sum = 0;
    long long reversed = 0;

    while (number > 0) {
        int digit = number % 10;

        sum += digit;
        reversed = reversed * 10 + digit;

        number /= 10;
    }

    cout << "Sum of digits: " << sum << endl;
    cout << "Reverse: " << reversed << endl;

    return 0;
}
