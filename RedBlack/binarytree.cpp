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
void BinaryTree::add(uint32_t val)
{
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

// Method to remove a node from the binary search tree
void BinaryTree::remove(uint32_t val)
{
    // Find the node to be removed
    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr && current->getData() != val) {
        parent = current;
        if (val < current->getData()) {
            current = current->getLeft();
        }
        else {
            current = current->getRight();
        }
    }

    // If the node isn't in the tree, return
    if (current == nullptr) {
        return;
    }

    // 1. If the node has no children, simply delete it
    if (current->getLeft() == nullptr && current->getRight() == nullptr)
    {
        if (current == root) {
            root = nullptr;
        }
        else if (current == parent->getLeft()) {
            parent->setLeft(nullptr);
        }
        else {
            parent->setRight(nullptr);
        }
        delete current;
    }
    // 2. If the node has one child, replace it with that child
    else if (current->getLeft() == nullptr || current->getRight() == nullptr)
    {
        Node* child;
        if (current->getLeft() == nullptr) {
            child = current->getRight();
        }
        else {
            child = current->getLeft();
        }
        if (current == root) {
            root = child;
        }
        else if (current == parent->getLeft()) {
            parent->setLeft(child);
        }
        else {
            parent->setRight(child);
        }
    }

    // 3. If the node has two children, find its in-order successor and replace it with that
    else
    {
        Node* successor = current->getRight();
        while (successor->getLeft() != nullptr) {
            successor = successor->getLeft();
        }
        uint32_t temp = successor->getData();
        remove(temp);
        current->setData(temp);
    }
}

// Public method for searching for a value
bool BinaryTree::search(uint32_t data)
{
  return searchNode(root, data);
}

// Method to search for a node in the binary search tree
bool BinaryTree::searchNode(Node* node, uint32_t data) {
    if (node == NULL) {
        return false;
    }
    else if (node->getData() == data) {
        return true;
    }
    else if (data < node->getData()) {
        return searchNode(node->getLeft(), data);
    }
    else {
        return searchNode(node->getRight(), data);
    }
}

// Method to print the binary search tree in order
void BinaryTree::printInOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->getLeft());
    cout << node->getData() << " ";
    printInOrder(node->getRight());
}

// Public method for printing binary tree.
void BinaryTree::print()
{
    cout << "root is " << root->getData() << endl;
    printTree(root, 4);
}

// Method to print the binary search tree in a visual way
void BinaryTree::printTree(Node* node, uint32_t indent) {
    if (node == NULL) {
        return;
    }
    printTree(node->getRight(), indent + 4);
    for (uint32_t i = 0; i < indent; i++) {
        cout << " ";
    }
    cout << node->getData() << endl;
    printTree(node->getLeft(), indent + 4);
}

