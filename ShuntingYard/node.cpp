#include <iostream>
#include <cstring>

#include "node.h"

using namespace std;

Node::Node() {
  cout << "a blank node was created" << endl;
  nextNode = NULL;
}


Node::Node(Student* newStudent) {
  //cout << "hello world" << endl;
  myStudent = newStudent;
  nextNode = NULL;
  
}


Node::~Node() {
  //free both node and student
  //student needsto be deleted
  //in a way that calls its own deconstructor
  delete nextNode;
  delete myStudent;
}

Node* Node::getNext() {
  return nextNode;
}

Student* Node::getStudent() {
  return myStudent;
}

void Node::setNext(Node* newNode) {
  nextNode = newNode;
}

