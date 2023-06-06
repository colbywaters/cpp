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
    int index = hash(student->id, size);
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

        if (numCollisions >= 3)
        {
            // numCollisions variable only counts what is already in list and not new.
            cout << "We have more than 3 collisions! Need to resize!" << endl;
            resize();
        }
    }
}

/*
 * Delete a student from the hash table
 */
void HashTable::remove(int id) {
    int index = hash(id, size);

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
    // 1. Construct new table that is twice the size as old table.
    int newSize = this->size * 2;
    Node** newTable = new Node*[newSize];
    for (int i = 0; i < newSize; i++) {
        newTable[i] = nullptr;
    }

    ///////////////////////////////////////////
    // rehash existing students into new table

    // 2. Traverse through old table and move all nodes to new hash table.
    for (int i = 0; i < size; i++)
    {
        Node* current = table[i];

        // Traverse list for this hast table entry.
        while (current != nullptr)
        {
            // ----------------------------------------------------
            // Add new node to new hash table.
            Student* pStudent = current->getStudent();

            int index = hash(pStudent->id, newSize);
            Node* pNewNode = new Node(pStudent);

            // If new table entry is empty then just add it.
            if (newTable[index] == nullptr) {
                newTable[index] = pNewNode;
            // Otherwise, add to end of list. Never should have more than 3 collisions.
            } else {
                Node* newcurrent = newTable[index];

                while (newcurrent->getNext() != nullptr) {
                    newcurrent = newcurrent->getNext();
                }
                newcurrent->setNext(pNewNode);
            }

            // ----------------------------------------------------
            current = current->getNext();
        }
    }
    
    // 3. Delete old table
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->getNext();
            delete temp;
        }
    }

    // 4. Update table to new table.
    delete[] table;
    table = newTable;
    int oldSize = size;
    size = newSize;
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