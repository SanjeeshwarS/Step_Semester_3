#include <bits/stdc++.h>
using namespace std;

class Candidate
{
private:
    string name;
    double cgpa;
    int codingScore;

public:
    Candidate(string name, double cgpa, int codingScore)
    {
        this->name = name;
        this->cgpa = cgpa;
        this->codingScore = codingScore;
    }

    static bool isEligible(double cgpa)
    {
        return cgpa >= 7.5;
    }

    static bool isEligible(double cgpa, int codingScore)
    {
        return cgpa >= 6.5 && codingScore >= 60;
    }

    double getCompositeScore() const
    {
        return cgpa * 10 + codingScore * 0.5;
    }

    string getName() const
    {
        return name;
    }

    bool isCandidateEligible() const
    {
        return isEligible(cgpa) ||
               isEligible(cgpa, codingScore);
    }

    bool operator<(const Candidate& other) const
    {
        return getCompositeScore() >
               other.getCompositeScore();
    }

    static string shortlistAndRank(
        vector<Candidate> candidates)
    {
        vector<Candidate> shortlisted;

        for (Candidate& candidate : candidates)
        {
            if (candidate.isCandidateEligible())
                shortlisted.push_back(candidate);
        }

        sort(shortlisted.begin(), shortlisted.end());

        string result;

        for (int i = 0; i < shortlisted.size(); i++)
        {
            stringstream ss;
            ss << fixed << setprecision(1)
               << shortlisted[i].getCompositeScore();

            result += to_string(i + 1) + ". " +
                      shortlisted[i].getName() +
                      " (" + ss.str() + ")";

            if (i != shortlisted.size() - 1)
                result += " | ";
        }

        return result;
    }
};

int main()
{
    vector<Candidate> candidates = {
        Candidate("Aisha", 8.2, 40),
        Candidate("Rohit", 6.8, 65),
        Candidate("Meena", 6.0, 90),
        Candidate("Karan", 7.5, 20)
    };

    cout << Candidate::shortlistAndRank(candidates)
         << endl;

    return 0;
}