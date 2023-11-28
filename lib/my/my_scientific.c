/*
** EPITECH PROJECT, 2023
** scientific writing
** File description:
** function to write in scientific
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static void writing_e(char low_up, int i, int j, char *t)
{
    int nb = 1;

    t[j] = low_up;
    j++;
    if (i < 0) {
        t[j] = '-';
        i = -i;
    } else
        t[j] = '+';
    j++;
    if (i < 9) {
        t[j] = '0';
        t[j + 1] = i + '0';
    } else {
        if (i > 0) {
            t[j] = (i % nb) + '0';
            nb = nb * 10;
        }
    }
}

static char *my_convert_sc(double nb, char low_up, int i, int nb_cast)
{
    int j = 2;
    char *t = malloc(sizeof(char) * 10);

    if (t == NULL)
        return NULL;
    t[0] = ((int)nb + '0');
    t[1] = '.';
    for (; j < 8; j++) {
        nb = (nb - nb_cast) * 10;
        nb_cast = (int)nb;
        t[j] = nb_cast + '0';
    }
    writing_e(low_up, i, j, t);
    return t;
}

char *sc_writing_not_null(double nb, char low_up)
{
    int nb_cast = (int)nb;
    int i = 0;

    if (nb < 0) {
        nb = -nb;
        nb_cast = (int)nb;
    }
    if (nb_cast > 0) {
        for (;nb_cast > 9; i++) {
            nb = nb / 10;
            nb_cast = (int)nb;
        }
    } else {
        for (; nb_cast < 1; i++) {
            nb = nb * 10;
            nb_cast = (int)nb;
        }
        i = -i;
    }
    return my_convert_sc(nb, low_up, i, (int)nb);
}
