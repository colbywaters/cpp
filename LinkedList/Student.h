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

    Student();

    void setName(const char* name);
    void setId(int id);

    const char* getName();
    int getId();

private:
    char mName[255];
    int  mId;
};
