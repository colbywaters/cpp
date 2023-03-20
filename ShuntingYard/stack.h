/*
 * Stack definition
 *
 * Colby Waters
 * 3/19/2023
 */
#ifndef Stack_H
#define Stack_H

#include "node.h"

/*
 * Stack class that implements push(), pop(), peek() and empty().
 */
class Stack {
private:
    Node* topNode;

public:
    Stack();

    void push(char c);

    void pop();

    char peek();

    bool empty();
};

#endif
