/*
 * Zuul Birthday Party implementation
 *
 * File: room.h
 * Description: Room definition
 *
 * Colby Waters
 * 12/18/2022
 */

#include <map>

using namespace std;

#define MAX_ROOM_NAME_SIZE 128
#define MAX_ROOM_NAME_DESC_SIZE 512

/*
 * Direction used for exits
 */
enum Direction
{
    north,
    south,
    east,
    west
};

/*
 * Room class that stores name, description, and exits
 */
class Room 
{
private:
	char name[MAX_ROOM_NAME_SIZE];              // name of room
    char description[MAX_ROOM_NAME_DESC_SIZE];  // description for room.

    // Map associates direction with Room. (example: "north", Room F-1)
    map<Direction, Room*> exits;  // stores exits of this room.

public:
    Room()
    {
        strcpy(name, "No name");
        strcpy(description, "No description");
    }

    Room(const char* new_name, const char* new_desc)
    {
        strncpy(name, new_name, MAX_ROOM_NAME_SIZE);
        strncpy(description, new_desc, MAX_ROOM_NAME_DESC_SIZE);
    }

    /**
     * Define an exit from this room.
     */
    void setExit(Direction dir, Room* neighbor) 
    {
        exits[dir] = neighbor;
    }

    /**
     * Return the room that is reached if we go from this room in direction
     * "direction". If there is no room in that direction, return null.
     */
    Room* getExit(Direction dir) 
    {   
        return exits[dir];
    }
};