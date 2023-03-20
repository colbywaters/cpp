#ifndef Node_H
#define Node_H

#include <iostream>
#include <cstring>
#include "student.h"

class Node {
 public:
  Node();
  Node(Student*);
  ~Node();
  //returns next node
  Node* getNext();
  //returns myStudent
  Student* getStudent();
  //sets nextNode to the Node*
  void setNext(Node*);
  
 private:
  Node* nextNode;
  Student* myStudent; // = new Student();
};

#endif
