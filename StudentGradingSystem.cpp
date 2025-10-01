#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

// Clamp function to restrict input within range
int clamp(int value, int minVal, int maxVal) {
    return min(max(value, minVal), maxVal);
}

// Input validation function
int getIntInput(string prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            value = clamp(value, minVal, maxVal);
            break;
        } else {
            cout << "❌ Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}

int main() {
    string name, usn;

    cout << "=== 📘 STUDENT GRADING SYSTEM ===\n\n";

    // Student info
    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter USN: ";
    getline(cin, usn);

    // QUIZZES
    int quiz[6];
    cout << "\n📘 Enter Quiz Scores (50 - 100)\n";

    cout << "Prelim Quizzes:\n";
    quiz[0] = getIntInput("  Quiz 1: ", 50, 100);
    quiz[1] = getIntInput("  Quiz 2: ", 50, 100);

    cout << "Midterm Quizzes:\n";
    quiz[2] = getIntInput("  Quiz 3: ", 50, 100);
    quiz[3] = getIntInput("  Quiz 4: ", 50, 100);

    cout << "Finals Quizzes:\n";
    quiz[4] = getIntInput("  Quiz 5: ", 50, 100);
    quiz[5] = getIntInput("  Quiz 6: ", 50, 100);

    // ACTIVITIES
    int activity[3];
    cout << "\n📝 Enter Activity Scores (0 - 100)\n";
    cout << "Prelim Activity:\n";
    activity[0] = getIntInput("  Activity 1: ", 0, 100);

    cout << "Midterm Activity:\n";
    activity[1] = getIntInput("  Activity 2: ", 0, 100);

    cout << "Finals Activity:\n";
    activity[2] = getIntInput("  Activity 3: ", 0, 100);

    // MAJOR EXAMS
    int exam[3];
    cout << "\n📚 Enter Major Exam Scores (0 - 100)\n";
    cout << "Prelim Exam:\n";
    exam[0] = getIntInput("  Exam 1: ", 0, 100);

    cout << "Midterm Exam:\n";
    exam[1] = getIntInput("  Exam 2: ", 0, 100);

    cout << "Finals Exam:\n";
    exam[2] = getIntInput("  Exam 3: ", 0, 100);

    // CALCULATIONS
    double quizTotal = 0, activityTotal = 0, examTotal = 0;
    for (int i = 0; i < 6; i++) quizTotal += quiz[i];
    for (int i = 0; i < 3; i++) activityTotal += activity[i];
    for (int i = 0; i < 3; i++) examTotal += exam[i];

    double quizFinal = quizTotal / 6.0;
    double activityFinal = activityTotal / 3.0;
    double examFinal = examTotal / 3.0;

    double lmsFinal = (quizFinal + examFinal) / 2.0;
    double faceToFaceFinal = (activityFinal + examFinal) / 2.0;
    int finalGrade = round((lmsFinal + faceToFaceFinal) / 2.0);

    // OUTPUT
    cout << "\n=== 📊 FINAL RESULTS ===\n";
    cout << "👤 Student: " << name << "\n";
    cout << "🆔 USN: " << usn << "\n\n";

    cout << fixed << setprecision(2);
    cout << "📘 Quiz Final: " << quizFinal << "%\n";
    cout << "📝 Activity Final: " << activityFinal << "%\n";
    cout << "📚 Major Exam Final: " << examFinal << "%\n";
    cout << "💻 LMS Final: " << lmsFinal << "%\n";
    cout << "🏫 Face-to-Face Final: " << faceToFaceFinal << "%\n";

    cout << setprecision(0);
    cout << "🎓 Overall Final Grade: " << finalGrade << "%\n";

    if (finalGrade >= 75)
        cout << "✅ Result: PASSED\n";
    else
        cout << "❌ Result: FAILED\n";

    return 0;
}

        cout << "❌ Result: FAILED\n";

    return 0;
}
