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

#include "vertex.h"

using namespace std;

// Constructor for vertex
Vertex::Vertex(string& l)
{
    label = l;
}

// Return label for vertex
string& Vertex::getLabel()
{
    return label;
}