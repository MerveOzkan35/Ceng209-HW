#ifndef KEY_H
#define KEY_H

typedef struct Key
{
    char name[30];
    char description[70];
}Key;

void initKey(Key *key, const char *name, const char *description);
#endif