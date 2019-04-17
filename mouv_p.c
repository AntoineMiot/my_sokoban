/*
** EPITECH PROJECT, 2018
** Sokoban
** File description:
** mouv
*/
#include <sys/ioctl.h>
#include <stdio.h>
#include "include/my.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

void mouv_haut_p(position *pos, variable *map)
{
    if (map->tbl[pos->y - 1][pos->x] != '#'
    && map->tbl[pos->y - 1][pos->x] != 'X') {
        map->tbl[pos->y][pos->x] = ' ';
        pos->y = pos->y - 1;
        map->tbl[pos->y][pos->x] = 'P';
        if (map->tbl[pos->y + 1][pos->x] == ' '
            && map->tbl2[pos->y + 1][pos->x] == 'O')
            map->tbl[pos->y + 1][pos->x] = 'O';
    } else if (map->tbl[pos->y - 1][pos->x] == 'X'
    && map->tbl[pos->y - 2][pos->x] != '#'
    && map->tbl[pos->y - 2][pos->x] != 'X') {
        map->tbl[pos->y][pos->x] = ' ';
        map->tbl[pos->y - 1][pos->x] = 'P';
        map->tbl[pos->y - 2][pos->x] = 'X';
        pos->y = pos->y - 1;
        if (map->tbl[pos->y + 1][pos->x] == ' '
        && map->tbl2[pos->y + 1][pos->x] == 'O') {
            map->tbl[pos->y + 1][pos->x] = 'O';
        }
    }
}

void mouv_bas_p(position *pos, variable *map)
{
    if (map->tbl[pos->y + 1][pos->x] != '#'
    && map->tbl[pos->y + 1][pos->x] != 'X') {
        map->tbl[pos->y][pos->x] = ' ';
        pos->y = pos->y + 1;
        map->tbl[pos->y][pos->x] = 'P';
        if (map->tbl[pos->y - 1][pos->x] == ' '
            && map->tbl2[pos->y - 1][pos->x] == 'O')
            map->tbl[pos->y - 1][pos->x] = 'O';
    } else if (map->tbl[pos->y + 1][pos->x] == 'X'
    && map->tbl[pos->y + 2][pos->x] != '#'
    && map->tbl[pos->y + 2][pos->x] != 'X') {
        map->tbl[pos->y][pos->x] = ' ';
        map->tbl[pos->y + 1][pos->x] = 'P';
        map->tbl[pos->y + 2][pos->x] = 'X';
        pos->y = pos->y + 1;
        if (map->tbl[pos->y - 1][pos->x] == ' '
        && map->tbl2[pos->y - 1][pos->x] == 'O') {
            map->tbl[pos->y - 1][pos->x] = 'O';
        }
    }
}

void mouv_gauche_p(position *pos, variable *map)
{
    if (map->tbl[pos->y][pos->x - 1] != '#'
    && map->tbl[pos->y][pos->x - 1] != 'X') {
        map->tbl[pos->y][pos->x] = ' ';
        pos->x = pos->x - 1;
        map->tbl[pos->y][pos->x] = 'P';
        if (map->tbl[pos->y][pos->x + 1] == ' '
            && map->tbl2[pos->y][pos->x + 1] == 'O')
            map->tbl[pos->y][pos->x + 1] = 'O';
    } else if (map->tbl[pos->y][pos->x - 1] == 'X'
    && map->tbl[pos->y][pos->x - 2] != '#'
    && map->tbl[pos->y][pos->x - 2] != 'X') {
        map->tbl[pos->y][pos->x] = ' ';
        map->tbl[pos->y][pos->x - 1] = 'P';
        map->tbl[pos->y][pos->x - 2] = 'X';
        pos->x = pos->x - 1;
        if (map->tbl[pos->y][pos->x + 1] == ' '
        && map->tbl2[pos->y][pos->x + 1] == 'O') {
            map->tbl[pos->y][pos->x + 1] = 'O';
        }
    }
}

void mouv_droite_p(position *pos, variable *map)
{
    if (map->tbl[pos->y][pos->x + 1] != '#'
    && map->tbl[pos->y][pos->x + 1] != 'X') {
        map->tbl[pos->y][pos->x] = ' ';
        pos->x = pos->x + 1;
        map->tbl[pos->y][pos->x] = 'P';
        if (map->tbl[pos->y][pos->x - 1] == ' '
            && map->tbl2[pos->y][pos->x - 1] == 'O')
            map->tbl[pos->y][pos->x - 1] = 'O';
    } else if (map->tbl[pos->y][pos->x + 1] == 'X'
    && map->tbl[pos->y][pos->x + 2] != '#'
    && map->tbl[pos->y][pos->x + 2] != 'X') {
        map->tbl[pos->y][pos->x] = ' ';
        map->tbl[pos->y][pos->x + 1] = 'P';
        map->tbl[pos->y][pos->x + 2] = 'X';
        pos->x = pos->x + 1;
        if (map->tbl[pos->y][pos->x - 1] == ' '
        && map->tbl2[pos->y][pos->x - 1] == 'O') {
            map->tbl[pos->y][pos->x - 1] = 'O';
        }
    }
}