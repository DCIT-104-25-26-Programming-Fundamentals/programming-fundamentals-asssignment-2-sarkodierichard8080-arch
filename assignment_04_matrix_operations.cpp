// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================





#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int matrixB1[MAX_SIZE][MAX_SIZE];
    int matrixB2[MAX_SIZE][MAX_SIZE];
    int sumMatrix[MAX_SIZE][MAX_SIZE];
    int matrixC1[MAX_SIZE][MAX_SIZE];
    int matrixC2[MAX_SIZE][MAX_SIZE];
    int productMatrix[MAX_SIZE][MAX_SIZE];

    cout << "=== Part A: Transpose a Matrix ===" << endl;
    int rowsA, colsA;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    readMatrix(matrix, rowsA, colsA);

    cout << endl << "Original Matrix:" << endl;
    printMatrix(matrix, rowsA, colsA);

    transposeMatrix(matrix, transposed, rowsA, colsA);

    cout << endl << "Transposed Matrix:" << endl;
    printMatrix(transposed, colsA, rowsA);

    cout << endl << "=== Part B: Add Two Matrices ===" << endl;
    int addRows, addCols;
    cout << "Enter number of rows for both matrices: ";
    cin >> addRows;
    cout << "Enter number of columns for both matrices: ";
    cin >> addCols;

    cout << "-- Matrix 1 --" << endl;
    readMatrix(matrixB1, addRows, addCols);
    cout << "-- Matrix 2 --" << endl;
    readMatrix(matrixB2, addRows, addCols);

    addMatrices(matrixB1, matrixB2, sumMatrix, addRows, addCols);

    cout << endl << "Sum Matrix:" << endl;
    printMatrix(sumMatrix, addRows, addCols);

    cout << endl << "=== Part C: Multiply Two Matrices ===" << endl;
    int rowsC1, colsC1, colsC2;
    cout << "Enter number of rows for Matrix A: ";
    cin >> rowsC1;
    cout << "Enter number of columns for Matrix A: ";
    cin >> colsC1;

    cout << "-- Matrix A --" << endl;
    readMatrix(matrixC1, rowsC1, colsC1);

    cout << "Matrix B must have " << colsC1 << " rows (to match Matrix A's columns)." << endl;
    cout << "Enter number of columns for Matrix B: ";
    cin >> colsC2;

    cout << "-- Matrix B --" << endl;
    readMatrix(matrixC2, colsC1, colsC2);

    multiplyMatrices(matrixC1, matrixC2, productMatrix, rowsC1, colsC1, colsC2);

    cout << endl << "Product Matrix (A x B):" << endl;
    printMatrix(productMatrix, rowsC1, colsC2);

    return 0;
}