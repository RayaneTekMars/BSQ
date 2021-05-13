/*
** EPITECH PROJECT, 2017
** my_sokoban.c
** File description:
** my_sokoban function
*/

#include "../../include/bsq.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
