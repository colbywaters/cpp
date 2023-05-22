/*
 * Main function
 *
 * Colby Waters
 * 4/7/2023
 */
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>

#include "redblacktree.h"

using namespace std;

// Print the available commands for the main parser!
void printCommands()
{
      cout << "Enter commands to add, search, delete, and print binary tree." << endl;
      cout << "   ADD - Add number to binary tree." << endl;
      cout << "   FILE - Add numbers from file to binary tree." << endl;
      cout << "   SEARCH - Search for number in binary tree." << endl;
      cout << "   REMOVE - Deletes number in tree." << endl;
      cout << "   PRINT - Prints tree." << endl;
      cout << "   QUIT - Exits program." << endl;
      cout << "------------------------------------------------" << endl;
}

/*
 * addFromFile - Add numbers from a file. Numbers are on a single line and separated by a space.
 */
void addFromFile(const char* filename, RedBlackTree& tree)
{
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file \"" << filename << "\" for reading.\n";
        return;
    }

    int num;

    while (inFile >> num) {
        tree.add(num);
    }
    inFile.close();
}

/*
 * main - This is main function for binary tree. Implements main parser.
 */
/*
int main()
{
    RedBlackTree tree;

    addFromFile("numbers.txt", tree);

    tree.print();

    return 0;
}
*/

int main()
{
    RedBlackTree tree;

    bool hasQuit = false;

    cout << "------------------------------------------------" << endl;
    cout << " Red Black Tree - Colby Waters" << endl;
    cout << "------------------------------------------------" << endl;
    printCommands();

    // Main command parser loop
    while(hasQuit == false)
    {
        char command[256];
        cout << "cmd>: ";
        cin.getline(command,sizeof(command));

        if (strcmp(command, "ADD") == 0 || strcmp(command, "add") == 0)
        {
            cout << "Enter number to add: ";
            cin.getline(command, sizeof(command));

            uint32_t num = atoi(command);

            // Add media entry
            tree.add(num);
        }
        else if (strcmp(command, "FILE") == 0 || strcmp(command, "file") == 0)
        {
            cout << "Enter filename where numbers come from: ";
            cin.getline(command, sizeof(command));

            addFromFile(command, tree);
        }
        else if (strcmp(command, "SEARCH") == 0)
        {
            cout << "Enter number: ";
            cin.getline(command, sizeof(command));

            uint32_t num = atoi(command);

            // Search for media entry
            bool found = tree.search(num);

            if (found) {
                cout << "Found number in tree!" << endl;
            } else {
                cout << "Did not find number!" << endl;
            }
        }
        else if (strcmp(command, "PRINT") == 0 || strcmp(command, "print") == 0)
        {
            tree.print();
        }
        else if (strcmp(command, "REMOVE") == 0 || strcmp(command, "remove") == 0)
        {
            cout << "Enter number: ";
            cin.getline(command, sizeof(command));

            uint32_t num = atoi(command);

            // Delete media entry
            tree.remove(num);
        }
        else if (strcmp(command, "QUIT") == 0 || strcmp(command, "quit") == 0)
        {
          cout << "QUIT command received" << endl;
          hasQuit = true;
          cout << "Thank you! Exiting Binary Tree!" << endl;
        }
        else
        {
            cout << "Unknown command received." << endl;

            printCommands();
        }
    }
}