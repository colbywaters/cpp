/*
 * Zuul Birthday Party implementation
 *
 * Colby Waters
 * 12/18/2022
 */
#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"

using namespace std;

/**
 * This is the main class for the game "Zuul Birthday" game.
 * 
 * The objective of the game is to find the birthday party but don't
 * forget to bring the cake and a present. You have to find the
 * rooms with the present and cake and add those to your inventory
 * and then bring these to the birthday party. You will not be allowed
 * to enter birthday party without these. If you have them then
 * you win!
 * 
 *  To play this game, create an instance of this class and call the "play"
 *  method.
 * 
 *  This main class creates and initializes all the others: it creates all
 *  rooms, creates the parser and starts the game.  It also evaluates and
 *  executes the commands that the parser returns.
 */
class Game 
{
private:
    vector<Room*> rooms;

public:
    /**
     *  Game constructor
     */
    Game()
    {
        createRooms();
    }

    /**
     *  Game destructor
     */
    ~Game() {}

    /**
     *  Main play routine.  Loops until end of play.
     */
    void play()
    {
        printWelcome();

        bool finished = false;

        while (!finished) {
            finished = processCommand() ? false : true;
        }
        cout << "Thank you for playing.  Good bye." << endl;
    }

    /**
     *  Parse command from user
     */
    bool processCommand()
    {
        char command[256];
        cout << "cmd>: ";
        cin.getline(command,sizeof(command));

        cout << "You typed: " << command << endl;

        if (strcmp(command, "quit") == 0)
        {
            return false;  // They want to quit so return false.
        }
        else if (strcmp(command, "help") == 0)
        {
            printHelp();
        }

        return true;  // false means we don't quit
    }

    /**
     * Print out some helpful information.
     */
    void printHelp() 
    {
        cout << endl;
        cout << "You are lost. You are alone. You wander" << endl;
        cout << "around at Sunset Highschool." << endl;
        cout << endl;
        cout << "Your command words are:" << endl;

        cout << "    help - prints this help information." << endl;
        cout << "    quit - quits program." << endl;

    }

    /**
     * Print out welcome information.
     */
    void printWelcome()
    {
        cout << endl;
        cout << "Welcome to Sunset Highschool!" << endl;
        cout << "There is a party here and you have to find it!" << endl;
        cout << "Before you can enter the party room you'll need" << endl;
        cout << "to find the cake and present in the other rooms" << endl;
        cout << "to bring to the party. Here is a ticket and be sure" << endl;
        cout << "not to lose your ticket! Have fun!" << endl;
        cout << "" << endl;
        cout << "Type 'help' if you need help." << endl;
        cout << endl;
    }

    void createRooms()
    {
        rooms.push_back(new Room("Cafeteria", "You are in the cafeteria."));
    	rooms.push_back(new Room("Staff", "You are in the staff room."));
    	rooms.push_back(new Room("1-20", "You are in the 1-20 room."));
    	rooms.push_back(new Room("F-1", "You are in the F-1 room."));
    	rooms.push_back(new Room("F-2", "You are in the F-2 room."));
    	rooms.push_back(new Room("F-3", "You are in the F-3 room."));
    	rooms.push_back(new Room("F-4", "You are in the F-4 room."));
    	rooms.push_back(new Room("E-5", "You are in the E-5 room."));
    	rooms.push_back(new Room("E-4", "You are in the F-1 room."));
    	rooms.push_back(new Room("E-3", "You are in the F-2 room."));
    	rooms.push_back(new Room("Main Office", "You are in the Main Office."));
    	rooms.push_back(new Room("Counseling", "You are in the Counseling Office."));
    	rooms.push_back(new Room("E-1", "You are in the E-1 room."));
    	rooms.push_back(new Room("E-2", "You are in the E-2 room."));
    	rooms.push_back(new Room("M-1", "You are in the M-1 room."));
    }
};

/*
 * main - This is main function for Zuul game.
 */
int main()
{
    cout << "------------------------------------------------" << endl;
    cout << " Zuul Birthday Party - Colby Waters - Dec 2022"   << endl;
    cout << "------------------------------------------------" << endl << endl;

    Game* game = new Game();

    game->play();

    return 0;
}