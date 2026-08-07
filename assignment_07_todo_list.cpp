// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Prompts the user for a task description and adds it to the tasks list.
 *
 * @param tasks The list of tasks to add to.
 */
void addTask(vector<string>& tasks) {
    cin.ignore(); // Clear leftover newline from previous numeric input.
    string description;
    cout << "Enter task: ";
    getline(cin, description);

    tasks.push_back(description);
    cout << "Task added: \"" << description << "\"" << endl;
}

/**
 * Displays all current tasks, numbered from 1.
 * Prints a friendly message if there are no tasks yet.
 *
 * @param tasks The list of tasks to display.
 */
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "You have no tasks yet. Add one from the menu!" << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

/**
 * Shows the current tasks, asks the user which one to delete,
 * and removes it from the list if the number is valid.
 *
 * @param tasks The list of tasks to delete from.
 */
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "There are no tasks to delete." << endl;
        return;
    }

    viewTasks(tasks);
    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    int index = taskNumber - 1;

    if (index < 0 || index >= static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string removedTask = tasks[index];
    tasks.erase(tasks.begin() + index);
    cout << "Task \"" << removedTask << "\" has been removed." << endl;
}

/**
 * Prints the main menu options to the console.
 */
void printMenu() {
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<string> tasks;
    bool running = true;

    while (running) {
        printMenu();
        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
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