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
    if (node == nullptr) { return; }

    Node* right = node->getRight();

    if (right == nullptr)
    {
        return;
    }

    node->setRight(right->getLeft());

    if (right->getLeft() != nullptr)
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
    if (node == nullptr) { return; }

    Node* left = node->getLeft();

    if (left == nullptr)
    {
        return;
    }

    node->setRight(left->getRight());

    if (left->getRight() != nullptr)
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

    if (newNode->getData() > parent->getData())
    {        
        parent->setRight(newNode);        
    }
    else
    {
        parent->setLeft(newNode);
    }

    if (parent->getColor() == BLACK)
    {
        return;
    }

    Node* grandParent = parent->getParent();
    Node* uncle = nullptr;

    while(grandParent != nullptr && parent != nullptr && parent->getColor() == RED)
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

                if (parent != nullptr)
                {
                    grandParent = parent->getParent();
                }
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
                if (parent != nullptr)
                {
                    grandParent = parent->getParent();
                }
                else {
                    grandParent = nullptr;
                }
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

void RedBlackTree::rebalanceAfterRemoval(Node* node, Node* parent)
{
    Node* sibling;
    while (node != root && (node == nullptr || node->getColor() == BLACK))
    {
        if (node == parent->getLeft())
        {
            sibling = parent->getRight();

            if (sibling->getColor() == RED)
            {
                sibling->setColor(BLACK);
                parent->setColor(RED);
                rotateLeft(parent);
                sibling = parent->getRight();
            }

            if ((sibling->getLeft() == nullptr || sibling->getLeft()->getColor() == BLACK) &&
                (sibling->getRight() == nullptr || sibling->getRight()->getColor() == BLACK))
            {
                sibling->setColor(RED);
                node = parent;
                parent = node->getParent();
            }
            else
            {
                if (sibling->getRight() == nullptr || sibling->getRight()->getColor() == BLACK)
                {
                    sibling->getLeft()->setColor(BLACK);
                    sibling->setColor(RED);
                    rotateRight(sibling);
                    sibling = parent->getRight();
                }

                sibling->setColor(parent->getColor());
                parent->setColor(BLACK);
                sibling->getRight()->setColor(BLACK);
                rotateLeft(parent);
                node = root; // Terminate the loop
            }
        }
        else
        {
            sibling = parent->getLeft();

            if (sibling->getColor() == RED)
            {
                sibling->setColor(BLACK);
                parent->setColor(RED);
                rotateRight(parent);
                sibling = parent->getLeft();
            }

            if ((sibling->getRight() == nullptr || sibling->getRight()->getColor() == BLACK) &&
                (sibling->getLeft() == nullptr || sibling->getLeft()->getColor() == BLACK))
            {
                sibling->setColor(RED);
                node = parent;
                parent = node->getParent();
            }
            else
            {
                if (sibling->getLeft() == nullptr || sibling->getLeft()->getColor() == BLACK)
                {
                    sibling->getRight()->setColor(BLACK);
                    sibling->setColor(RED);
                    rotateLeft(sibling);
                    sibling = parent->getLeft();
                }

                sibling->setColor(parent->getColor());
                parent->setColor(BLACK);
                sibling->getLeft()->setColor(BLACK);
                rotateRight(parent);
                node = root; // Terminate the loop
            }
        }
    }

    if (node != nullptr)
    {
        node->setColor(BLACK);
    }
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

    // 1. If the node to be deleted has no children, simply remove it and update the parent node.
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
    // 2. If the node to be deleted has only one child, replace the node with its child.
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
        child->setParent(parent); // Update the child's parent

        if (child != nullptr && child->getColor() == BLACK)
        {
            // Rebalance the tree
            rebalanceAfterRemoval(child, parent);
        }
    }
    // 3. If the node to be deleted has two children, then replace
    //    the node with its in-order successor, which is the
    //    leftmost node in the right subtree. Then delete the in-order
    //    successor node as if it has at most one child.
    else
    {
        Node* successor = current->getLeft();

        while (successor->getRight() != nullptr) {
            successor = successor->getRight();
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
    if (root == nullptr)
    {
        cout << "Empty tree!" << endl;
        return;
    }

    cout << "Root value is " << root->getData() << endl;

    if (root->getParent())
    {
        cout << "Root parent value is " << root->getParent()->getData() << endl;
    }

    printTree(root, 4);
}

// Method to print the RedBlack search tree in a visual way
void RedBlackTree::printTree(Node* node, uint32_t indent) {

    if (node == nullptr) {
        return;
    }

    printTree(node->getRight(), indent + 4);

    for (uint32_t i = 0; i < indent; i++) {
        cout << " ";
    }
    cout << node->getData();
    if (node->getColor() == BLACK) {
        cout << " B";
    } else {
        cout << " R";
    }
    if (node->getParent() != nullptr)
    {
        cout << " P( " << node->getParent()->getData() << ")";
    }
    cout << endl;
    
    printTree(node->getLeft(), indent + 4);
}

