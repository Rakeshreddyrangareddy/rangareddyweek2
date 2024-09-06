#include <iostream>
#include <vector>
using namespace std;

// Struct to store non-zero elements
struct Element {
    int row;
    int col;
    int value;
};

int main() {
    int rows, cols;

    // Input number of rows and columns
    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    // Vector to store the non-zero elements as tuples
    vector<Element> sparseMatrix;

    // Input the matrix elements
    cout << "Enter the elements of the matrix (row-wise): " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            cout << "Enter the element at row " << i << " and column " << j << ": ";
            cin >> value;
            if (value != 0) {
                // If element is non-zero, store it
                sparseMatrix.push_back({i, j, value});
            }
        }
    }

    // Display the sparse matrix in tuple format
    cout << "\nSparse Matrix Representation (Row, Column, Value):" << endl;
    for (const auto &elem : sparseMatrix) {
        cout << "(" << elem.row << ", " << elem.col << ", " << elem.value << ")" << endl;
    }

    return 0;
}


