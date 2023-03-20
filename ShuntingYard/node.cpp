/*
 * Node implementation
 *
 * Colby Waters
 * 3/19/2023
 */
#include "node.h"

using namespace std;

Node::Node() {
  nextNode = nullptr;
}

Node::Node(char c) {
  data = c;
  nextNode = nullptr;
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
