#include "Room.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initRoom(Room *room, char *name, char *description){

    room->name = name;


    room->description = description;
    room->north = NULL;
    room->south = NULL;
    room->east = NULL;
    room->west = NULL;

     // Initialize key and items
    room->key.name[0] = '\0';  // Empty key initially
    room->key.description[0] = '\0';

    room->itemCount = 0;       // No items initially
    room->charCount = 0;

    room->activeCharacter = NULL;

}

void connectRooms(Room *current, Room *target, const char *direction) {
    if (current == NULL || target == NULL || direction == NULL) return;

    if (strcmp(direction, "north") == 0) {
        current->north = target;
        target->south = current;
    } else if (strcmp(direction, "south") == 0) {
        current->south = target;
        target->north = current;
    } else if (strcmp(direction, "east") == 0) {
        current->east = target;
        target->west = current;
    } else if (strcmp(direction, "west") == 0) {
        current->west = target;
        target->east = current;
    } else {
        return;
    }
}

// Display room information
void displayRoomInfo(const Room *room) {
    if (room == NULL) return;

    printf("\nRoom Name: %s\n", room->name);
    printf("Description: %s\n", room->description);

    // Display active character
    if(room->activeCharacter != NULL){
        printf("Active Character: %s\n", room->activeCharacter->name);
    printf("Health: %d | Strength: %d | Damage: %d\n", 
    room->activeCharacter->health, room->activeCharacter->strength, room->activeCharacter->damage);
    }else{
        printf("No active character.\n");
    }
    

    // Display items
    if (room->itemCount > 0) {
        printf("Items in the Room:\n");
        for (int i = 0; i < room->itemCount; i++) {
            printf("- %s\n", room->itemList[i].name);
            printf("%s\n", room->itemList[i].description);
            printf("Damage: %d\n", room->itemList[i].damage);
        }
    } else {
        printf("No items in the room.\n");
    }
}

// Add an item to the room
void addItemToRoom(Room *room, const Item *item) {
    if (room == NULL || item == NULL) return;

    if (room->itemCount < 5) {
        room->itemList[room->itemCount++] = *item;
        
    } 
}

// Add a character to the room's character list
void addCharacterToRoom(Room *room, struct Character *character) {

    if(room->charCount < 3){
        room->charList[room->charCount] = character;
        room->charCount += 1;
    }else{
        printf("Room is full.\n");
    }
    
}

// Randomly choose an active character
void randomlySetCharacter(Room *room) {
    
        if(room->charCount > 0){
            int randomIndex = rand() % room->charCount;  // Random index
        room->activeCharacter = room->charList[randomIndex];
        }else{
            printf("No character in the room to set as active.");
        }
        
}

// free room
void cleanRoom(Room *room) {
    if (room == NULL) return;

    if (room->name) {
        free(room->name);
        room ->name = NULL;
    }

    if (room->description) {
        free(room->description);
        room ->description = NULL;
    }

    
}