#include <bits/stdc++.h>
using namespace std;

void guessTheNumber(int secretNumber, int maxTries, int guesses[])
{
    int tries = 0;
    bool guessed = false;

    while (tries < maxTries && !guessed)
    {
        int guess = guesses[tries];

        if (guess > secretNumber)
        {
            cout << "Too high" << endl;
        }
        else if (guess < secretNumber)
        {
            cout << "Too low" << endl;
        }
        else
        {
            cout << "Correct! You guessed it" << endl;
            guessed = true;
            break;
        }

        tries++;
    }

    if (!guessed)
    {
        cout << "Out of tries — the number was "
             << secretNumber << endl;
    }
}

int main()
{
    int secretNumber = 42;
    int maxTries = 4;

    int guesses[] = {
        20,
        60,
        42
    };

    guessTheNumber(secretNumber, maxTries, guesses);

    return 0;
}