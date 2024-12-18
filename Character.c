#include "Character.h"
#include <stdio.h>
#include <string.h>

void initCharacter(Character *c, char *name, int health, int strength, int damage){

    strncpy(c -> name, name, sizeof(c -> name) - 1);
    c -> name[sizeof(c -> name) - 1] = '\0';


    c -> health = health;
    c -> strength = strength;
    c -> damage = damage;
}

void attackToPlayer(struct Player *player, Character *c){
   
    printf("Character %s attacks to player.\n", c -> name);
    printf("Damage amount is %d.\n", c -> damage);
    player -> health -= c -> damage;
    player -> strength -= c -> damage / 2.0;
    //Since strength more for attacking, it decreases less

    // Ensure values don't drop below zero
    if (player->health < 0) player->health = 0;
    if (player->strength < 0) player->strength = 0;

    displayPlayerStats(player);
    displayCharacterStats(c);
}

void displayCharacterStats(Character *c){
   
    printf("Character stats are :\n Health -> %d Strength -> %d\n",
    c -> health, c -> strength);
}