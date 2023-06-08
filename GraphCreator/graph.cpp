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

#include "graph.h"

using namespace std;

// Some notes:
//   1. When a vertex is created, it will be assigned a unique number to identify it.
//   2. When an edge is created, it will be assigned a unique number to identify it along
//      with 2 vertex ids for which the edge connects.
//   3. If I have a vertex then how do I find the edge?
//       a. Use a map to start 

void Graph::addVertex(string& label)
{
    Vertex* pVertex = new Vertex(label);
    vertices[label] = pVertex;

    if (vertices.find(label) != vertices.end())
    {
        cout << "Successfully added vertex " << label << endl;
    }
}

void Graph::remVertex(string& label)
{
    if (vertices.find(label) != vertices.end())
    {
        Vertex* pVertex = vertices[label];
        delete pVertex;
        vertices.erase(label);
        cout << "Successfully removed vertex " << label << endl;
    }
    else
    {
        cout << "Vertex was not found in graph." << endl;
    }
}

bool Graph::addEdge(string& a, string& b, uint32_t weight)
{
    if (vertices.find(a) == vertices.end() ||
        vertices.find(b) == vertices.end())
    {
        cout << "Could not add edge. Vertex not found." << endl;
        return false;
    }

    Vertex* pA = vertices[a];
    Vertex* pB = vertices[b];

    Edge* pEdge = new Edge(pA, pB, weight);


    edges.push_back(pEdge);

    vertexEdges[pA].push_back(pEdge);
    vertexEdges[pB].push_back(pEdge);

    return true;
}

void Graph::remEdge(string& a, string& b)
{
    cout << "Removing edge: " << a << " => " << b << endl;
    Vertex* pA = vertices[a];
    Vertex* pB = vertices[b];

    Edge* pFoundEdge = nullptr;

    list<Edge*>::iterator it;
    for (it = vertexEdges[pA].begin(); it != vertexEdges[pA].end(); ++it)
    {
        Edge* pEdge = *it;

        if (pEdge != nullptr && pEdge->otherVertex(pA) == pB)
        {
            // Found edge... let's delete this.
            pFoundEdge = pEdge;
            cout << "    Found edge!" << endl;
        }
    }

    if (pFoundEdge != nullptr)
    {
        list<Edge*>* edgesA = &vertexEdges[pA];
        list<Edge*>* edgesB = &vertexEdges[pB];

        edgesA->remove(pFoundEdge);
        edgesB->remove(pFoundEdge);
        edges.remove(pFoundEdge);
    }
}

void Graph::print()
{
    // loop over vertices and dump these.
    map<string, Vertex*>::iterator it_v;

    uint32_t numVertices = vertices.size();
    uint32_t numEdges = edges.size();



    cout << "--- Vertices ---------------" << endl;

    if (numVertices == 0)
    {
        cout << "Graph has no vertices!" << endl;
        return;
    }

    for (it_v = vertices.begin(); it_v != vertices.end(); it_v++)
    {
        std::cout << it_v->first << endl;
    }

    cout << endl << "--- Edges ---------------" << endl;

    if (numEdges == 0)
    {
        cout << "Graph doesn't have edges!" << endl;
        return;
    }

    list<Edge*>::iterator it_e;

    for (it_e = edges.begin(); it_e != edges.end(); it_e++)
    {
        Edge* pEdge = *it_e;

        pEdge->print();
    }

}

uint32_t Graph::shortest(string& a, string& b)
{
    return 0;
}