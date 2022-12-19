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
 * Need this because we're forced to use cstring instead of std::string
 * Found this on https://stackoverflow.com/questions/4157687/using-char-as-a-key-in-stdmap
 */
struct cmp_str
{
   bool operator()(char const *a, char const *b) const
   {
      return std::strcmp(a, b) < 0;
   }
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
    map<char*, Room*, cmp_str> exits;  // stores exits of this room.

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
    void setExit(const char* direction, Room* neighbor) 
    {
        int len = strlen(direction);
        char* dir = new char[len];
        exits[dir] = neighbor;
    }
};