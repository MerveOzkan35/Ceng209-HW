#include "Item.h"
#include <string.h>

void initItem(Item *item, const char *name, int damage, const char *description) {
    // Copy the strings into the name and description fields
    strncpy(item->name, name, sizeof(item->name) - 1); 
    item->name[sizeof(item->name) - 1] = '\0'; // Ensure null termination
    
    item->damage = damage;
    
    strncpy(item->description, description, sizeof(item->description) - 1); // Safe string copy
    item->description[sizeof(item->description) - 1] = '\0'; // Ensure null termination

    item->isUsed = false;
}
