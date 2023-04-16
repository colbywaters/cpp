/*
 * Node definition for binary tree
 *
 * Update: Needed to update Node for binary tree
 *
 * Colby Waters
 * 4/7/2023
 */

using namespace std;

#ifndef Node_H
#define Node_H

/*
 * Node class definition for characters
 */
class Node
{
public:
    Node();
    Node(uint32_t);
    ~Node();

    Node* getLeft();
    Node* getRight();

    uint32_t getData();

    // Set children
    void setLeft(Node*);
    void setRight(Node*);

private:
    Node* left;
    Node* right;
    uint32_t number;
};

#endif // Node_H
