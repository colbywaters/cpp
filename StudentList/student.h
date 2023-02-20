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
     /*
      * Default constructor
      */
     Student()
     {
          strcpy(this->fname, "");
          strcpy(this->lname, "");
          id = 0;
          gpa = 0.0f;
     }

     /*
      * Constructor that takes student information.
      */
     Student(int id, float gpa, const char* fname, const char* lname)
     {
          this->id = id;
          this->gpa = gpa;
          strcpy(this->fname, fname);
          strcpy(this->lname, lname);
     }

     int   id;          // id
     float gpa;         // gpa
     char  fname[256];  // first name
     char  lname[256];  // last name
};

#endif