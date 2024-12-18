#include "Key.h"
#include <string.h>

void initKey(Key *key, const char *name, const char *description){
    strncpy(key -> name, name, sizeof(key -> name) - 1);
    key -> name[sizeof(key -> name) - 1] = '\0';

    strncpy(key -> description, description, sizeof(key-> description) - 1);
    key -> description[sizeof(key-> description) - 1] = '\0';
    
}