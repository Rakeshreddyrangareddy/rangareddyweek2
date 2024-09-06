#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int row;          // Row index
    int col;          // Column index
    int value;        // Non-zero value
    Node* next;       // Pointer to the next node
};

// Class for Sparse Matrix linked list
class SparseMatrix {
private:
    Node* head;       // Pointer to the head of the linked list

public:
    SparseMatrix() : head(nullptr) {}

    // Function to create and insert a new node in the linked list
    void insert(int row, int col, int value) {
        Node* newNode = new Node();
        newNode->row = row;
        newNode->col = col;
        newNode->value = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display the sparse matrix linked list
    void display() {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << "Row: " << temp->row << " | Column: " << temp->col
                 << " | Value: " << temp->value
                 << " | Next Node Address: " << temp->next << endl;
            temp = temp->next;
        }
    }

    // Manual insertion of matrix elements based on user input
    void inputMatrix() {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int value;
                cout << "Enter value for element at [" << i << "][" << j << "]: ";
                cin >> value;
                if (value != 0) {
                    insert(i, j, value);
                }
            }
        }
    }
};

int main() {
    SparseMatrix matrix;

    cout << "Input sparse matrix values (enter 0 for zero values):" << endl;
    matrix.inputMatrix();

    cout << "\nDisplaying the Linked List representation of the Sparse Matrix:\n";
    matrix.display();

    return 0;
}

