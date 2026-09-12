#include <bits/stdc++.h>
using namespace std;

class Player
{
private:
    string name;
    int matchesPlayed;
    double battingAverage;
    bool injured;

public:
    Player(string name, int matchesPlayed,
           double battingAverage, bool injured)
    {
        this->name = name;
        this->matchesPlayed = matchesPlayed;
        this->battingAverage = battingAverage;
        this->injured = injured;
    }

    static bool isDraftable(int matchesPlayed)
    {
        return matchesPlayed >= 10;
    }

    static bool isDraftable(int matchesPlayed, bool injured)
    {
        return matchesPlayed >= 5 && !injured;
    }

    bool draftable()
    {
        return isDraftable(matchesPlayed) ||
               isDraftable(matchesPlayed, injured);
    }

    bool operator<(const Player& other) const
    {
        return battingAverage > other.battingAverage;
    }

    string getName() const
    {
        return name;
    }

    static string draftAndRank(vector<Player> players)
    {
        vector<Player> draftablePlayers;

        for (Player& player : players)
        {
            if (player.draftable())
                draftablePlayers.push_back(player);
        }

        sort(draftablePlayers.begin(),
             draftablePlayers.end());

        string result;

        for (int i = 0; i < draftablePlayers.size(); i++)
        {
            result += to_string(i + 1) + ". " +
                      draftablePlayers[i].getName();

            if (i != draftablePlayers.size() - 1)
                result += " | ";
        }

        return result;
    }
};

int main()
{
    vector<Player> players = {
        Player("Virat", 15, 48.0, false),
        Player("Rahul", 7, 55.0, false),
        Player("Sameer", 3, 60.0, false),
        Player("Dev", 12, 20.0, true)
    };

    cout << Player::draftAndRank(players) << endl;

    return 0;
}