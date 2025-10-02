#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

// Clamp helper
int clamp(int value, int minVal, int maxVal) {
    return min(max(value, minVal), maxVal);
}

// Input validation helper
int getIntInput(string prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value < minVal) {
                cout << " Score cannot be below " << minVal << ". Please re-enter.\n";
                continue;
            }
            if (value > maxVal) {
                cout << " Score cannot exceed " << maxVal << ". Please re-enter.\n";
                continue;
            }
            break; //  only breaks if within range
        } else {
            cout << " Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}

int main() {
    cout << "===  STUDENT GRADING SYSTEM ===\n\n";

    string usn, fullname;
    cout << "Enter Student USN: ";
    cin >> usn;
    cin.ignore();
    cout << "Enter Full Name: ";
    getline(cin, fullname);

    int quiz[6], activity[3], exam[3];

    //  Get Quiz Scores
    cout << "\nEnter 6 Quiz Scores (50 - 100):\n";
    quiz[0] = getIntInput("Prelim Quiz 1: ", 50, 100);
    quiz[1] = getIntInput("Prelim Quiz 2: ", 50, 100);
    quiz[2] = getIntInput("Midterm Quiz 1: ", 50, 100);
    quiz[3] = getIntInput("Midterm Quiz 2: ", 50, 100);
    quiz[4] = getIntInput("Final Quiz 1: ", 50, 100);
    quiz[5] = getIntInput("Final Quiz 2: ", 50, 100);

    //  Get Activity Scores
    cout << "\nEnter 3 Activity Scores (0 - 100):\n";
    activity[0] = getIntInput("Prelim Activity: ", 0, 100);
    activity[1] = getIntInput("Midterm Activity: ", 0, 100);
    activity[2] = getIntInput("Final Activity: ", 0, 100);

    //  Get Major Exam Scores
    cout << "\nEnter 3 Major Exam Scores (0 - 100):\n";
    exam[0] = getIntInput("Prelim Major Exam: ", 0, 100);
    exam[1] = getIntInput("Midterm Major Exam: ", 0, 100);
    exam[2] = getIntInput("Final Major Exam: ", 0, 100);

    //  Calculations
    double quizTotal = 0, activityTotal = 0, examTotal = 0;
    for (int i = 0; i < 6; i++) quizTotal += quiz[i];
    for (int i = 0; i < 3; i++) activityTotal += activity[i];
    for (int i = 0; i < 3; i++) examTotal += exam[i];

    double quizFinal = quizTotal / 6.0;
    double activityFinal = activityTotal / 3.0;
    double examFinal = examTotal / 3.0;

    double lmsFinal = (quizFinal + examFinal) / 2.0;
    double faceToFaceFinal = (activityFinal + examFinal) / 2.0;
    double finalGrade = (lmsFinal + faceToFaceFinal) / 2.0;
    int roundedFinal = round(finalGrade);

    //  Output
    cout << "\n===  FINAL RESULTS ===\n";
    cout << " Student: " << fullname << "\n";
    cout << " USN: " << usn << "\n\n";

    cout << fixed << setprecision(2);
    cout << " Quiz Final: " << quizFinal << "%\n";
    cout << " Activity Final: " << activityFinal << "%\n";
    cout << " Major Exam Final: " << examFinal << "%\n";
    cout << " LMS Final: " << lmsFinal << "%\n";
    cout << " Face-to-Face Final: " << faceToFaceFinal << "%\n";

    cout << setprecision(0);
    cout << " Overall Final Grade: " << roundedFinal << "%\n";

    if (roundedFinal >= 75)
        cout << " Result: PASSED\n";
    else
        cout << " Result: FAILED\n";

    return 0;
}
