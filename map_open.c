/*
** EPITECH PROJECT, 2018
** Sokoban
** File description:
** map_open
*/
#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

variable nbrline(variable map)
{
    map.nbr_line = 0;

    for (unsigned long e = 0; map.str[e] != '\0'; e++) {
        if (map.str[e] == '\n')
            map.nbr_line++;
    }
    return (map);
}

variable nbrcolumn(variable map)
{
    unsigned long i = 0;
    map.nbr_column = 0;

    for (i; map.str[i] != '\n'; i++);
    map.nbr_column = i;
    return (map);
}

inc_map str_array_fis(inc_map fis)
{
    fis.c = fis.c + 1;
    fis.rank_tbl = fis.rank_tbl + 1;
    return (fis);
}

variable str_array(variable map, inc_map fis)
{
    fis.c = 0;
    fis.rank_tbl = 0;
    char **tbl = malloc(sizeof(char *) * (map.nbr_line + 1));

    tbl[fis.rank_tbl] = malloc(sizeof(char) * (map.nbr_column + 1));
    for (map.len_first_line; map.str[map.len_first_line] != '\0';) {
        if (map.str[map.len_first_line] == '\n') {
            tbl[fis.rank_tbl][fis.c] = map.str[map.len_first_line];
            fis = str_array_fis(fis);
            tbl[fis.rank_tbl] = malloc(sizeof(char) * (map.nbr_column + 1));
            fis.c = 0;
            map.len_first_line = map.len_first_line + 1;
        }
        tbl[fis.rank_tbl][fis.c] = map.str[map.len_first_line];
        fis.c = fis.c + 1;
        map.len_first_line = map.len_first_line + 1;
    }
    tbl[fis.rank_tbl + 1] = malloc(sizeof(char) * 1);
    tbl[fis.rank_tbl + 1][0] = '\0';
    map.tbl = tbl;
    return (map);
}

variable map_str(char const *str, variable map)
{
    struct stat s;
    char *buff;
    unsigned long fd;

    stat(str, &s);
    buff = malloc(sizeof(char) * s.st_size);
    fd = open(str, O_RDONLY);
    if (fd == -1)
        exit(84);
    read(fd, buff, s.st_size);
    close(fd);
    map.str = buff;
    return (map);
}

