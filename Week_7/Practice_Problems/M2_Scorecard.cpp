#include <iostream>
using namespace std;

class Scorecard {
private:
    bool* results;
    const int totalQuestions;
    int recorded;

public:
    Scorecard(int count)
        : totalQuestions(count), recorded(0) {
        results = new bool[totalQuestions];
    }

    void recordAnswer(bool correct) {
        if (recorded >= totalQuestions) {
            cout << "All questions recorded" << endl;
            return;
        }

        results[recorded] = correct;
        recorded++;
    }

    int getScore() const {
        int score = 0;

        for (int i = 0; i < recorded; i++) {
            if (results[i]) {
                score++;
            }
        }

        return score;
    }

    ~Scorecard() {
        delete[] results;
    }
};

int main() {
    Scorecard sc(4);

    sc.recordAnswer(true);
    sc.recordAnswer(true);
    sc.recordAnswer(false);
    sc.recordAnswer(true);

    cout << "Score: "
         << sc.getScore() << endl;

    return 0;
}