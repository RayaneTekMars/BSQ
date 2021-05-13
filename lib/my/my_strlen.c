/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** my_strlen
*/

#include "../../include/bsq.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i += 1;
    return (i);
}

int my_strlen_line(char *str)
{
    int i = 0;

    while (str[i])
        str[i] == '\n' ? i += 1 : 0;
    return (i);
}