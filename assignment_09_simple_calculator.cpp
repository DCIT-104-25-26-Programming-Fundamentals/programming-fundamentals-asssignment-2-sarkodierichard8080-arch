// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/**
 * Adds two numbers.
 */
double add(double a, double b) {
    return a + b;
}

/**
 * Subtracts b from a.
 */
double subtract(double a, double b) {
    return a - b;
}

/**
 * Multiplies two numbers.
 */
double multiply(double a, double b) {
    return a * b;
}

/**
 * Divides a by b. Sets success to false if b is zero,
 * so the caller can handle the divide-by-zero case without crashing.
 */
double divide(double a, double b, bool& success) {
    if (b == 0) {
        success = false;
        return 0;
    }
    success = true;
    return a / b;
}

/**
 * Computes a modulo b (the remainder of a / b), using integer arithmetic.
 * Sets success to false if b is zero.
 */
 double computeModulus(double a, double b, bool& success) {
    if (b == 0) {
        success = false;
        return 0;
    }
    success = true;
    return static_cast<int>(a) % static_cast<int>(b);
}

/**
 * Raises a to the power of b using the pow() function from <cmath>.
 */
double exponentiate(double a, double b) {
    return pow(a, b);
}

/**
 * Prints the main calculator menu options to the console.
 */
void printMenu() {
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}

int main() {
    bool running = true;

    while (running) {
        printMenu();
        int choice;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            running = false;
            continue;
        }

        if (choice < 1 || choice > 6) {
            cout << "Error: Please enter a number between 1 and 7." << endl << endl;
            continue;
        }

        double a, b;
        cout << "Enter first number : ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        double result;
        bool success = true;
        string symbol;

        switch (choice) {
            case 1:
                result = add(a, b);
                symbol = "+";
                break;
            case 2:
                result = subtract(a, b);
                symbol = "-";
                break;
            case 3:
                result = multiply(a, b);
                symbol = "*";
                break;
            case 4:
                result = divide(a, b, success);
                symbol = "/";
                break;
            case 5:
                 result = computeModulus(a, b, success);
                symbol = "%";
                break;
            case 6:
                result = exponentiate(a, b);
                symbol = "^";
                break;
        }

        if (!success) {
            cout << "Error: Cannot divide by zero." << endl;
        } else {
            cout << "Result: " << a << " " << symbol << " " << b << " = "
                 << fixed << setprecision(2) << result << endl;
        }

        cout << endl;
    }

    return 0;
}