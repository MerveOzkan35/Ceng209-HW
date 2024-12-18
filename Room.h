#ifndef ROOM_H
#define ROOM_H

/*
typedef struct Key Key;
typedef struct Character Character;
typedef struct Item Item;
*/
//typedef struct Character Character;

#include "Character.h"
#include "Item.h"
#include "Key.h"

typedef struct Room {
    char *name;               
    char *description;       
    struct Room *south;          
    struct Room *east;           
    struct Room *west;           
    struct Room *north; 
    Key key;
     struct Character *activeCharacter;// Represents the chosen character from list[3].
     struct Character *charList[3];// Represents the pool of possible characters in the room.
    Item itemList[5]; //Every room has 5 items at most   
    int itemCount;    
    int charCount; 
} Room;

// Function declarations
void initRoom(Room *room, char *name, char *description);
void connectRooms(Room *current, Room *target, const char *direction);
void displayRoomInfo(const Room *room);
void addItemToRoom(Room *room, const Item *add);
void addCharacterToRoom(Room *room, struct Character *c);
void randomlySetCharacter(Room *room);
void cleanRoom(Room *room);



#endif

