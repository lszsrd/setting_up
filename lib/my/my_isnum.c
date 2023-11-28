/*
** EPITECH PROJECT, 2023
** /lib/my/my_isnum.c
** File description:
** Check if the given character is numeric
** Return 1 if so, 0 otherwise
*/

#include "my.h"

int my_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
