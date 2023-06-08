/*
 * Main function for Graph Creator
 *
 * Colby Waters
 * 6/5/2023
 */
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <map>

#include "edge.h"

using namespace std;

// Constructor for an Edge
Edge::Edge(Vertex* pA, Vertex* pB, uint32_t weight)
{
    this->pA = pA;
    this->pB = pB;
    this->weight = weight;
}

// Returns other vertex for an edge.
Vertex* Edge::otherVertex(Vertex* pMe)
{
    if (pMe == pA) return pB;
    return pA;
}

// Print the edge information
void Edge::print()
{
    cout << pA->getLabel() << " => "
            << pB->getLabel() << " weight( " << weight << " )"  << endl;
}
