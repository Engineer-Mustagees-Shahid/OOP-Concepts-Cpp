#include <iostream>
using namespace std;

// Task 1: Function to allocate memory for a char matrix
char** AllocateMemory(int& rows, int& cols) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    char** matrix = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new char[cols];
    }
    return matrix;
}

// Task 2: Function to take input for the matrix
void InputMatrix(char** matrix, const int rows, const int cols) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Task 3: Function to display the matrix
void DisplayMatrix(char** matrix, const int& rows, const int& cols) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Task 4: Function to check if all diagonal elements are the same
bool isAllDiagonal(char** matrix, const int& rows, const int& cols) {
    if (rows != cols) {
        cout << "Matrix is not square, cannot check diagonals." << endl;
        return false;
    }

    char diagonalValue = matrix[0][0];
    for (int i = 1; i < rows; ++i) {
        if (matrix[i][i] != diagonalValue) {
            return false;
        }
    }
    return true;
}

// Task 5: Rotate the matrix anti-clockwise if all diagonal elements are the same
void rotateAntiClockWise(char** matrix, const int& rows, const int& cols) {
    if (!isAllDiagonal(matrix, rows, cols)) {
        cout << "Matrix does not have the same diagonal values. Cannot rotate." << endl;
        return;
    }

    cout << "Matrix after Anti-Clockwise Rotation:" << endl;
    for (int i = cols - 1; i >= 0; --i) {
        for (int j = 0; j < rows; ++j) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    int rows, cols;
    char** matrix = AllocateMemory(rows, cols);

    InputMatrix(matrix, rows, cols);
    DisplayMatrix(matrix, rows, cols);

    if (isAllDiagonal(matrix, rows, cols)) {
        cout << "All diagonal elements are the same." << endl;
    } else {
        cout << "Diagonal elements are not the same." << endl;
    }

    rotateAntiClockWise(matrix, rows, cols);

    // Free allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

