/*
 * Student Hash table implementation for a tracking student information
 *
 * Colby Waters
 * 2/9/2023
 */
#include <iostream>
#include <iomanip>
#include <cstring>

#include "node.h"
#include "student.h"
#include "hashtable.h"

using namespace std;

/*
 * Constructor that takes a size
 */
HashTable::HashTable(int size) {
    this->size = size;
    table = new Node*[size];
    for (int i = 0; i < size; i++) {
        table[i] = nullptr;
    }
}

/*
 * Destructor
 */
HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->getNext();
            delete temp;
        }
    }
    delete[] table;
}

/*
 * Add a new student to the hash table
 */
void HashTable::add(Student* student) {
    int index = hash(student->id);
    Node* node = new Node(student);
    if (table[index] == nullptr) {
        table[index] = node;
    } else {
        Node* current = table[index];
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(node);
    }
}

/*
 * Delete a student from the hash table
 */
void HashTable::remove(int id) {
    int index = hash(id);

    Node* current = table[index];
    Node* prev = nullptr;

    while (current != nullptr && current->getStudent()->id != id) {
        prev = current;
        current = current->getNext();
    }
    if (current == nullptr) {
        cout << "Student with ID " << id << " not found." << endl;
        return;
    }
    if (prev == nullptr) {
        table[index] = current->getNext();
    } else {
        prev->setNext(current->getNext());
    }
    delete current;
    cout << "Student with ID " << id << " removed." << endl;
}

/*
 * Print all students in the hash table
 */
void HashTable::print() {
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": ";
        Node* current = table[i];
        while (current != nullptr) {
            Student* student = current->getStudent();
            cout << "[" << student->id << ", " << student->fname << " " << student->lname << ", " << student->gpa << "] ";
            current = current->getNext();
        }
        cout << endl;
    }
}