#ifndef PLAYER_H
#define PLAYER_H
#include "Room.h"
#include "Item.h"
#include "Character.h"
#include "Key.h"
#include <stdbool.h>

typedef struct Room Room;
typedef struct Character Character;

typedef struct Player
{
    int health;
    int strength;
    Item *currentItem;
    Room *currentRoom;
    int inventoryCapacity;//how many items can it get
    int inventorySize;//currently how many items exist
    Item *inventory[5];
    Key keylist[4];
    int keyCount;

} Player;

void initPlayer(Player *player); //Constructor, initializer
void displayPlayerStats(Player *player);
void addItem(Player *player, Item *item);
bool searchForItem(Player *player, const char *itemname);
void useItem(Player *player, Item *item);//for noncombat items like health potion
void dropItem(Player *player, const char *itemname);
void manageInventory(Player *player);
void attack(Player *player, Item *item, Character *enemy);//attack via an item
void collectKey(Player *player, Key *key);
void showKeyList(Player *player);
void showInventory(Player *player);

#endif
