#include "Player.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Room.h"

void initPlayer(Player *player)
{
    player->health = 100;
    player->strength = 100;
    player->currentItem = NULL;
    player->currentRoom = NULL;
    player->inventoryCapacity = 5;
    player->inventorySize = 0; // at start, no item
    player->keyCount = 0;
    // array is already initialized in player.h file
}

void displayPlayerStats(Player *player)
{
    printf("Player stats are :\n Health -> %d Strength -> %d\n", player->health, player->strength);
}

void addItem(Player *player, Item *item)
{
    if (player->inventorySize == player->inventoryCapacity)
    {
        printf("Inventory is full, you can not add this item.");
        printf("If you want to add this item, you need drop an item via inventory management.");
        printf("Type 'inventory' for inventory management.");
    }
    else
    {
        player->inventory[player->inventorySize] = item;
        player->inventorySize += 1;
        printf("Added %s to inventory succesfully.", item->name);
    }
}

bool searchForItem(Player *player, const char *itemname)
{
    for (int i = 0; i < player->inventorySize; i++)
    {
        if (strcmp(player->inventory[i]->name, itemname) == 0)
        {
            return true;
            
        }
    }
    return false;
}

void useItem(Player *player, Item *item)
{
   
    printf("You chose to use %s item.", item->name);
   
    player->currentItem = item;
    printf("Current item is %s.\n", item->name);

    // If chosen ıtem is a health potion, health increased to 100
    if (strcmp(item->name, "Firebloom Flower Potion") == 0 ||
        strcmp(item->name, "Health Potion") == 0)
    {
        player->health = 100;
        printf("Your health is %d\n", player->health);
        item->isUsed = true;
    }
    
}

// Drop an item from the inventory
void dropItem(Player *player, const char *itemname)
{
    for (int i = 0; i < player->inventorySize; i++)
    {
        if (strcmp(player->inventory[i]->name, itemname) == 0)
        {
            // Item found, shift items to remove it
            for (int j = i; j < player->inventorySize - 1; j++)
            {
                player->inventory[j] = player->inventory[j + 1]; // Shift items left
            }
            player->inventorySize--; // Decrease inventory size
            printf("Dropped %s from inventory.\n", itemname);
            return;
        }
    }
    printf("%s not found in your inventory.\n", itemname);
}

// Manage the player's inventory (drop items, view items, etc.)
void manageInventory(Player *player)
{
    printf("Welcome to inventory.\n");
    printf("Inventory capacity: %d\n", player->inventoryCapacity);
    printf("Inventory size: %d\n", player->inventorySize);
    printf("If you want to drop an item, type 'drop <itemname>'\n");

    char command[20], itemname[50];
    scanf("%s %s", command, itemname); // Read the command and item name

    if (strcmp(command, "drop") == 0)
    {
        dropItem(player, itemname); // Drop the item
    }
    else
    {
        printf("Invalid command.\n");
    }
}

void attack(Player *player, Item *item, Character *enemy)
{
    if (player->currentItem != NULL)
    {
        printf("Player attacks to %s with %s.\n", enemy->name, item->name);
        printf("Damage amount of %s is %d.\n", item->name, item->damage);
        enemy->health -= item->damage;
        item->isUsed = true;

        if (enemy->health < 0)
        {
            enemy->health = 0;
        }

        displayPlayerStats(player);
        displayCharacterStats(enemy);
    }else if(player->currentItem == NULL){
        printf("You dont have a current item. Type -use <item> to choose any item.");
    }else{
        printf("Can't attack.");
    }
}

void collectKey(Player *player, Key *key)
{
    player->keylist[player->keyCount] = *key;
    player->keyCount++;

    printf("You collected %s\n", key->name);
}

void showKeyList(Player *player)
{
    if (player->keyCount != 0)
    {
        printf("Here is the key list:\n");
        for (int i = 0; i < player->keyCount; i++)
        {
            printf("Key name: %s\n", (player->keylist[i]).name);
            printf("Description: %s\n", (player->keylist[i]).description);
        }
    }
    else
    {
        printf("There is no key.");
    }
}

void showInventory(Player *player)
{
    if (player->inventorySize > 0)
    {
        printf("Inventory:\n");
        for (int i = 0; i < player->inventorySize; i++)
        {
            printf("- %s\n", player->inventory[i]->name);
        }
    }
    else
    {
        printf("You have no items in your inventory.\n");
    }
}
