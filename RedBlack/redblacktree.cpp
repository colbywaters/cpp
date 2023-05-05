/*
 * RedBlack tree implementation
 *
 * Colby Waters
 * 4/7/2023
 */
#include <iostream>
#include <cstring>
#include "redblacktree.h"

using namespace std;

RedBlackTree::RedBlackTree()
{
    root = nullptr;
}

RedBlackTree::~RedBlackTree()
{
    // Should we delete the tree here?
}

void RedBlackTree::rotateLeft(Node* node)
{
    Node* right = node->getRight();
    node->setRight(right->getLeft());

    if (right->getLeft() == nullptr)
    {
        right->getLeft()->setParent(node);
    }

    right->setParent(node->getParent());

    if(node->getParent() == nullptr)
    {
        root = right;
    }
    else if (node == node->getParent()->getLeft())
    {
        node->getParent()->setLeft(right);        
    }
    else
    {
        node->getParent()->setRight(right);
    }

    right->setLeft(node);
    node->setParent(right);
}

void RedBlackTree::rotateRight(Node* node)
{
    Node* left = node->getLeft();
    node->setRight(left->getRight());

    if (left->getRight() == nullptr)
    {
        left->getRight()->setParent(node);
    }

    left->setParent(node->getParent());

    if(node->getParent() == nullptr)
    {
        root = left;
    }
    else if (node == node->getParent()->getLeft())
    {
        node->getParent()->setLeft(left);        
    }
    else
    {
        node->getParent()->setRight(left);
    }

    left->setRight(node);
    node->setParent(left);
}

// Method to add a value to the RedBlack search tree
void RedBlackTree::add(uint32_t val)
{
    Node* newNode = new Node(val);
    Node* current = root;
    Node* parent = nullptr;

    // Find spot in tree to place new node
    while(current != nullptr)
    {
        parent = current;
        if(val < current->getData())
        {
            current = current->getLeft();
        }
        else
        {
            current = current->getRight();
        }
    }

    // Set the new node's parent and color
    newNode->setParent(parent);
    newNode->setColor(RED);

    if (parent == nullptr)
    {
        root = newNode;
        root->setColor(BLACK);
        return;
    }

    if (parent->getColor() == BLACK)
    {
        return;
    }

    Node* grandParent = parent->getParent();
    Node* uncle = nullptr;

    while(parent->getColor() == RED)
    {
        if (parent == grandParent->getLeft())
        {
            uncle = grandParent->getRight();

            // Is uncle red?
            if (uncle != nullptr && uncle->getColor() == RED)
            {
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                grandParent->setColor(RED);
                newNode = grandParent;
                parent = newNode->getParent();
                grandParent = parent->getParent();
            }
            else
            {
                // The uncle is black and the new node is right
                if (newNode == parent->getRight())
                {
                    rotateLeft(parent);
                    Node* temp = parent;
                    parent = newNode;
                    newNode = temp;
                }

                // The uncle is black and new node is right
                parent->setColor(BLACK);
                grandParent->setColor(RED);
                rotateLeft(grandParent);
            }
        // If parent is the right child of the grandparent.
        } else {
            uncle = grandParent->getLeft();

            if (uncle != nullptr && uncle->getColor() == RED) {
                parent->setColor(BLACK);
                uncle->setColor(BLACK);
                grandParent->setColor(RED);
                newNode = grandParent;
                parent = newNode->getParent();
                grandParent = parent->getParent();
            }
            else
            {
                if (newNode == parent->getLeft()) {
                    rotateRight(parent);

                    Node* temp = parent;
                    parent = newNode;
                    newNode = temp;
                }

                // Uncle is black and new node is a right child
                parent->setColor(BLACK);
                grandParent->setColor(RED);
                rotateLeft(grandParent);
            }
        }
    }

    root->setColor(BLACK);
}

// Method to remove a node from the RedBlack search tree
void RedBlackTree::remove(uint32_t val)
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
bool RedBlackTree::search(uint32_t data)
{
  return searchNode(root, data);
}

// Method to search for a node in the RedBlack search tree
bool RedBlackTree::searchNode(Node* node, uint32_t data) {
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

// Method to print the RedBlack search tree in order
void RedBlackTree::printInOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->getLeft());
    cout << node->getData() << " ";
    printInOrder(node->getRight());
}

// Public method for printing RedBlack tree.
void RedBlackTree::print()
{
    cout << "root is " << root->getData() << endl;
    printTree(root, 4);
}

// Method to print the RedBlack search tree in a visual way
void RedBlackTree::printTree(Node* node, uint32_t indent) {
    cout << "printTree called ";

    if (node == nullptr) {
        cout << "node is nullptr" << endl;
        return;
    }
    cout << "node is valid" << endl;


    cout << "  calling print for right" << endl;
    printTree(node->getRight(), indent + 4);

    for (uint32_t i = 0; i < indent; i++) {
        cout << " ";
    }
    cout << node->getData() << endl;
    if (node->getColor() == BLACK) {
        cout << " B";
    } else {
        cout << " R";
    }
    if (node->getParent() != nullptr)
    {
        cout << " P( " << node->getParent()->getData() << ")";
    }
    
    cout << "  calling print for left" << endl;
    printTree(node->getLeft(), indent + 4);
}

