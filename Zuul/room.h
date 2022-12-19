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
    west,
    unknown
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

    vector<Item*> items;

    bool partyRoom;

public:
    Room()
    {
        strcpy(name, "No name");
        strcpy(description, "No description");
        partyRoom = false;
    }

    Room(const char* new_name, const char* new_desc)
    {
        strncpy(name, new_name, MAX_ROOM_NAME_SIZE);
        strncpy(description, new_desc, MAX_ROOM_NAME_DESC_SIZE);
        partyRoom = false;
    }

    /**
     * Get name of this room.
     */
    const char* getName() { return name; }

    /**
     * Get description of this room.
     */
    const char* getDescription() { return description; }

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

    static const char* getDirectionString(Direction dir)
    {
        switch(dir)
        {
            case north: return "north";
            case south: return "south";
            case east:  return "east";
            case west:  return "west";
            default:
                break;
        }
        return nullptr;
    }

    /**
     * Return a string describing the room and it's exits, for example
     * "Exits: north west".
     */
    void getDescriptionExtendedString(char* exitsString, int exitsStringSize)
    {
        strcpy(exitsString, description);
        strcat(exitsString, "\n");

        getExitString(exitsString, exitsStringSize);

        if (items.size() > 0) {
            strcat(exitsString, "\nThere are the following items in this room:\n");

    	    for(int i = 0; i < items.size(); i++) {
                strcat(exitsString, items[i]->getDescription());
                strcat(exitsString, " ");
    	    }
            strcat(exitsString, "\n");
        } else {
        	strcat(exitsString, "\nThere are no items in this room.\n");
        }
    }

    /**
     * Return a string describing the room's exits, for example
     * "Exits: north west".
     * Need to ensure string is initialized before using this.
     */
    void getExitString(char* exitsString, int exitsStringSize)
    {
        strcat(exitsString, "Exits: ");

        map<Direction, Room*>::iterator it;

        for (it = exits.begin(); it != exits.end(); it++)
        {
            Direction dir = it->first;

            strcat(exitsString, getDirectionString(dir));
            strcat(exitsString, " ");
        }
    }

    /*
     * Get items from the room.
     */
    Item* getItem(int index) {
    	return items[index];
    }
    
    /*
     * Set a specific item in the room
     */
    void setItem(Item* item) {
        items.push_back(item);
    }

    /*
     * Removes an item from room.
     */
    Item* removeItem(const char* item) {

    	Item* returnItem = nullptr;
        int foundItem = -1;
    	
    	for(int i = 0; i < items.size() && returnItem == nullptr; i++)
        {
    		if (strcmp(items[i]->getDescription(), item) == 0)
            {
    			returnItem = items[i];
                foundItem = i;
    		}
    	}
    	
    	if (returnItem != nullptr && foundItem != -1)
        {
            items.erase(items.begin()+foundItem);
    	}
    	
    	return returnItem;
    }

    /*
     * Make this be the party room!
     */
    void setAsPartyRoom() {
    	partyRoom = true;
    }
    
    /*
     * Is this the party room?
     */
    bool isPartyRoom() {
    	return partyRoom;
    }

    /*
     * Are we allowed to enter this room?
     */
    bool canEnterRoom(vector<Item*>& inventory) {
    	
    	if (partyRoom == false) {
    		return true;
    	}
    	
    	bool hasTicket = false;
    	bool hasCake = false;
    	bool hasPresent = false;
    	
    	for(int i = 0; i < inventory.size(); i++)
        {
    		if (strcmp(inventory[i]->getDescription(), "ticket") == 0) {
    			hasTicket = true;
    		}
    		
            if (strcmp(inventory[i]->getDescription(), "cake") == 0) {
    			hasCake = true;
    		}
    		
            if (strcmp(inventory[i]->getDescription(), "present") == 0) {
    			hasPresent = true;
    		}
    	}
    	
        // This is the party room. Can only enter if you have a ticket, cake, and a present.
    	return (hasTicket && hasCake && hasPresent);
    }
};