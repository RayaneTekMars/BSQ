/*
** EPITECH PROJECT, 2017
** bsq.h
** File description:
** bsq header
*/

#ifndef BSQ_H_
#define BSQ_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_map
{
    char *map;
    int start;
    int size;
    int nb_lines;
    int nb_columns;
} map_t;

map_t *init_map(char *);
void bsq_display(map_t *);
void bsq_draw(map_t **);
void my_putstr(char *);
void bsq(char *);
void display_error(char *, int);
int bsq_find(map_t *);
int my_strlen(char *);
int my_putchar(char);
int my_atoi(char *);

#define BUFF_SIZE	2000000000

#endif /* BSQ_H_ */
