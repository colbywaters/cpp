/*
 * LinkedList Assignment
 *
 * File: Main.cpp
 * Description: Main implementation
 *
 * Colby Waters
 * 1/15/2023
 */

#include <iostream>

#include "Student.h"
#include "Node.h"

using namespace std;

/*
 * Main entry point into program for testing Node and Student class implementation.
 */
int main()
{
    // Create 5 nodes with each containing a separate student.

    ///////////////////////////////////////////////////////////////////
    // 1. Create the student objects and fill out information for each.
    Student* s1 = new Student();
    Student* s2 = new Student();
    Student* s3 = new Student();
    Student* s4 = new Student();
    Student* s5 = new Student();

    s1->setName("Colby Waters");
    s1->setId(376747);

    s2->setName("Billy Mayer");
    s2->setId(123457);

    s3->setName("Ted Nugget");
    s3->setId(666666);

    s4->setName("Hugh Janus");
    s4->setId(000000);

    s5->setName("Theodore K");
    s5->setId(565656);

    ///////////////////////////////////////////////////////////////////
    // 2. Create the node objects, assign a student to each, and link
    //    them together in a list.
    Node* node1 = new Node(s1);
    Node* node2 = new Node(s2);
    Node* node3 = new Node(s3);
    Node* node4 = new Node(s4);
    Node* node5 = new Node(s5);

    node1->setNext(node2);
    node2->setNext(node3);
    node3->setNext(node4);
    node4->setNext(node5);

    ///////////////////////////////////////////////////////////////////
    // 3. Iterate over list and print out each student from each node
    //    in list.
    Node* curNode = node1;

    while(curNode != nullptr)
    {
        // Print out student information from curNode
        Student* pStudent = curNode->getStudent();

        cout << "------------------" << endl;
        cout << "Name: " << pStudent->getName() << endl;
        cout << "Id: " << pStudent->getId() << endl;

        // Move to next node
        curNode = curNode->getNext();
    }

    ///////////////////////////////////////////////////////////////////
    // 4. Delete all of the student and node objects that were
    //   dynamically created.
   delete s1;
   delete s2;
   delete s3;
   delete s4;
   delete s5;

   delete node1;
   delete node2;
   delete node3;
   delete node4;
   delete node5;

   return 0;
}