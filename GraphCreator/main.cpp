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

// Print the available commands for the main parser!
void printCommands()
{
      cout << "Enter commands to update graph." << endl;
      cout << "   ADD_V - Add vertex node to graph." << endl;
      cout << "   ADD_E - Add edge to graph." << endl;
      cout << "   REMOVE_V - Remove vertex node to graph." << endl;
      cout << "   REMOVE_E - Remove edge to graph." << endl;
      cout << "   SHORTEST - Find shortest path." << endl;
      cout << "   PRINT - Print graph information" << endl;
      cout << "   QUIT - Exits program." << endl;
      cout << "------------------------------------------------" << endl;
}

int main()
{
    bool hasQuit = false;

    cout << "------------------------------------------------" << endl;
    cout << " Graph - Colby Waters" << endl;
    cout << "------------------------------------------------" << endl;
    printCommands();

    Graph g;

    // Main command parser loop
    while(hasQuit == false)
    {
        char command[256];
        cout << "cmd>: ";
        cin.getline(command,sizeof(command));

        if (strcmp(command, "ADD_V") == 0 || strcmp(command, "add_v") == 0)
        {
            cout << "Enter label for vertex: ";
            cin.getline(command, sizeof(command));
            string label = command;

            cout << "----- Created Vertex ---------------------" << endl;        
            cout << "Label: " << label.c_str() << endl;

            g.addVertex(label);
        }
        else if (strcmp(command, "ADD_E") == 0 || strcmp(command, "add_e") == 0)
        {
            cout << "Enter first vertex name: ";
            cin.getline(command, sizeof(command));
            string firstLabel = command;

            cout << "Enter second vertex name: ";
            cin.getline(command, sizeof(command));
            string secondLabel = command;

            cout << "Enter weight: ";
            cin.getline(command, sizeof(command));
            uint32_t weight = atoi(command);

            if (g.addEdge(firstLabel, secondLabel, weight) == true)
            {
                cout << "----- Created Edge ---------------------" << endl;
                cout << "First Label: " << firstLabel.c_str() << endl;
                cout << "Second Label: " << secondLabel.c_str() << endl;
                cout << "Weight: " << weight << endl;
            }
        }
        else if (strcmp(command, "REMOVE_V") == 0 || strcmp(command, "remove_v") == 0)
        {
            cout << "Enter label for vertex to remove: ";
            cin.getline(command, sizeof(command));
            string label = command;

            cout << "----- Removed Vertex ---------------------" << endl;        
            cout << "Label: " << label.c_str() << endl;

            g.remVertex(label);
        }
        else if (strcmp(command, "REMOVE_E") == 0 || strcmp(command, "remove_e") == 0)
        {
            cout << "Enter first vertex name: ";
            cin.getline(command, sizeof(command));
            string firstLabel = command;

            cout << "Enter second vertex name: ";
            cin.getline(command, sizeof(command));
            string secondLabel = command;

            g.remEdge(firstLabel, secondLabel);

            cout << "----- Removed Edge ---------------------" << endl;
            cout << "First Vertex: " << firstLabel.c_str() << endl;
            cout << "Second Vertex: " << secondLabel.c_str() << endl;
        }
        else if (strcmp(command, "SHORTEST") == 0)
        {
            cout << "Enter first node name: ";
            cin.getline(command, sizeof(command));
            string firstNode = command;

            cout << "Enter second node name: ";
            cin.getline(command, sizeof(command));
            string secondNode = command;
        }
        else if (strcmp(command, "PRINT") == 0 || strcmp(command, "print") == 0)
        {
            g.print();
        }
        else if (strcmp(command, "QUIT") == 0 || strcmp(command, "quit") == 0)
        {
          cout << "QUIT command received" << endl;
          hasQuit = true;
          cout << "Thank you! Exiting Graph Creator!" << endl;
        }
        else
        {
            cout << "Unknown command received." << endl;

            printCommands();
        }
    }
}