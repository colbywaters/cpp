/*
 * Queue definition
 *
 * Colby Waters
 * 3/19/2023
 */
#ifndef Queue_H
#define Queue_H

#include "node.h"

/*
 * Queue class that uses linked list. Implements the enqueue() and dequeue().
 */
class Queue
{
private:
    Node* frontNode;
    Node* rearNode;

public:
    Queue();

    void enqueue(char c);

    void dequeue();

    char front();

    bool empty();
};

#endif
