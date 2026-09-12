#include <bits/stdc++.h>
using namespace std;

string playRound(string playerMove, string computerMove)
{
    if (playerMove == computerMove)
        return "Draw";

    if ((playerMove == "Rock" && computerMove == "Scissors") ||
        (playerMove == "Paper" && computerMove == "Rock") ||
        (playerMove == "Scissors" && computerMove == "Paper"))
    {
        return "Player Wins";
    }

    return "Computer Wins";
}

int main()
{
    srand(time(0));

    string moves[] = {"Rock", "Paper", "Scissors"};

    string playerMove;
    int wins = 0;
    int losses = 0;
    int draws = 0;

    const int rounds = 5;

    cout << "Round | Player Move | Computer Move | Result" << endl;

    for (int i = 1; i <= rounds; i++)
    {
        cout << "\nEnter your move (Rock/Paper/Scissors): ";
        cin >> playerMove;

        int randomIndex = rand() % 3;
        string computerMove = moves[randomIndex];

        string result = playRound(playerMove, computerMove);

        cout << "Round " << i << " | "
             << playerMove << " | "
             << computerMove << " | "
             << result << endl;

        if (result == "Player Wins")
            wins++;
        else if (result == "Computer Wins")
            losses++;
        else
            draws++;
    }

    double winPercentage = (wins * 100.0) / rounds;

    cout << "\nFinal Summary" << endl;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Draws: " << draws << endl;
    cout << fixed << setprecision(1);
    cout << "Win %: " << winPercentage << "%" << endl;

    return 0;
}