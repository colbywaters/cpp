/*
 * Graph definition for Graph Creator
 *
 * Colby Waters
 * 6/5/2023
 */
#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "edge.h"

using namespace std;

// Graph class definition
class Graph
{
public:
    void addVertex(string& label);
    void remVertex(string& label);

    bool addEdge(string& a, string& b, uint32_t weight);
    void remEdge(string& a, string& b);

    void print();

    uint32_t shortest(string& a, string& b);

private:
    list<Edge*> edges;                // list of all edges

    map<string, Vertex*> vertices;    // map string to vertex for easy lookup
    map<Vertex*, list<Edge*>> vertexEdges;  // list of edges per vertex
};

#endif