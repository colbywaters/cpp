#include <iostream>

#include "MaxHeap.h"

using namespace std;

/*
 * Main implementation for using Max Heap data structure.
 */
int main() {
    MaxHeap heap;

    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1. Enter a series of numbers." << endl;
    cout << "2. Enter filename containing series of numbers." << endl;
    cout << "--------------------------------------------------" << endl;

    cout << "Make your choice (1 or 2): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter up to 100 integers (separated by spaces). Enter -1 to stop: ";
        int value;
        while (cin >> value && value != -1)
            heap.insert(value);
    } else if (choice == 2) {
        /* Todo! */
    } else {
        cout << "Invalid choice! It needs to be either 1 or 2." << endl;
        return 0;
    }

    cout << endl << "Heap tree: " << endl;
    heap.display(0);

    cout << endl << "Max heap numbers: ";
    heap.removeAll();

    return 0;
}