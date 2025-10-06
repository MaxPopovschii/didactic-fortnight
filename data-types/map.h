#ifndef MAP_H
#define MAP_H

#include <stddef.h>

// Simple map (hash table) for int keys and values
#define MAP_SIZE 101

typedef struct {
    int key;
    int value;
    int used;
} MapEntry;

typedef struct {
    MapEntry entries[MAP_SIZE];
} Map;

void map_init(Map *map);
void map_put(Map *map, int key, int value);
int  map_get(Map *map, int key, int *found);
void map_free(Map *map);

#endif // MAP_H
