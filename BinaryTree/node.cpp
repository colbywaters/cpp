/*
 * Node implementation for binary tree
 *
 * Colby Waters
 * 4/7/2023
 */
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node() {
  left = nullptr;
  right = nullptr;
}

Node::Node(uint32_t n) {
  number = n;
  left = nullptr;
  right = nullptr;
}

Node::~Node() {
  // free next node? Not sure that should be done here.
  delete left;
  delete right;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}

uint32_t Node::getData() {
  return number;
}

void Node::setLeft(Node* newNode) {
  left = newNode;
}

void Node::setRight(Node* newNode) {
  right = newNode;
}
