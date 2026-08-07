// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

/**
 * Represents a single student record.
 */
struct Student {
    string name;
    int id;
    vector<double> scores;
};

/**
 * Calculates the average of a student's scores.
 *
 * @param scores The list of scores.
 * @return The average score.
 */
double calculateAverage(const vector<double>& scores) {
    double sum = 0;
    for (size_t i = 0; i < scores.size(); i++) {
        sum += scores[i];
    }
    return sum / scores.size();
}

/**
 * Prompts the user for a student's name, ID, and scores,
 * then adds the new student record to the list.
 *
 * @param students The list of students to add to.
 */
void addStudent(vector<Student>& students) {
    Student s;

    cin.ignore(); // Clear leftover newline from previous numeric input.
    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

/**
 * Displays a formatted table of every student's name, ID, scores,
 * and average score. Prints a message if there are no students yet.
 *
 * @param students The list of students to display.
 */
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << left << setw(20) << "Name" << setw(12) << "ID"
         << setw(20) << "Scores" << "Average" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (size_t i = 0; i < students.size(); i++) {
        const Student& s = students[i];
        double average = calculateAverage(s.scores);

        string scoresText;
        for (size_t j = 0; j < s.scores.size(); j++) {
            scoresText += to_string(static_cast<int>(s.scores[j]));
            if (j < s.scores.size() - 1) {
                scoresText += ", ";
            }
        }

        cout << left << setw(20) << s.name << setw(12) << s.id
             << setw(20) << scoresText
             << fixed << setprecision(2) << average << endl;
    }
}

/**
 * Prompts for a student ID, finds the matching student, and prints
 * their average score. Prints an error if the ID is not found.
 *
 * @param students The list of students to search.
 */
void calculateAverageForStudent(const vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            double average = calculateAverage(students[i].scores);
            cout << students[i].name << "'s average score: "
                 << fixed << setprecision(2) << average << endl;
            return;
        }
    }

    cout << "Error: No student found with that ID." << endl;
}

/**
 * Prints the main menu options to the console.
 */
void printMenu() {
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<Student> students;
    bool running = true;

    while (running) {
        printMenu();
        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageForStudent(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Error: Please enter a number between 1 and 4." << endl;
        }

        cout << endl;
    }

    return 0;
}