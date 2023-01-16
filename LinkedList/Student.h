/*
 * LinkedList Assignment
 *
 * File: Student.h
 * Description: Student definition
 *
 * Colby Waters
 * 1/15/2023
 */

/*
 * Student class that stores name and id.
 */
class Student
{
public:

    // Default constructor for Student    
    Student();

    // Destructor for Student
   ~Student();

    // Set name for student
    void setName(const char* name);

    // Set id for student
    void setId(int id);

    // Get name for student
    const char* getName();

    // Get id for student
    int getId();

private:
    // Student private data: name, id
    char mName[255];
    int  mId;
};
