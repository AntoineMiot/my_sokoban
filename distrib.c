/*
** EPITECH PROJECT, 2018
** Sokoban
** File description:
** distrib
*/
#include <sys/ioctl.h>
#include <stdio.h>
#include "include/my.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

void verif_p(position *pos, variable map, int x, int y)
{
    if (map.tbl[y][x] == 'P') {
        pos->x = x;
        pos->y = y;
    }
    return;
}

void find_pos(position *pos, variable map)
{
    int x = 0;
    int y = 0;

    while (map.tbl[y][x] != '\0') {
        while (map.tbl[y][x] != '\n') {
            verif_p(pos, map, x, y);
            x = x + 1;
        }
        x = 0;
        y = y + 1;
    }
    return;
}