/*
 * Edge definition for Graph Creator
 *
 * Colby Waters
 * 6/5/2023
 */
#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

using namespace std;

// Edge defintion
class Edge
{
public:
    Edge(Vertex* pA, Vertex* pB, uint32_t weight);

    Vertex* otherVertex(Vertex* pMe);

    void print();

private:
    Vertex* pA;
    Vertex* pB;
    uint32_t weight;
};

#endif