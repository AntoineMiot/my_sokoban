/*
** EPITECH PROJECT, 2018
** Sokoban
** File description:
** victory function
*/
#include <sys/ioctl.h>
#include <stdio.h>
#include "include/my.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

void victory_two(variable *map)
{
    if (map->tbl[map->t][map->y] == 'X' && map->tbl2[map->t][map->y] == 'O')
        map->x_on_o = map->x_on_o + 1;
}

void victory(variable *map)
{
    map->t = 0;
    map->y = 0;
    map->x_on_o = 0;

    while (map->tbl[map->t][map->y] != '\0'
    && map->tbl2[map->t][map->y] != '\0') {
        while (map->tbl[map->t][map->y] != '\n'
        && map->tbl2[map->t][map->y] != '\n') {
            victory_two(map);
            map->y++;
        }
        map->y = 0;
        map->t++;
    }
    if (map->x_on_o == map->count_o && map->x_on_o == map->count_x) {
        endwin();
        exit(0);
    }
    map->x_on_o = 0;
}

void vic_loose(variable map)
{
    victory(&map);
    x_loose(&map);
}