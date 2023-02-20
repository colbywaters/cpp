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
        int numCollisions = 1;        
        Node* current = table[index];
        while (current->getNext() != nullptr) {
            current = current->getNext();
            numCollisions++;
        }
        current->setNext(node);

        if (numCollisions > 3)
        {
            resize();
        }
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
 * Resize - Rehash entire table into a newer larger table.
 */
void HashTable::resize()
{
    int newSize = this->size * 2;
    Node** newTable = new Node*[newSize]();
    int oldSize = size;
    size = newSize;
    
    // rehash existing students into new table
    for (int i = 0; i < oldSize; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            int index = hash(current->getStudent()->id);
            Node* newNode = new Node(current->getStudent());
            newTable[index] = newNode;
            current = current->getNext();
        }
    }
    
    // delete old table
    for (int i = 0; i < oldSize; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->getNext();
            delete temp;
        }
    }
    delete[] table;
    table = newTable;
}

/*
 * Print all students in the hash table
 */
void HashTable::print() {
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": "; // << std::flush;

        Node* current = table[i];
        while (current != nullptr) {
            Student* student = current->getStudent();
            cout << "[" << student->id << ", " << student->gpa << ", " << student->fname << " " << student->lname << "] ";
            current = current->getNext();
        }
        cout << endl;
    }
}