/*
** EPITECH PROJECT, 2023
** /lib/my/my_isalnum.c
** File description:
** Check if the given character is alphanumeric
** Return 1 if so, 0 otherwise
*/

#include "my.h"

int my_isalnum(char c)
{
    if (my_isalpha(c) > 0 || my_isnum(c) > 0)
        return 1;
    return 0;
}
