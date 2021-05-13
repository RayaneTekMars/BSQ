/*
** EPITECH PROJECT, 2017
** bsq_display.c
** File description:
** display function
*/

#include "../include/bsq.h"

void draw_col(map_t **map, int start, int size)
{
    for (int i = 0; i < size; i++) {
        (*map)->map[start] = 'x';
        start += (*map)->nb_columns + 1;
    }
}

void draw_line(map_t **map, int start, int size)
{
    for (int i = 0; i < size; i++) {
        (*map)->map[start] = 'x';
        start += 1;
    }
}

void bsq_draw(map_t **map)
{
    int x = (*map)->start;
    int y = (*map)->start;

    for (int i = 0; i < (*map)->size - 1; i++) {
        draw_line(map, x, i);
        draw_col(map, y, i + 1);
        y += 1;
        x += (*map)->nb_columns + 1;
    }
}