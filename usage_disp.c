/*
** EPITECH PROJECT, 2018
** Sokoban
** File description:
** usage display
*/
#include <sys/ioctl.h>
#include <stdio.h>
#include "include/my.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map,");
    my_putstr(" containing ‘#’ for walls,\n");
    my_putstr("          ‘P’ for the player, ‘X’ for boxes and");
    my_putstr(" ‘O’ for storage locations.\n");
    exit(0);
}

void test_char_valid(variable map)
{
    for (int i = 0; map.str[i] != '\0'; i++) {
        if (map.str[i] != ' ' && map.str[i] != '\n'
            && map.str[i] != '#' && map.str[i] != 'X'
            && map.str[i] != 'O' && map.str[i] != 'P')
            exit(84);
    }
}

