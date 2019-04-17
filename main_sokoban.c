/*
** EPITECH PROJECT, 2018
** Sokoban
** File description:
** main fonction
*/
#include <sys/ioctl.h>
#include <stdio.h>
#include "include/my.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int maxi_len_array(variable map)
{
    int len = 0;
    int len_temp = 0;
    int i = 0;

    while (map.tbl[i][0] != '\0') {
        len_temp = my_strlen(map.tbl[i]);
        if (len_temp >= len) {
            len = len_temp;
        }
        i++;
    }
    return (len);
}

variable distrib(char const *str, variable map)
{
    struct inc_map fis;
    struct inc_map sec;
    map = map_str(str, map);
    map = nbrline(map);
    map = nbrcolumn(map);
    map.len_first_line = 0;
    map = str_array(map, fis);
    map.len_first_line = 0;
    map = str_array_two(map, sec);
    map = check_char_nbr(map);
    return (map);
}

void char_distrib_detec(char tmp, position *pos, variable *map)
{
    if (tmp == 'A')
        mouv_haut_p(pos, map);
    if (tmp == 'B')
        mouv_bas_p(pos, map);
    if (tmp == 'C')
        mouv_droite_p(pos, map);
    if (tmp == 'D')
        mouv_gauche_p(pos, map);
}

int disp_middle(variable map, int ac, char **av)
{
    struct position pos;
    struct position opos;
    int size = maxi_len_array(map);
    char tmp;

    find_pos(&pos, map);
    initscr();
    while (1) {
        clear();
        char_distrib_detec(tmp, &pos, &map);
        for (int i = 0; i != map.nbr_line; i++) {
            mvprintw((LINES / 2) - (map.nbr_line / 2) + i,
            (COLS / 2) - (size / 2), map.tbl[i]);
        }
        refresh();
        vic_loose(map);
        tmp = getch();
        if (tmp == ' ')
            main(ac, av);
    }
    endwin();
}

int main(int ac, char **av)
{
    struct variable map;

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h')
        usage();
    map = distrib(av[1], map);
    test_char_valid(map);
    disp_middle(map, ac, av);
    return (0);
}
