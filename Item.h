#ifndef ITEM_H
#define ITEM_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Item
{
    char name[30];
    int damage;
    char description[70];
    bool isUsed;

} Item;

void initItem(Item *item, const char *name, int damage, const char *description);
#endif