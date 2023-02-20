/*
 * Student List implementation for a vector of student
 *
 * Colby Waters
 * 11/6/2022
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>

#include "node.h"
#include "student.h"
#include "hashtable.h"

using namespace std;

/*
 * Add Student - add student to student list
 */
Student* addStudent()
{
    int id = 0;
    float gpa = 0.0f;
    char fname[256];
    char lname[256];

    cout << "-------------------------------" << endl;
    cout << "Enter Student Information" << endl;
    cout << "-------------------------------" << endl;
    cout << "First Name: ";
    cin >> fname;
    cout << "Last Name: ";
    cin >> lname;
    cout << "Id: ";
    cin >> id;
    cout << "GPA: ";
    cin >> gpa;

    // @todo We can do error checking here and only create
    //       a student if id and gpa are legit.
    Student* s = new Student(id, gpa, fname, lname);

    return s;
}

/*
 * Student - print information for each student
 */
void printStudent(Student* s)
{
    cout << "First Name: " << s->fname << endl;
    cout << "Last Name: " << s->lname << endl;
    cout << "Id: " << s->id << endl;
    cout << "GPA: " << s->gpa << endl;
}

/*
 * Print Students - print students in student list
 */
void printStudents(Node* students)
{
    if (students != nullptr)
    {
        printStudent(students->getStudent());
        cout << endl;
        printStudents(students->getNext());
    }
}

/*
 * Print Students - print students in student list
 */
float average(Node* students, float gpaAverage)
{
    if (students != nullptr)
    {
        gpaAverage += students->getStudent()->gpa;
        return average(students->getNext(), gpaAverage); 
    }
    return gpaAverage;
}

uint32_t count(Node* students, uint32_t c)
{
    if (students != nullptr)
    {
        c++;
        return count(students->getNext(), c);
    }
    return c; 
}

/*
 * Get Student Id
 */
uint32_t getStudentId()
{     
    uint32_t id = 0;

    cout << "-------------------------------" << endl;
    cout << "Enter Id for student to delete." << endl;
    cout << "-------------------------------" << endl;
    cout << "Id: ";
    cin >> id;

    return id;
}

/*
 * Create a random student with a first name, last name, ID, and GPA
 */
Student* createRandomStudent(int id) {

    float gpa = ((float)rand()/(float)(RAND_MAX)) * 4.0f;

    // @note Complete pain to use cstring and array for this!
    //       Let's use C++ instead of C?
    std::ifstream firstNamesFile("first_names.txt");
    std::vector<std::string> firstNames;
    std::string fName;
    while (std::getline(firstNamesFile, fName)) {
        firstNames.push_back(fName.substr(0, fName.size() - 1));
    }
    firstNamesFile.close();

    // read in last names from file
    std::ifstream lastNamesFile("last_names.txt");
    std::vector<std::string> lastNames;
    std::string lName;
    while (std::getline(lastNamesFile, lName)) {
        lastNames.push_back(lName.substr(0, lName.size() - 1));
    }
    lastNamesFile.close();

    // generate a random first and last name
    int numFirstNames = firstNames.size();
    int numLastNames = lastNames.size();

    std::string firstName = firstNames[rand() % (numFirstNames - 1)];
    std::string lastName = lastNames[rand() % (numLastNames - 1)];

    // create the student with the generated information
    Student* s = new Student(id, gpa, firstName.c_str(), lastName.c_str());

    return s;
}

/*
 * main - This is main function for student list!
 */
int main()
{
    // Set precion for cout to 2 decimal places
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

   time_t t;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));

    int initialSize = 100;
    HashTable hashTable(initialSize);

    // Parser for commands
    //   ADD -    Creates a new entry for a student.  After you type in add, the program
    //            should prompt for first name, last name, student id, and GPA.  That student
    //            should then be added to the list of students (well, student pointers!).
    //   PRINT -  Your program should print out all the students currently stored.
    //            Example: John Doe, 101500, 3.70
    //   AVERAGE - Averages GPA for all students.
    //   DELETE - Prompt the user for the student id number to delete, and remove that struct
    //            from the list. Be sure to delete the data.

    bool hasQuit = false;

    cout << "------------------------------------------------" << endl;
    cout << " Student List - Colby Waters" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter commands to manage student list." << endl;
    cout << "   ADD - Creates new entry for a student." << endl;
    cout << "   PRINT - Prints out all students in list." << endl;
    cout << "   DELETE - Deletes student with ID from list." << endl;
    cout << "   GENERATE - Generate random students." << endl;
    cout << "   AVERAGE - Averages students GPA from list." << endl;
    cout << "   QUIT - Exits Student List program." << endl;
    cout << "------------------------------------------------" << endl;
    
    while(hasQuit == false)
    {
        char command[255];
        cout << ">: ";
        cin >> command;

        if (strcmp(command, "ADD") == 0)
        {
            // Add student.
            Student* s = addStudent();
            hashTable.add(s);
        }
        else if (strcmp(command, "PRINT") == 0)
        {
            cout << "-------------------------------" << endl;
            cout << "Student List" << endl;
            cout << "-------------------------------" << endl;

            // Print student
            hashTable.print();
        }
        else if (strcmp(command, "GENERATE") == 0)
        {
            int numStudents;
            cout << "Enter number of students to generate: ";
            cin >> numStudents;
            for (int i = 0; i < numStudents; i++) {
                Student* s = createRandomStudent(i);
                hashTable.add(s);
            }
            cout << "Generated " << numStudents << " students." << endl;
        }
        else if (strcmp(command, "AVERAGE") == 0)
        {
            /*
            uint32_t c = 0;
            float a = 0.0f;

            a = average(students, a);
            c = count(students, c);

            // Print out debug information for average.
            //cout << "Sum is " << a << endl;
            //cout << "Count is " << c << endl;

            a = a / (float)c;

            cout << "-------------------------------" << endl;
            cout << "Average is " << a << endl;
            cout << "-------------------------------" << endl;
            */
        }
        else if (strcmp(command, "DELETE") == 0)
        {
            // Delete student
            uint32_t id = getStudentId();
            hashTable.remove(id);
        }
        else if (strcmp(command, "QUIT") == 0)
        {
          cout << "QUIT command received" << endl;
          hasQuit = true;
          cout << "Thank you! Exiting Student List." << endl;
        }
        else
        {
            cout << "Unknown command received." << endl;

            cout << "Enter commands to manage student list." << endl;
            cout << "   ADD - Creates new entry for a student." << endl;
            cout << "   PRINT - Prints out all students in list." << endl;
            cout << "   DELETE - Deletes student with ID from list." << endl;
            cout << "   QUIT - Exits Student List program." << endl;
            cout << "------------------------------------------------" << endl;
        }
    }
}

