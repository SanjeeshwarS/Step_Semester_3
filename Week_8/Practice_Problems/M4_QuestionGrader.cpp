#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <algorithm>
using namespace std;

class Question {
protected:
    string text;
    string correctAnswer;
    string studentAnswer;
    double points;

public:
    Question(string t, string correct, string student, double pts)
        : text(t), correctAnswer(correct), studentAnswer(student), points(pts) {
    }

    virtual ~Question() {
    }

    virtual string getType() const = 0;
    virtual double score() const = 0;
};

class ExactMatchQuestion : public Question {
public:
    ExactMatchQuestion(string t, string correct, string student, double pts)
        : Question(t, correct, student, pts) {
    }

    double score() const override {
        return studentAnswer == correctAnswer ? points : 0;
    }
};

class McqQuestion : public ExactMatchQuestion {
public:
    McqQuestion(string t, string correct, string student, double pts)
        : ExactMatchQuestion(t, correct, student, pts) {
    }

    string getType() const override {
        return "MCQ";
    }
};

class TrueFalseQuestion : public ExactMatchQuestion {
public:
    TrueFalseQuestion(string t, string correct, string student, double pts)
        : ExactMatchQuestion(t, correct, student, pts) {
    }

    string getType() const override {
        return "TF";
    }
};

class EssayQuestion : public Question {
private:
    static string toLower(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    static string trim(const string& s) {
        size_t start = s.find_first_not_of(' ');
        if (start == string::npos) {
            return "";
        }
        size_t end = s.find_last_not_of(' ');
        return s.substr(start, end - start + 1);
    }

    int keywordsFound() const {
        string answer = toLower(studentAnswer);
        stringstream ss(correctAnswer);
        string keyword;
        int found = 0;

        while (getline(ss, keyword, ',')) {
            keyword = toLower(trim(keyword));

            if (!keyword.empty() && answer.find(keyword) != string::npos) {
                found++;
            }
        }

        return found;
    }

public:
    EssayQuestion(string t, string correct, string student, double pts)
        : Question(t, correct, student, pts) {
    }

    string getType() const override {
        return "ESSAY";
    }

    double score() const override {
        int found = keywordsFound();

        if (found >= 2) {
            return points * 0.75;
        } else if (found == 1) {
            return points * 0.50;
        }
        return 0;
    }
};

int main() {
    using Maker = function<unique_ptr<Question>(string, string, string, double)>;

    map<string, Maker> factory = {
        {"MCQ", [](string t, string c, string s, double p) {
            return unique_ptr<Question>(new McqQuestion(t, c, s, p));
        }},
        {"TF", [](string t, string c, string s, double p) {
            return unique_ptr<Question>(new TrueFalseQuestion(t, c, s, p));
        }},
        {"ESSAY", [](string t, string c, string s, double p) {
            return unique_ptr<Question>(new EssayQuestion(t, c, s, p));
        }}
    };

    int n;
    cin >> n;

    vector<unique_ptr<Question>> questions;

    for (int i = 0; i < n; i++) {
        string type, text, correct, student;
        double points;
        cin >> type >> quoted(text) >> quoted(correct) >> quoted(student) >> points;
        questions.push_back(factory[type](text, correct, student, points));
    }

    double total = 0;
    cout << fixed << setprecision(2);

    for (const auto& q : questions) {
        double score = q->score();
        cout << q->getType() << ": " << score << endl;
        total += score;
    }

    cout << "Total Score: " << total << endl;

    return 0;
}
