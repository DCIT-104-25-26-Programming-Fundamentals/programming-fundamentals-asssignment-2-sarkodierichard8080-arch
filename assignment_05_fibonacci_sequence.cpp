// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
using namespace std;

/**
 * Prints the first n terms of the Fibonacci sequence, generated with a loop.
 *
 * @param n The number of terms to print.
 */
void printFibonacci(int n) {
    long long a = 0;
    long long b = 1;

    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a;
        if (i < n - 1) {
            cout << " ";
        }
        long long next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

/**
 * Determines whether a given number appears in the Fibonacci sequence.
 * Generates Fibonacci numbers with a loop until reaching or passing the target.
 *
 * @param num The number to check.
 * @return true if num is a Fibonacci number, false otherwise.
 */
bool isFibonacci(long long num) {
    if (num < 0) {
        return false;
    }

    long long a = 0;
    long long b = 1;

    while (a < num) {
        long long next = a + b;
        a = b;
        b = next;
    }

    return a == num;
}

int main() {
    // -------------------------------------------------------------------
    // PART A — Print the First N Terms
    // -------------------------------------------------------------------
    int n;
    cout << "How many terms? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Please enter a positive number of terms." << endl;
    } else {
        printFibonacci(n);
    }

    // -------------------------------------------------------------------
    // PART B — Check if a Number Belongs to the Sequence
    // -------------------------------------------------------------------
    long long numberToCheck;
    cout << "Enter a number to check: ";
    cin >> numberToCheck;

    if (isFibonacci(numberToCheck)) {
        cout << numberToCheck << " is a Fibonacci number." << endl;
    } else {
        cout << numberToCheck << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
