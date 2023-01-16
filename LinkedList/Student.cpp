/*
 * LinkedList Assignment
 *
 * File: Student.h
 * Description: Student implementation
 *
 * Colby Waters
 * 1/15/2023
 */
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Student.h"

/*
 * Default constructor for Student
 */
Student::Student()
{ 
   mId = 0;
   strcpy(mName, "");
}

/*
 * Destructor for Student
 */
Student::~Student()
{
   // Nothing to delete for student.
}

/*
 * Method to set student id.
 */
void Student::setId(int id)
{
   mId = id;
}

/*
 * Method to set student name.
 */
void Student::setName(const char* name)
{
   strcpy(mName, name);
}

/*
 * Method to get student name.
 */
const char* Student::getName()
{
   return mName;
}

/*
 * Method to get student id.
 */
int Student::getId()
{
   return mId;
}

