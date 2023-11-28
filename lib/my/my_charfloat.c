/*
** EPITECH PROJECT, 2023
** my_charfloat
** File description:
** write float
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

static int nb_modulo(int nb)
{
    int nb_mall = 1;

    while (nb / nb_mall != 0) {
        nb_mall = nb_mall * 10;
    }
    return nb_mall;
}

static int nb_bf_point(char *t, int j, int nb_cast, int modulo)
{
    for (; modulo > 0.1 ; j++) {
        t[j] = (nb_cast / modulo) + '0';
        nb_cast = nb_cast - (nb_cast / modulo) * modulo;
        modulo = modulo / 10;
        }
    return j;
}

char *my_float(double nb)
{
    int j = 0;
    char *t = malloc(sizeof(char) * 8);
    int nb_cast = (int)nb;
    int modulo = nb_modulo(nb_cast) / 10;
    int nb_j = 0;

    if (t == NULL)
        return NULL;
    j += nb_bf_point(t, j, nb_cast, modulo);
    t[j] = '.';
    j++;
    nb_cast = (int)nb;
    nb_j = j;
    for (; j < 6 + nb_j; j++) {
        nb = (nb - nb_cast) * 10;
        nb_cast = (int)nb;
        t[j] = nb_cast + '0';
    }
    return t;
}
