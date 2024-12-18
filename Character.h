#ifndef CHARACTER_H
#define CHARACTER_H
#include "Player.h"

struct Player;

typedef struct Character
{
    char name[30];
    int health;
    int strength;
    int damage;
}Character;

void initCharacter(Character *c, char *name, int health, int strength, int damage);
void attackToPlayer(struct Player *player, Character *c);
void displayCharacterStats(Character *c);
#endif
