/*
 * Node definition
 *
 * Update: Needed to update Node to use character!
 *
 * Colby Waters
 * 3/19/2023
 */
#ifndef Node_H
#define Node_H

/*
 * Node class definition for characters
 */
class Node
{
public:
    Node();
    Node(char);
    ~Node();
    //returns next node
    Node* getNext();
    //returns character
    char getData();

    //sets nextNode to the Node*
    void setNext(Node*);

private:
    Node* nextNode;
    char data;   // The data is a character in this case!
};

#endif
