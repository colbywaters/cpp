#include <iostream>
#include <cstring>

#include "node.h"

using namespace std;

Node::Node() {
  nextNode = NULL;
}

Node::Node(char c) {
  data = c;
  nextNode = NULL;
}

Node::~Node() {
  // free next node? Not sure that should be done here.
  delete nextNode;
}

Node* Node::getNext() {
  return nextNode;
}

char Node::getData() {
  return data;
}

void Node::setNext(Node* newNode) {
  nextNode = newNode;
}

