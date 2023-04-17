/*
 * Binary tree definition
 *
 * Colby Waters
 * 4/7/2023
 */
#ifndef BinaryTree_H
#define BinaryTree_H

#include "node.h"

/*
 * BinaryTree class definition
 */
class BinaryTree
{
public:
    // Constructor / Destructor
    BinaryTree();
    ~BinaryTree();

    // Methods for adding, removing, and searching for values
    void add(uint32_t val);
    void remove(uint32_t val);
    bool search(uint32_t val);

    // Method to print entire tree.
    void print();

private:

    // Method to search for a node in the binary search tree
    bool searchNode(Node* node, uint32_t data);

    // FuncMethodtion to print the binary search tree in order
    void printInOrder(Node* node);

    // Method to print the binary search tree in a visual way
    void printTree(Node* node, uint32_t indent);

private:
    Node* root;
};

#endif // BinaryTree_H
