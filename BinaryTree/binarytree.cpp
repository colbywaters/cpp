/*
 * Binary tree implementation
 *
 * Colby Waters
 * 4/7/2023
 */
#include <iostream>
#include <cstring>
#include "binarytree.h"

using namespace std;

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    // Should we delete the tree here?
}

// Method to add a value to the binary search tree
void BinaryTree::addValue(int val) {
    Node* newNode = new Node(val);

    // If the tree is empty, make the new node the root
    if (root == nullptr) {
        root = newNode;
        return;
    }

    // Otherwise, traverse the tree and find the correct position for the new node
    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (val < current->getData()) {
            current = current->getLeft();
        }
        else {
            current = current->getRight();
        }
    }
    if (val < parent->getData()) {
        parent->setLeft(newNode);
    }
    else {
        parent->setRight( newNode );
    }
}

