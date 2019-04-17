/*
** EPITECH PROJECT, 2018
** Sokoban
** File description:
** check si il y a le bon nbr de O et de X
*/
#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

variable check_char_nbr(variable map)
{
    map.count_o = 0;
    map.count_x = 0;

    for (int i = 0; i != map.nbr_line * map.nbr_column; i++) {
        if (map.str[i] == 'X')
            map.count_x = map.count_x + 1;
        if (map.str[i] == 'O')
            map.count_o = map.count_o + 1;
    }
    if (map.count_o != map.count_x)
        exit(84);
    return (map);
}