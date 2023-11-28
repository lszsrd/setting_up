/*
** EPITECH PROJECT, 2023
** B-CPE-110-NCY-1-1-settingup-laszlo.serdet-1
** File description:
** setting_up
*/

#include "my.h"

#pragma once

typedef struct {
    char **board;
    bool is_valid;
    int columns;
    int lines;
} s_board;

typedef struct {
    bool line_is_dot;
    int x;
    int swap_x;
    int y;
    int swap_y;
    int k;
    int size;
} s_square;
/* setting_up's function */
int setting_up(int ac, char **av);
int find_biggest_square(s_board *b);
