/*
** EPITECH PROJECT, 2023
** B-CPE-110-NCY-1-1-settingup-laszlo.serdet-1
** File description:
** algo
*/

#include "my.h"
#include "setting_up.h"

/* Place the square at the correct coordinates on the board */
static void set_new_square_on_board(s_board *b, s_square *s)
{
    for (int k = 0; k < s->size; k++)
        for (int l = 0; l < s->size; l++)
            b->board[s->x + k][s->y + l]
                = (b->board[s->x + k][s->y + l] != '.')
                ? b->board[s->x + k][s->y + l] : 'x';
}

/* When a valid square is found and is bigger than the old one, register it */
static int register_new_square(s_square *s, int size)
{
    if (size > s->size) {
        s->size = size;
        s->x = s->swap_y;
        s->y = s->swap_x;
    }
    return 0;
}

/* Third part of the function finding the biggest square of the board */
static int find_biggest_square_part3(s_board *b, s_square *s, int i, int j)
{
    for (int l = s->swap_y; l <= i && b->board[i] != NULL; l++) {
        s->line_is_dot = b->board[l][j + s->k] == '.' ? s->line_is_dot : false;
    }
    return 0;
}

/* Second part of the function finding the biggest square of the board */
static int find_biggest_square_part2(s_board *b, s_square *s, int i, int j)
{
    bool is_dot = true;
    int size = 0;

    s->swap_y = i;
    s->swap_x = j;
    s->line_is_dot = true;
    for (size = 0; is_dot; size++) {
        for (s->k = 0; i <= b->lines && s->line_is_dot && s->k <= size;
            s->k++) {
            find_biggest_square_part3(b, s, i, j);
            s->line_is_dot = (b->board[i][j + s->k] == '.' &&
                b->board[i] != NULL) ? s->line_is_dot : false;
        }
        if (s->line_is_dot == false || i > b->lines) {
            is_dot = false;
            size += (true) ? register_new_square(s, size) : 0;
        }
        i++;
    }
    return size;
}

/* Find the biggest square of the board */
/* NOTE: If a map of 10.000 x 10.000 has too less obstacles, the program
 * won't work because of the amount of operations of backtracking to do*/
int find_biggest_square(s_board *b)
{
    s_square s;
    int i = 0;
    int j = 0;

    s.x = 0;
    s.y = 0;
    s.size = 0;
    for (i = 1; b->board[i] != NULL; i++) {
        for (j = 0; b->board[i][j] != 0; j++) {
            b->is_valid = (b->board[i][j] == '.' || b->board[i][j] == 'o' ||
                b->board[i][j] == 0) ? b->is_valid : false;
                find_biggest_square_part2(b, &s, i, j);
        }
        b->is_valid = (j == b->columns) ? b->is_valid : false;
    }
    b->is_valid = (i == b->lines + 1) ? b->is_valid : false;
    set_new_square_on_board(b, &s);
    return 0;
}
