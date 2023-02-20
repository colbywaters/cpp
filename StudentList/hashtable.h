/*
 * Student Hash table implementation for a tracking student information
 *
 * Colby Waters
 * 2/9/2023
 */

#ifndef Hashtable_H
#define Hashtable_H

/*
 * Hash table class
 */
class HashTable
{
public:
    // Constructor
    HashTable(int size);

    // Destructor
    ~HashTable();

    // Add a new student to the hash table
    void add(Student* student);

    // Delete a student from the hash table
    void remove(int id);

    // Print all students in the hash table
    void print();

private:
    int size;       // Size of the hash table.
    Node** table;   // Pointer to array of pointers to student nodes

    void resize();

    // Hash function
    int hash(int id) {
        return id % size;
    }

    // Helper function to create a new student node
    Student* createStudent(int id,  float gpa, const char* fname, const char* lname);
};

#endif // Hashtable_H