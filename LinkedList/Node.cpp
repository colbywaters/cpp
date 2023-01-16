/*
 * LinkedList Assignment
 *
 * File: Node.cpp
 * Description: Node implementation
 *
 * Colby Waters
 * 1/15/2023
 */
#include "Student.h"
#include "Node.h"

/*
 * Default constructor for Node
 */
Node::Node()
{
    mpStudent = nullptr;
    mpNext = nullptr;
}

/*
 * Constructor that takes student
 */
Node::Node(Student* pStudent)
{
    mpStudent = pStudent;  
    mpNext = nullptr;
}

/*
 * Destructor
 */
Node::~Node()
{
    delete mpStudent;
}

/*
 * Set next node pointer. This will be pointer to next element in linked list.
 */
void Node::setNext(Node* pNode)
{
    mpNext = pNode;
}

/*
 * Get next node pointer. This is useful for traversing linked lists.
 */
Node* Node::getNext()
{
    return mpNext;
}

/*
 * Get student information for this node.
 */
Student* Node::getStudent()
{
    return mpStudent;
}