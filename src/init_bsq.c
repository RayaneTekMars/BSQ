/*
** EPITECH PROJECT, 2017
** bsq_display.c
** File description:
** display function
*/

#include "../include/bsq.h"

int check_lines_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
    }
    return (1);
}

int get_lines_number(char *path)
{
    int fd = open(path, O_RDONLY);
    int i = 0;
    char nb_lines[15];

    fd == -1 ? display_error(path, 1) : 0;
    while (read(fd, &nb_lines[i], 1) > 0 && nb_lines[i] != '\n' && i < 15)
        i += 1;
    nb_lines[i] = '\0';
    close(fd);
    if (!check_lines_number(nb_lines) || i == 0 || i == 14) {
        my_putstr("Error : Invalid number");
        exit(84);
    }
    return (my_atoi(nb_lines));
}

int get_columns_number(char *path)
{
    int fd = open(path, O_RDONLY);
    int i = 0;
    char tmp;

    fd == -1 ? display_error(path, 1) : 0;
    while (read(fd, &tmp, 1) > 0 && tmp != '\n');
    while (read(fd, &tmp, 1) > 0 && tmp != '\n')
        i += 1;
    close(fd) == -1 ? display_error(path, 3) : 0;
    return (i);
}

char *load_file(char *path)
{
    int fd = open(path, O_RDONLY);
    char tmp;
    char *buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
    int offset = 0;
    int len;

    if (fd == -1)
        display_error(path, 1);
    while (read(fd, &tmp, 1) > 0 && tmp != '\n');
    while ((len = read(fd, buff, BUFF_SIZE - offset)) > 0)
        offset += len;
    buff[offset] = '\0';
    if (len < 0)
        display_error(path, 2);
    return (buff);
}

map_t *init_map(char *path)
{
    map_t *new = malloc(sizeof(*new));

    if (!new)
        exit(84);
    new->nb_columns = get_columns_number(path);
    new->nb_lines = get_lines_number(path);
    new->map = load_file(path);
    new->start = 0;
    new->size = 0;
    return (new);
}