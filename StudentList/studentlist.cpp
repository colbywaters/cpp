/*
 * Student List implementation for a vector of student
 *
 * Colby Waters
 * 11/6/2022
 */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*
 * Student - information for each student
 */
struct Student
{
     char  fname[255];  // first name
     char  lname[255];  // last name
     int   id;          // id
     float gpa;         // gpa
};

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
 * Add Student - add student to student list
 */
void addStudent(vector<Student*>& students)
{
    Student* s = new Student();
    cout << "-------------------------------" << endl;
    cout << "Enter Student Information" << endl;
    cout << "-------------------------------" << endl;
    cout << "First Name: ";
    cin >> s->fname;
    cout << "Last Name: ";
    cin >> s->lname;
    cout << "Id: ";
    cin >> s->id;
    cout << "GPA: ";
    cin >> s->gpa;

    students.push_back(s);
}

/*
 * Print Students - print students in student list
 */
void printStudents(vector<Student*>& students)
{
    cout << "-------------------------------" << endl;
    cout << "Student List" << endl;
    cout << "-------------------------------" << endl;

    if (students.size() > 0)
    {
        for(int i = 0; i < students.size(); i++)
        {
            printStudent(students[i]);
            cout << endl;
        }
    }
    else
    {
        cout << "No students!" << endl;
    }
}

/*
 * Delete Student - delete student in student list
 */
void deleteStudent(vector<Student*>& students)
{     
    uint32_t id = 0;

    cout << "-------------------------------" << endl;
    cout << "Enter Id for student to delete." << endl;
    cout << "-------------------------------" << endl;
    cout << "Id: ";
    cin >> id;

    vector<Student*>::iterator i;

    for(i = students.begin(); i != students.end(); ++i)
    {
        Student* s = *i;

        if (s->id == id)
        {
            break; // break out of loop so the iterator points to entry we found.
        }
    }

    if (i != students.end())
    {
        Student* s = *i;
        cout << "Found student ... removing." << endl;
        cout << "   " << s->fname << " " << s->lname << endl;
        students.erase(i);  // Remove student from list!
        delete s;           // Free the actual memory for student!
    }
    else
    {
        cout << "Could not find student with id: " << id << endl;
    }
}

/*
 * main - This is main function for student list!
 */
int main()
{
    // Parser for commands
    //   ADD -    Creates a new entry for a student.  After you type in add, the program
    //            should prompt for first name, last name, student id, and GPA.  That student
    //            should then be added to the vector of students (well, student pointers!).
    //   PRINT -  Your program should print out all the students currently stored.
    //            Example: John Doe, 101500, 3.70
    //   DELETE - Prompt the user for the student id number to delete, and remove that struct
    //            from the vector. Be sure to delete the data.

    bool hasQuit = false;

    cout << "------------------------------------------------" << endl;
    cout << " Student List - Colby Waters" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter commands to manage student list." << endl;
    cout << "   ADD - Creates new entry for a student." << endl;
    cout << "   PRINT - Prints out all students in list." << endl;
    cout << "   DELETE - Deletes student with ID from list." << endl;
    cout << "   QUIT - Exits Student List program." << endl;
    cout << "------------------------------------------------" << endl;
    
    vector<Student*> students;

    while(hasQuit == false)
    {
        char command[255];
        cout << ">: ";
        cin >> command;

        if (strcmp(command, "ADD") == 0)
        {
            // Add student
            addStudent(students);
        }
        else if (strcmp(command, "PRINT") == 0)
        {
            // Print student
            printStudents(students);
        }
        else if (strcmp(command, "DELETE") == 0)
        {
            // Delete student
            deleteStudent(students);
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

