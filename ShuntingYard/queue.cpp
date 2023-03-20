/*
 * Queue implementation that implements enqueue() and dequeue().
 *
 * Colby Waters
 * 3/19/2023
 */
#include "node.h"
#include "queue.h"

Queue::Queue()
{
    frontNode = nullptr;
    rearNode = nullptr;
}

void Queue::enqueue(char c)
{
    Node* newNode = new Node(c);
    newNode->setNext( nullptr );
    if (rearNode == nullptr) {
        frontNode = newNode;
        rearNode = newNode;
    }
    else {
        rearNode->setNext(newNode);
        rearNode = newNode;
    }
}

void Queue::dequeue()
{
    if (frontNode == nullptr) {
        return;
    }
    Node* temp = frontNode;
    frontNode = frontNode->getNext();
    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
    //delete temp;
}

char Queue::front()
{
    if (frontNode == nullptr) {
        return '\0';
    }
    return frontNode->getData();
}

bool Queue::empty()
{
    return frontNode == nullptr;
}