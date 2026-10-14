#include <iostream>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) {
        return false;
    }

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    long long number;

    while (cin >> number) {
        cout << number << (isPrime(number) ? " is prime" : " is not prime") << endl;
    }

    return 0;
}
