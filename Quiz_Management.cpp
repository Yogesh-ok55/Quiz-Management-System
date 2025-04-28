#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Question {
private:
    string questionText;
    vector<string> options;
    int correctOption; 

public:
    Question() {}

    void inputQuestion() {
        cout << "\nEnter the question: ";
        cin.ignore();
        getline(cin, questionText);

        string option;
        cout << "Enter 4 options:\n";
        for (int i = 0; i < 4; i++) {
            cout << "Option " << i + 1 << ": ";
            getline(cin, option);
            options.push_back(option);
        }

        cout << "Enter the correct option number (1-4): ";
        cin >> correctOption;
    }

    void displayQuestion() {
        cout << questionText << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool checkAnswer(int answer) {
        return answer == correctOption;
    }
};


class Quiz {
private:
    vector<Question> questions;
    int score;

public:
    Quiz() {
        score = 0;
    }

    void addQuestion() {
        Question q;
        q.inputQuestion();
        questions.push_back(q);
    }

    void startQuiz() {
        score = 0;
        int answer;
        cout << "\n--- Starting Quiz ---\n" << endl;
        for (size_t i = 0; i < questions.size(); i++) {
            cout << "Question " << i + 1 << ":\n";
            questions[i].displayQuestion();
            cout << "Enter your answer (1-4): ";
            cin >> answer;
            if (questions[i].checkAnswer(answer)) {
                cout << "Correct!\n" << endl;
                score++;
            } else {
                cout << "Wrong!\n" << endl;
            }
        }
    }

    int getScore() {
        return score;
    }

    int getTotalQuestions() {
        return questions.size();
    }
};


class User {
private:
    string username;
    int userScore;

public:
    User(string name) {
        username = name;
        userScore = 0;
    }

    void takeQuiz(Quiz &quiz) {
        quiz.startQuiz();
        userScore = quiz.getScore();
    }

    void showResult(Quiz &quiz) {
        cout << "\n--- Quiz Completed! ---\n";
        cout << "User: " << username << endl;
        cout << "Score: " << userScore << " out of " << quiz.getTotalQuestions() << endl;
    }
};


int main() {
    Quiz quiz;

    int numQuestions;
    cout << "Enter number of questions you want to add: ";
    cin >> numQuestions;

   
    for (int i = 0; i < numQuestions; i++) {
        cout << "\nAdding Question " << i + 1 << ":" << endl;
        quiz.addQuestion();
    }

    string name;
    cout << "\nEnter your name to start the quiz: ";
    cin.ignore();
    getline(cin, name);
    User user(name);

    user.takeQuiz(quiz);
    user.showResult(quiz);

    return 0;
}
