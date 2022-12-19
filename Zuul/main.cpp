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

    vector<Room*> oHall;  // One Hall
    vector<Room*> mHall;  // Main Hall
    vector<Room*> eHall;  // E Hall
    vector<Room*> fHall;  // F Hall

    static const int oHallSegments = 5;
    static const int mHallSegments = 7;
    static const int eHallSegments = 3;
    static const int fHallSegments = 3;
    static const int totalRooms = 15;

    Room* currentRoom;

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

        printRoomDescription(currentRoom);

        bool finished = false;

        while (!finished) {
            finished = processCommand() ? false : true;
        }
        cout << "Thank you for playing.  Good bye." << endl;
    }

    /**
     *  Helper function to return Direction from string.
     */
    Direction getDirectionFromString(const char* str)
    {
        if (strcmp(str, "north") == 0) return Direction::north;
        if (strcmp(str, "south") == 0) return Direction::south;
        if (strcmp(str, "east") == 0) return Direction::east;
        if (strcmp(str, "west") == 0) return Direction::west;

        return Direction::unknown;
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
        else
        {
            if (strlen(command) > 0)
            {
                // handle commands with arguments here
                char *token = strtok(command, " ");

                if (strcmp(token, "go") == 0)
                {
                    char *dirStr = strtok(nullptr, "\n");
                    Direction dir = getDirectionFromString(dirStr);

                    if (dir != unknown)
                    {
                        goRoom(dir);
                    }
                }
                else
                {
                    cout << "Unknown command!" << endl;
                }
            }
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
        cout << "    go <north, south, east, west> - moves you in specific direction." << endl;
        cout << "        example: go south" << endl;
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
        for(int i = 0; i < oHallSegments; i++) {
            oHall.push_back(new Room("One Hall", "You are in One Hall."));
        }

        for(int i = 0; i < mHallSegments; i++) {
            mHall.push_back(new Room("Main Hall", "You are in Main Hall."));
        }

        for(int i = 0; i < eHallSegments; i++) {
            eHall.push_back(new Room("E Hall", "You are in E Hall."));
        }

        for(int i = 0; i < fHallSegments; i++) {
            fHall.push_back(new Room("F Hall", "You are in F Hall."));
        }

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

        currentRoom = rooms[0]; // Start off in cafeteria.
        
        // Setup cafeteria exits
        rooms[0]->setExit(Direction::east, oHall[1]);
        
        // Setup One Hall room exits
        rooms[1]->setExit(Direction::west, oHall[1]);
        rooms[2]->setExit(Direction::west, oHall[2]);
        
        // Setup F Hall room exits
        rooms[3]->setExit(Direction::north, fHall[0]);
        rooms[4]->setExit(Direction::north, fHall[1]);
        rooms[5]->setExit(Direction::north, fHall[2]);
        rooms[6]->setExit(Direction::north, eHall[2]);
        
        // Setup E Hall room exits
        rooms[7]->setExit(Direction::west, eHall[2]);
        rooms[8]->setExit(Direction::west, eHall[1]);
        rooms[9]->setExit(Direction::west, eHall[0]);
        rooms[12]->setExit(Direction::east, eHall[0]);
        rooms[13]->setExit(Direction::east, eHall[1]);
        
        // Setup Main Hall room exists
        rooms[10]->setExit(Direction::north, mHall[6]);
        rooms[11]->setExit(Direction::south, mHall[4]);
        rooms[14]->setExit(Direction::south, mHall[1]);
        
        // Setup One hall
        oHall[0]->setExit(Direction::east, mHall[0]);
        oHall[1]->setExit(Direction::east, rooms[1]);
        oHall[2]->setExit(Direction::east, rooms[2]);
        oHall[3]->setExit(Direction::east, fHall[0]);
        
        oHall[1]->setExit(Direction::west, rooms[0]);
        
        oHall[0]->setExit(Direction::south, oHall[1]);
        oHall[1]->setExit(Direction::south, oHall[2]);
        oHall[2]->setExit(Direction::south, oHall[3]);
        oHall[3]->setExit(Direction::south, oHall[4]);
        
        oHall[1]->setExit(Direction::north, oHall[0]);
        oHall[2]->setExit(Direction::north, oHall[1]);
        oHall[3]->setExit(Direction::north, oHall[2]);
        oHall[4]->setExit(Direction::north, oHall[3]);
        
        // Setup F hall
        fHall[0]->setExit(Direction::east, fHall[1]);
        fHall[1]->setExit(Direction::east, fHall[2]);
        fHall[2]->setExit(Direction::east, eHall[2]);
        
        fHall[0]->setExit(Direction::west, oHall[3]);
        fHall[1]->setExit(Direction::west, fHall[0]);
        fHall[2]->setExit(Direction::west, eHall[1]);
        
        fHall[0]->setExit(Direction::south, rooms[3]);
        fHall[1]->setExit(Direction::south, rooms[4]);
        fHall[2]->setExit(Direction::south, rooms[5]);
        
        // Setup E hall
        eHall[0]->setExit(Direction::south, eHall[1]);
        eHall[1]->setExit(Direction::south, eHall[2]);
        eHall[2]->setExit(Direction::south, rooms[6]);
        
        eHall[0]->setExit(Direction::north, mHall[3]);
        eHall[1]->setExit(Direction::north, eHall[0]);
        eHall[2]->setExit(Direction::north, eHall[1]);
        
        eHall[0]->setExit(Direction::east, rooms[12]);
        eHall[1]->setExit(Direction::east, rooms[13]);
        eHall[0]->setExit(Direction::west, rooms[9]);
        eHall[1]->setExit(Direction::west, rooms[8]);
        eHall[2]->setExit(Direction::west, rooms[7]);
        
        // Setup M hall
        mHall[0]->setExit(Direction::east, mHall[1]);
        mHall[1]->setExit(Direction::east, mHall[2]);
        mHall[2]->setExit(Direction::east, mHall[3]);
        mHall[3]->setExit(Direction::east, mHall[4]);
        mHall[4]->setExit(Direction::east, mHall[5]);
        mHall[5]->setExit(Direction::east, mHall[6]);
        
        mHall[6]->setExit(Direction::west, mHall[5]);
        mHall[5]->setExit(Direction::west, mHall[4]);
        mHall[4]->setExit(Direction::west, mHall[3]);
        mHall[3]->setExit(Direction::west, mHall[2]);
        mHall[2]->setExit(Direction::west, mHall[1]);
        mHall[1]->setExit(Direction::west, mHall[0]);        
        mHall[0]->setExit(Direction::west, oHall[0]);
        
        mHall[1]->setExit(Direction::north, rooms[14]);
        
        mHall[4]->setExit(Direction::north, rooms[11]);
        mHall[6]->setExit(Direction::south, rooms[10]);
        mHall[3]->setExit(Direction::south, eHall[0]);
    }

    /**
     * Moves from current room to next room associated with direction.
     */
    void goRoom(Direction direction)
    {
        cout << "Moved " << Room::getDirectionString(direction) << endl;

        // Try to leave current room.
        Room* nextRoom = currentRoom->getExit(direction);

        if (nextRoom == nullptr) {
            cout << "There is no door in that direction!" << endl;
        } else {
            currentRoom = nextRoom;
        }
        printRoomDescription(currentRoom);
    }

    /**
     * Print out description for specified room
     */
    void printRoomDescription(Room* room)
    {
        char roomDesc[512];
        room->getDescriptionExtendedString(roomDesc, 512);
        cout << roomDesc << endl;
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