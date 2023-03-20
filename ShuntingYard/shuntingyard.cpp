/*
 * Shunting Yard implementation
 *
 * Colby Waters
 * 3/19/2023
 */
#include <iostream>
#include <cstring>
#include <stack>   // Used for node stack for tree expression. Can use my own stack for this but it's for characters!
#include <string>  // Used for getline for cin!
#include "node.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"

using namespace std;

/*
 * Return precedence level for operator. Higher precendence has priority.
 */
int precedence(char op)
{
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}


/*
 * Take a string input and return output in a queue.
 */
void shuntingYard(const char* input, Queue& output)
{
    Stack opStack;

    if (input == nullptr)
    {
        return;
    }

    int inputLen = strlen(input);

    for (int i = 0; i < inputLen; i++)
    {
        char c = input[i];

        if (isdigit(c))
        {
            output.enqueue(c);
        }
        else if (c == '(')
        {
            opStack.push(c);
        }
        else if (c == ')')
        {
            while (!opStack.empty() && opStack.peek() != '(') {
                output.enqueue(opStack.peek());
                opStack.pop();
            }
            if (!opStack.empty() && opStack.peek() == '(') {
                opStack.pop();
            }
        } else {
            while (!opStack.empty() && opStack.peek() != '(' &&
                   precedence(c) <= precedence(opStack.peek()))
            {
                output.enqueue(opStack.peek());
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty())
    {
        output.enqueue(opStack.peek());
        opStack.pop();
    }
}

/*
 * Build expression tree from input queue
 */
BinaryNode* buildExpressionTree(Queue& input)
{
    stack<BinaryNode*> nodeStack;

    while (!input.empty())
    {
        char c = input.front();

        input.dequeue();

        if (isdigit(c))
        {
            nodeStack.push(new BinaryNode(c));
        }
        else
        {
            BinaryNode* right = nodeStack.top();
            nodeStack.pop();
            BinaryNode* left = nodeStack.top();
            nodeStack.pop();
            BinaryNode* node = new BinaryNode(c);
            node->left = left;
            node->right = right;
            nodeStack.push(node);
        }
    }

    return nodeStack.top();
}

/*
 * Print infix notation
 */
void printInfix(BinaryNode* node)
{
    if (node->left && node->right)
    {
        cout << "(";
        printInfix(node->left);
        cout << " " << node->val << " ";
        printInfix(node->right);
        cout << ")";
    }
    else
    {
        cout << node->val;
    }
}

/*
 * Print prefix notation
 */
void printPrefix(BinaryNode* node)
{
    if (node->left && node->right)
    {
        cout << node->val;
        printPrefix(node->left);
        printPrefix(node->right);
    }
    else
    {
        cout << node->val;
    }
}

/*
 * Print postfix notation
 */
void printPostfix(BinaryNode* node)
{
    if (node->left && node->right)
    {
        printPostfix(node->left);
        printPostfix(node->right);
        cout << node->val;
    }
    else
    {
        cout << node->val;
    }
}

/*
 * Main implementation
 */
int main()
{
    // note: Using string here since it's silly to use cstring for getline.
    string input;
    cout << "Enter an infix expression: ";
    getline(cin, input);

    Queue output;

    shuntingYard(input.c_str(), output);
    cout << "Completed Shunting Yard Algorithm" << endl;

    BinaryNode* expression = buildExpressionTree(output);

    cout << "Infix expression: " << endl;
    printInfix(expression);
    cout << endl;

    cout << "Postfix expression: " << endl;
    printPostfix(expression);
    cout << endl;

    cout << "Infix expression: " << endl;
    printPrefix(expression);
    cout << endl;
}
