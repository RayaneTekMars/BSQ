/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main function
*/

#include "../include/bsq.h"

void display_error(char *path, int nb)
{
    switch (nb) {
    case 1:
        my_putstr("Can't open the file : '");
        my_putstr(path);
        break;
    case 2:
        my_putstr("Can't read the file : '");
        my_putstr(path);
        break;
    case 3:
        my_putstr("Can't close the file : '");
        my_putstr(path);
        break;
    case 4:
        my_putstr("Invalid number on first line");
    }
    my_putstr("'\n");
    exit(84);
}

int check_map(char *str)
{
    int i = 0;
    for (; str[i] == '.' || str[i] == 'o' || str[i] == '\n'; i++);
    if (str[i] != '\0') {
        my_putstr("Invalid map\n");
        exit(84);
    }
}

void bsq(char *path)
{
    map_t *map = init_map(path);

    check_map(map->map);
    bsq_find(map);
    bsq_draw(&map);
    my_putstr(map->map);
    free(map->map);
    free(map);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (1);
    bsq(av[1]);
    return (0);
}