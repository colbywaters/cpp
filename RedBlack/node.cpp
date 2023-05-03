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

void Node::setData(uint32_t n)
{
    number = n; 
}

void Node::setLeft(Node* newNode) {
  left = newNode;
}

NodeColor Node::getColor()
{
    return color;
}

void Node::setColor(NodeColor c)
{
    color = c;
}

// Set parent
void Node::setParent(Node* p)
{
    parent = p;
}

// Get parent
Node* Node::getParent()
{
    return parent;
}

void Node::setRight(Node* newNode) {
  right = newNode;
}
