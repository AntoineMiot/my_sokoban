/*
** EPITECH PROJECT, 2018
** Sokoban
** File description:
** tous les X doivent être coincé pour perdre
*/
#include <sys/ioctl.h>
#include <stdio.h>
#include "include/my.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int angle_one(variable *map, int count_x_keblo)
{
    if (map->tbl[map->i][map->c] == 'X'
        && map->tbl2[map->i - 1][map->c] == '#'
        && map->tbl2[map->i][map->c - 1] == '#')
        count_x_keblo = count_x_keblo + 1;
    else if (map->tbl[map->i][map->c] == 'X'
        && map->tbl2[map->i + 1][map->c] == '#'
        && map->tbl2[map->i][map->c - 1] == '#')
        count_x_keblo = count_x_keblo + 1;
    if (map->tbl[map->i][map->c] == 'X'
        && map->tbl2[map->i - 1][map->c] == '#'
        && map->tbl2[map->i][map->c + 1] == '#')
        count_x_keblo = count_x_keblo + 1;
    else if (map->tbl[map->i][map->c] == 'X'
        && map->tbl2[map->i + 1][map->c] == '#'
        && map->tbl2[map->i][map->c + 1] == '#')
        count_x_keblo = count_x_keblo + 1;
    return (count_x_keblo);
}

void x_loose(variable *map)
{
    int count_x_keblo = 0;
    map->i = 0;
    map->c = 0;

    while (map->tbl[map->i][map->c] != '\0'
    && map->tbl2[map->i][map->c] != '\0') {
        while (map->tbl[map->i][map->c] != '\n'
        && map->tbl2[map->i][map->c] != '\n') {
            count_x_keblo = angle_one(map, count_x_keblo);
            map->c++;
        }
        map->c = 0;
        map->i++;
    }
    if (count_x_keblo == map->count_x) {
        endwin();
        exit(1);
    }
    count_x_keblo = 0;
}