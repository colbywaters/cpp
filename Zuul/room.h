/*
 * Zuul Birthday Party implementation
 *
 * File: room.h
 * Description: Room definition
 *
 * Colby Waters
 * 12/18/2022
 */

#define MAX_ROOM_NAME_SIZE 128
#define MAX_ROOM_NAME_DESC_SIZE 512

class Room 
{
public:
	char name[MAX_ROOM_NAME_SIZE];              // name of room
    char description[MAX_ROOM_NAME_DESC_SIZE];  // description for room.

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
};