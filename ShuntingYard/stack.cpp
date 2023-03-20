/*
 * Stack implementation that implements push(), pop(), peek() and empty().
 *
 * Colby Waters
 * 3/19/2023
 */
#include "stack.h"


Stack::Stack()
{
    topNode = nullptr;
}

void Stack::push(char c)
{
    Node* newNode = new Node(c);
    newNode->setNext(topNode);
    topNode = newNode;
}

void Stack::pop() {
    if (topNode == nullptr) {
        return;
    }
    Node* temp = topNode;
    topNode = topNode->getNext();
}

char Stack::peek()
{
    if (topNode == nullptr) {
        return '\0';
    }
    return topNode->getData();
}

bool Stack::empty()
{
    return topNode == nullptr;
}
