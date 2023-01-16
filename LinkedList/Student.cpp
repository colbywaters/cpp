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

    Student::Student()
    { 
       mId = 0;
       strcpy(mName, "");
    }

    void Student::setId(int id)
    {
       mId = id;
    }

    void Student::setName(const char* name)
    {
       strcpy(mName, name);
    }

    const char* Student::getName()
    {
        return mName;
    }

    int Student::getId()
    {
        return mId;
    }

