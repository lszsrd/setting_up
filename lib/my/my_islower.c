/*
** EPITECH PROJECT, 2023
** /lib/my/my_islower.c
** File description:
** Check if the given character is a lowercase alpha
** Return 1 if so, 0 otherwise
*/

#include "my.h"

int my_islower(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}
