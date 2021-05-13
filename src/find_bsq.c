/*
** EPITECH PROJECT, 2017
** bsq_find.c
** File description:
** find function
*/

#include "../include/bsq.h"

int is_obstacle_col(map_t *map, int start, int size)
{
    for (int i = 0; i < size; i++) {
        if (map->map[start] == 'o' || map->map[start] == '\0')
            return (1);
        start += map->nb_columns + 1;
    }
    return (0);
}

int is_obstacle_line(map_t *map, int start, int size)
{
    for (int i = 0; i < size; i++) {
        if (map->map[start] == 'o'    \
        || map->map[start] == '\n'    \
        || map->map[start] == '\0')
            return (1);
        start += 1;
    }
    return (0);
}

void is_max(map_t *map, int i, int size)
{
    if (map->size < size) {
        map->size = size;
        map->start = i;
    }
}

void is_square(map_t *map, int i)
{
    int size = 1;
    int y = 0;

    while (map->map[i] != '\0') {
        if (is_obstacle_col(map, i + y, size)
        || is_obstacle_line(map, i + (y * (map->nb_columns + 1)), size)) {
            is_max(map, i, size);
            return;
        }
        y += 1;
        size += 1;
    }
}

int bsq_find(map_t *map)
{
    for (int i = 0; map->map[i] != '\0'; i++) {
        while (map->map[i] == '\n' || map->map[i] == 'o')
            i += 1;
        is_square(map, i);
    }
    return (0);
}