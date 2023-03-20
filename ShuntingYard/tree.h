/*
 * Tree definition
 *
 * Colby Waters
 * 3/19/2023
 */
#ifndef Tree_H
#define Tree_H

/*
 * Tree binary node class definition
 */
class BinaryNode
{
public:
    char val;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(char c)
    {
        val = c;
        left = nullptr;
        right = nullptr;
    }
};

#endif
