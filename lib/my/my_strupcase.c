/*
** EPITECH PROJECT, 2023
** /lib/my/my_strupcase.c
** File description:
** Takes the given string and returns an uppercased string
*/

#include "my.h"

char *my_strupcase(char *str)
{
    char *rtn = malloc(1 + sizeof(char) * my_strlen(str));

    for (int a = 0; str[a] != 0; a++) {
        if (my_islower(str[a]) > 0)
            rtn[a] = str[a] - 32;
        else
            rtn[a] = str[a];
    }
    return str;
}
