/*
 * Student List implementation for a vector of student
 *
 * Colby Waters
 * 11/6/2022
 */

#ifndef Student_H
#define Student_H

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

#endif