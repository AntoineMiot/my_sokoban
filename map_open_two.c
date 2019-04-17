/*
** EPITECH PROJECT, 2018
** Sokoban
** File description:
** map_open 2
*/
#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

inc_map str_array_sec(inc_map sec)
{
    sec.c = sec.c + 1;
    sec.rank_tbl = sec.rank_tbl + 1;
    return (sec);
}

variable str_array_two(variable map, inc_map sec)
{
    sec.c = 0;
    sec.rank_tbl = 0;
    char **tbltwo = malloc(sizeof(char *) * (map.nbr_line + 1));

    tbltwo[sec.rank_tbl] = malloc(sizeof(char) * (map.nbr_column + 1));
    for (map.len_first_line; map.str[map.len_first_line] != '\0';) {
        if (map.str[map.len_first_line] == '\n') {
            tbltwo[sec.rank_tbl][sec.c] = map.str[map.len_first_line];
            sec = str_array_sec(sec);
            tbltwo[sec.rank_tbl] = malloc(sizeof(char) * (map.nbr_column + 1));
            sec.c = 0;
            map.len_first_line = map.len_first_line + 1;
        }
        tbltwo[sec.rank_tbl][sec.c] = map.str[map.len_first_line];
        sec.c = sec.c + 1;
        map.len_first_line = map.len_first_line + 1;
    }
    tbltwo[sec.rank_tbl + 1] = malloc(sizeof(char) * 1);
    tbltwo[sec.rank_tbl + 1][0] = '\0';
    map.tbl2 = tbltwo;
    return (map);
}