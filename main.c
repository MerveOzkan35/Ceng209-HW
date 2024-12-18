
#include "Room.h"
#include "Player.h"
#include "Item.h"
#include "Character.h"
#include "Key.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void displayMessage(const char *filename);
char *readFileContent(const char *filename);
void movePlayer(Player *player, const char *direction);
void loadGame(Player *player, const char *filename);
void saveGame(Player *player, const char *filename);
void listSavedGames();


int main()
{
    // Display welcome message
    displayMessage("WelcomeToGame.txt");

    printf("\nStarting the game...\n");

    // Now, i will set rooms, items and characters in them
    // House Lannister
    Room lannister;
    char *description1 = readFileContent("HouseLannister.txt");

    if (description1 == NULL)
    {
        printf("Failed to load room description. Exiting program.\n");
        return 1; // Exit with an error code if file reading failed
    }

    initRoom(&lannister, "House Lannister", description1);

    Character cersei = {0};
    Character joffrey = {0};
    Character jaime = {0};

    initCharacter(&cersei, "Cersei Lannister", 100, 50, 10);
    initCharacter(&joffrey, "Joffrey Baratheon", 100, 40, 20);
    initCharacter(&jaime, "Jaime Lannister", 100, 100, 25);

    addCharacterToRoom(&lannister, &cersei);
    addCharacterToRoom(&lannister, &joffrey);
    addCharacterToRoom(&lannister, &jaime);

    randomlySetCharacter(&lannister);

    Item valyrianSword;
    initItem(&valyrianSword, "Valyrian Steel Sword", 20,
             "A rare and powerful sword forged from Valyrian steel");
    addItemToRoom(&lannister, &valyrianSword);

    Item healthPotion;
    initItem(&healthPotion, "Health Potion", 0,
             "A magical liquid that restores health and vitality when consumed");
    addItemToRoom(&lannister, &healthPotion);

    // House Baratheon
    Room baratheon;
    char *description2 = readFileContent("HouseBaratheon.txt");

    if (description2 == NULL)
    {
        printf("Failed to load room description. Exiting program.\n");
        return 1; // Exit with an error code if file reading failed
    }

    initRoom(&baratheon, "House Baratheon", description2);

    Character robert = {0};
    Character stannis = {0};
    Character renly = {0};

    initCharacter(&robert, "Robert Baratheon", 100, 100, 20);
    initCharacter(&stannis, "Stannis Baratheon", 100, 80, 15);
    initCharacter(&renly, "Renly Baratheon", 100, 60, 10);

    addCharacterToRoom(&baratheon, &robert);
    addCharacterToRoom(&baratheon, &stannis);
    addCharacterToRoom(&baratheon, &renly);

    randomlySetCharacter(&baratheon);

    Item dragger; // Stands for DRAgonglass daGGER
    initItem(&dragger, "Dragonglass Dagger", 15,
             "A dagger made from dragonglass");
    addItemToRoom(&baratheon, &dragger);

    Item wildfire;
    initItem(&wildfire, "Wildfire", 20,
             "A highly volatile and destructive substance, capable of causing massive explosions.");
    addItemToRoom(&baratheon, &wildfire);

    // House Tyrell
    Room tyrell;
    char *description3 = readFileContent("HouseTyrell.txt");

    if (description3 == NULL)
    {
        printf("Failed to load room description. Exiting program.\n");
        return 1; // Exit with an error code if file reading failed
    }

    initRoom(&tyrell, "House Tyrell", description3);

    Character olenna = {0};
    Character margaery = {0};
    Character loras = {0};

    initCharacter(&olenna, "Olenna Tyrell", 50, 40, 5);
    initCharacter(&margaery, "Margaery Tyrell", 100, 40, 5);
    initCharacter(&loras, "Loras Tyrell", 100, 60, 10);

    addCharacterToRoom(&tyrell, &olenna);
    addCharacterToRoom(&tyrell, &margaery);
    addCharacterToRoom(&tyrell, &loras);

    randomlySetCharacter(&tyrell);

    Item poisonRing; // A ring that includes poison
    initItem(&poisonRing, "Poison Ring", 100,
             "A ring that includes poison in it, can kill when used.");
    addItemToRoom(&tyrell, &poisonRing);

    // Manipulative Room
    Room manipulative;
    char *description4 = readFileContent("ManipulativeRoom.txt");

    if (description4 == NULL)
    {
        printf("Failed to load room description. Exiting program.\n");
        return 1; // Exit with an error code if file reading failed
    }

    initRoom(&manipulative, "Manipulative Room", description4);

    Character baelish = {0};
    Character melisandre = {0};
    Character jaqen = {0};

    initCharacter(&baelish, "Petyr Baelish", 100, 60, 15);
    initCharacter(&melisandre, "Lady Melisandre", 100, 70, 20);
    initCharacter(&jaqen, "Jaqen Heghar", 100, 100, 25);

    addCharacterToRoom(&manipulative, &baelish);
    addCharacterToRoom(&manipulative, &melisandre);
    addCharacterToRoom(&manipulative, &jaqen);

    randomlySetCharacter(&manipulative);

    Item darkSister;
    initItem(&darkSister, "Dark Sister Sword", 20,
             "A legendary Valyrian steel sword, known for its grace and deadly edge");
    addItemToRoom(&manipulative, &darkSister);

    Item flower;
    initItem(&flower, "Firebloom Flower Potion", 0,
             "A rare flower that grows in the shadow of volcanoes, used in this health potion.");
    addItemToRoom(&manipulative, &flower);

    // House Of Undying
    Room undying;
    char *description5 = readFileContent("HouseOfUndying.txt");

    if (description5 == NULL)
    {
        printf("Failed to load room description. Exiting program.\n");
        return 1; // Exit with an error code if file reading failed
    }

    initRoom(&undying, "House Of Undying", description5);

    Character pyatPre = {0};

    initCharacter(&pyatPre, "Pyat Pre", 100, 100, 20);

    addCharacterToRoom(&undying, &pyatPre);

    randomlySetCharacter(&undying);

    Item dracarys;
    initItem(&dracarys, "Dracarys Command", 100,
             "A command in High Valyrian to dragons for breathing dragonfire. Only this can stop Pyat Pre.");
    addItemToRoom(&undying, &dracarys);

    // Hole(corridors will also be a room)
    Room hole;
    char *description6 = readFileContent("Hole.txt");

    if (description6 == NULL)
    {
        printf("Failed to load room description. Exiting program.\n");
        return 1; // Exit with an error code if file reading failed
    }

    initRoom(&hole, "Hole", description6);

    Room corridorA;
    initRoom(&corridorA, "Corridor A", "Nothing in here.");
    Room corridorB;
    initRoom(&corridorB, "Corridor B", "Nothing in here.");
    Room corridorC;
    initRoom(&corridorC, "Corridor C", "Nothing in here.");
    Room corridorD;
    initRoom(&corridorD, "Corridor D", "Nothing in here.");

    // Now, I will set room connections
    // for better understanding you can check Map.txt
    connectRooms(&tyrell, &corridorA, "east");
    connectRooms(&tyrell, &corridorB, "south");

    connectRooms(&baratheon, &corridorA, "west");
    connectRooms(&baratheon, &corridorC, "south");

    connectRooms(&lannister, &corridorB, "north");
    connectRooms(&lannister, &corridorD, "east");

    connectRooms(&manipulative, &corridorC, "north");
    connectRooms(&manipulative, &corridorD, "west");

    connectRooms(&corridorD, &undying, "south");

    connectRooms(&hole, &corridorA, "north");
    connectRooms(&hole, &corridorB, "west");
    connectRooms(&hole, &corridorC, "east");
    connectRooms(&hole, &corridorD, "south");

    // Create keys and set room's attribute key
    Key lannisterKey;
    initKey(&lannisterKey, "Lannister Key", "A golden key engraved with a roaring lion");
    lannister.key = lannisterKey;

    Key baratheonKey;
    initKey(&baratheonKey, "Baratheon Key", "A sturdy iron key adorned with a crowned stag");
    baratheon.key = baratheonKey;

    Key tyrellKey;
    initKey(&tyrellKey, "Tyrell Key", "A delicate golden key decorated with a blooming rose");
    tyrell.key = tyrellKey;

    Key manipulativeKey;
    initKey(&manipulativeKey, "Manipulative Key", "A sleek, silver key with an intricate, twisting design, symbolizing secrets and deception");
    manipulative.key = manipulativeKey;

    // Game starts via commands
    Player player;
    initPlayer(&player);

    player.currentRoom = &hole;

    displayRoomInfo(&hole);

    printf("Type any command (-help to see available commands):\n ");
    char command[100];

    do
    {
        printf("\n> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        if (strncmp(command, "move ", 5) == 0)
        {
            movePlayer(&player, command + 5);
        }
        else if (strcmp(command, "look") == 0)
        {
            displayRoomInfo(player.currentRoom);
        }
        else if (strcmp(command, "inventory") == 0)
        {
            showInventory(&player);

            // For incentory management user can drop items via this method
            manageInventory(&player);
        }
        else if (strncmp(command, "pickup ", 7) == 0)
        {
            char itemName[50];
            sscanf(command + 7, "%49[^\n]", itemName); // Extract item name from command

            int itemFound = 0;

            // Search for the item in the current room
            for (int i = 0; i < player.currentRoom->itemCount; i++)
            {
                if (strcmp(player.currentRoom->itemList[i].name, itemName) == 0)
                {
                    // Add item to player's inventory
                    addItem(&player, &player.currentRoom->itemList[i]);

                    // If item is added succesfully
                    //  Remove the item from the room by shifting remaining items
                    if (searchForItem(&player, itemName))
                    {
                        for (int j = i; j < player.currentRoom->itemCount - 1; j++)
                        {
                            player.currentRoom->itemList[j] = player.currentRoom->itemList[j + 1];
                        }
                        player.currentRoom->itemCount--; // Decrease room's item count

                        printf("You picked up: %s\n", itemName);
                    }

                    itemFound = 1;
                    break;
                }
            }

            if (!itemFound)
            {
                printf("Item '%s' not found in this room.\n", itemName);
            }
        }
        else if (strcmp(command, "attack") == 0)
        {
            attack(&player, player.currentItem, player.currentRoom->activeCharacter);

            if (player.currentRoom->activeCharacter->health != 0)
            {
                printf("%s attacks you back.", player.currentRoom->activeCharacter->name);
                attackToPlayer(&player, player.currentRoom->activeCharacter);
            }
            // Collect key if character is defeated
            if (player.currentRoom->activeCharacter->health == 0 && strcmp(player.currentRoom->activeCharacter->name, "Pyat Pre") != 0)
            {
                printf("Congrats! You defeated %s\n", player.currentRoom->activeCharacter->name);
                printf("That means you earn a key.\n");
                collectKey(&player, &player.currentRoom->key);
                printf("%s:%s", player.currentRoom->key.name, player.currentRoom->key.description);
            }
            else if (player.health == 0)
            {
                printf("Your health is 0, you are defeated. Game ends..");
                return 0;
            }
        }
        else if (strcmp(command, "list") == 0)
        {
            listSavedGames();
        }
        else if (strncmp(command, "save ", 5) == 0)
        {
            char filename[50];
            printf("You want to save your game.\n");
            sscanf(command + 5, "%49s", filename);
            saveGame(&player, filename);
        }
        else if (strncmp(command, "load ", 5) == 0)
        {
            char filename[50];
            printf("You want to load a game.\n");
            sscanf(command + 5, "%49s", filename);
            loadGame(&player, filename);
        }
        else if (strcmp(command, "exit") == 0)
        {
            printf("Exiting game...\n");
            // break;  // Exit the game loop
            return 0;
        }
        else if (strcmp(command, "help") == 0)
        {
            displayMessage("HelpCommand.txt");
        }
        else if (strncmp(command, "use ", 4) == 0)
        {
            char itemName[50];
            sscanf(command + 4, "%49[^\n]", itemName); // Extract the item name from the command

            // Search for the item in the player's inventory
            Item *foundItem = NULL; // Pointer to store the found item
            for (int i = 0; i < player.inventorySize; i++)
            {
                if (strcmp(player.inventory[i]->name, itemName) == 0)
                {
                    foundItem = player.inventory[i];
                    break;
                }
            }

            if (foundItem != NULL)
            {

                // Call the useItem function with the found item
                useItem(&player, foundItem);
            }
            else
            {
                printf("Item '%s' not found in your inventory.\n", itemName);
            }
        }

        else if (strcmp(command, "map") == 0)
        {
            displayMessage("Map.txt");
        }
        else
        {
            printf("Invalid command. Type '-help' to see available commands.\n");
        }
    } while (pyatPre.health != 0);

    /*
    If Pyat Pre is defeated, that means pyatPre.health = 0 and dragons are saved.
    Game ends and as a reward there is a speech by Daenerys Targaryen
    for thanking to player for saving her dragons.
    And at the end of speech, there will be dragon shape made of ASCII,
    I wanted to add this, cuz it would look good as visual and also cute.
    */

    if (pyatPre.health == 0)
    {
        printf("Congrats! You defeated Pyat Pre and saved dragons from him.\n");
        printf("Now, Daenerys Targaryen will make a thank speech to you.\n ");
        printf("And you will get an award from her.\n");
        displayMessage("DaenerysSpeechToHero.txt");
        printf("\n\n\n");
        displayMessage("DragonShapeASCII.txt");
    }
    else
    {
        printf("You failed, couldn't save the dragons. Maybe next time, BYE.");
    }

    // Clean rooms
    cleanRoom(&lannister);
    cleanRoom(&baratheon);
    cleanRoom(&tyrell);
    cleanRoom(&manipulative);
    cleanRoom(&undying);

    return 0;
}

//To print a txt file to screen
void displayMessage(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: Could not open the file %s.\n", filename);
        return;
    }

    char line[256];
    printf("\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}

//To store a txt file to a room description
char *readFileContent(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    // Determine the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Allocate memory for the file content (+1 for the null terminator)
    char *content = (char *)malloc(fileSize + 1);
    if (content == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    // Read the file content into memory
    fread(content, 1, fileSize, file);
    content[fileSize] = '\0'; // Null-terminate the string

    fclose(file);
    return content;
}

void movePlayer(Player *player, const char *direction)
{
    if (strcmp(player->currentRoom->name, "Corridor D") == 0 && strcmp(direction, "south") == 0 && player->keyCount != 4)
    {
        printf("You can't move to House of Undying without collecting all 4 keys.\n");
        printf("Now, you are in %s\n", player->currentRoom->name);
        return;
    }
    else if (strcmp(direction, "north") == 0 && player->currentRoom->north != NULL)
    {
        player->currentRoom = player->currentRoom->north;
        printf("You moved north.\n");
        printf("Now, you are in %s\n", player->currentRoom->name);
    }
    else if (strcmp(direction, "south") == 0 && player->currentRoom->south != NULL)
    {
        player->currentRoom = player->currentRoom->south;
        printf("You moved south.\n");
        printf("Now, you are in %s\n", player->currentRoom->name);
    }
    else if (strcmp(direction, "east") == 0 && player->currentRoom->east != NULL)
    {
        player->currentRoom = player->currentRoom->east;
        printf("You moved east.\n");
        printf("Now, you are in %s\n", player->currentRoom->name);
    }
    else if (strcmp(direction, "west") == 0 && player->currentRoom->west != NULL)
    {
        player->currentRoom = player->currentRoom->west;
        printf("You moved west.\n");
        printf("Now, you are in %s\n", player->currentRoom->name);
    }
    else
    {
        printf("You can't move in that direction.\n");
    }
}

void loadGame(Player *player, const char *filename)
{
    char filepath[100] = "saves/";
    strcat(filepath, filename);

    FILE *file = fopen(filepath, "rb");
    if (file == NULL)
    {
        printf("Error: Could not load the game from %s.\n", filepath);
        return;
    }

    // Load player health and inventory count
    fread(&player->health, sizeof(int), 1, file);
    fread(&player->inventorySize, sizeof(int), 1, file);

    // Load each item into the player's inventory
    for (int i = 0; i < player->inventorySize; i++)
    {
        fread(&player->inventory[i], sizeof(Item), 1, file);
    }

    printf("Game successfully loaded from '%s'.\n", filepath);
    fclose(file);
}

void saveGame(Player *player, const char *filename)
{
    char filepath[100] = "saves/";
    strcat(filepath, filename);

    FILE *file = fopen(filepath, "wb");
    if (file == NULL)
    {
        printf("Error: Could not save the game to %s.\n", filepath);
        return;
    }

    // Save player health and inventory count
    fwrite(&player->health, sizeof(int), 1, file);
    fwrite(&player->inventorySize, sizeof(int), 1, file);

    // Save each item in the player's inventory
    for (int i = 0; i < player->inventorySize; i++)
    {
        fwrite(&player->inventory[i], sizeof(Item), 1, file);
    }

    printf("Game successfully saved to '%s'.\n", filepath);
    fclose(file);
}

// A cross-Platform way for listing saved games
// In windows and linux/macos systems we had to include different libs to our code
// So i chose this way to make it cross platform
#ifdef _WIN32
#include <windows.h>
void listSavedGames()
{
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile("saves\\*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        printf("Could not open 'saves' directory. Make sure it exists.\n");
        return;
    }

    printf("Saved Games:\n");
    do
    {
        if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0)
            printf("- %s\n", findFileData.cFileName);
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}
#else
#include <dirent.h>
void listSavedGames()
{
    DIR *dir = opendir("saves");
    struct dirent *entry;

    if (dir == NULL)
    {
        printf("Could not open 'saves' directory. Make sure it exists.\n");
        return;
    }

    printf("Saved Games:\n");
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] == '.')
            continue;
        printf("- %s\n", entry->d_name);
    }
    closedir(dir);
}
#endif
