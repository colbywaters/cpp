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
 * Node class definition for characters
 */
class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    // Method to add a value to the binary search tree
    void addValue(int val);

/*
    // Method to remove a node from the binary search tree
    void remove_node(int val) {
        // Find the node to be removed
        Node* current = root;
        Node* parent = nullptr;
        while (current != nullptr && current->data != val) {
            parent = current;
            if (val < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        // If the node isn't in the tree, return
        if (current == nullptr) {
            return;
        }

        // If the node has no children, simply delete it
        if (current->left == nullptr && current->right == nullptr) {
            if (current == root) {
                root = nullptr;
            }
            else if (current == parent->left) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
            delete current;
        }

        // If the node has one child, replace it with that child
        else if (current->left == nullptr || current->right == nullptr) {
            Node* child;
            if (current->left == nullptr) {
                child = current->right;
            }
            else {
                child = current->left;
            }
            if (current == root) {
                root = child;
            }
            else if (current == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
            delete current;
        }

        // If the node has two children, find its in-order successor and replace it with that
        else {
            Node* successor = current->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            int temp = successor->data;
            remove_node(temp);
            current->data = temp;
        }
    }

    // Method to search for a node with a given value in the binary search tree
    bool search_node(int val) {
        Node* current = root;
        while (current != nullptr)
*/

private:
    Node* root;
};

#endif // BinaryTree_H
