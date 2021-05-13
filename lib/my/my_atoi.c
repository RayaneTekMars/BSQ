/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** my_atoi
*/

#include "../../include/bsq.h"

int my_atoi(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i]) {
        nb = (10 * nb) + str[i] - '0';
        i += 1;
    }
    return (nb);
}