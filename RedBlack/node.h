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
 * Color for node
 */
enum NodeColor
{
    BLACK,
    RED
};

/*
 * Node class definition for characters
 */
class Node
{
public:
    Node();
    Node(uint32_t);
    ~Node();

    // Set children
    void setLeft(Node*);
    void setRight(Node*);

    // Get children
    Node* getLeft();
    Node* getRight();

    // Set parent
    void setParent(Node*);

    // Get parent
    Node* getParent();

    uint32_t getData();
    void setData(uint32_t n);

    NodeColor getColor();
    void setColor(NodeColor c);

private:
    Node* left;
    Node* right;
    Node* parent;
    NodeColor color;
    uint32_t number;
};

#endif // Node_H
