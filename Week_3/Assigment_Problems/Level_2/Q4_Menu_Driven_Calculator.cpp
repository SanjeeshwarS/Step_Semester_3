#include <bits/stdc++.h>
using namespace std;

void calculate(double a, double b, char operation)
{
    switch (operation)
    {
        case '+':
            cout << "Result: " << a + b << endl;
            break;

        case '-':
            cout << "Result: " << a - b << endl;
            break;

        case '*':
            cout << "Result: " << a * b << endl;
            break;

        case '/':
            if (b == 0)
                cout << "Cannot divide by zero" << endl;
            else
                cout << "Result: " << a / b << endl;
            break;

        default:
            cout << "Invalid operator" << endl;
    }
}

int main()
{
    double a, b;
    char operation;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "Enter operator: ";
    cin >> operation;

    calculate(a, b, operation);

    return 0;
}