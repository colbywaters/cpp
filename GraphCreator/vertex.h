/*
 * Main function for Graph Creator
 *
 * Colby Waters
 * 6/5/2023
 */
#ifndef VERTEX_H
#define VERTEX_H

#include <string>

using namespace std;

class Vertex
{
public:
    Vertex(string& l);

    string& getLabel();

private:
    string label;
};

#endif