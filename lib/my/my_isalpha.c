/*
** EPITECH PROJECT, 2023
** /lib/my/my_isalpha.c
** File description:
** Check if the given character is alpha
** Return 1 if so, 0 otherwise
*/

#include "my.h"

int my_isalpha(char c)
{
    if (my_islower(c) > 0 || my_isupper(c) > 0)
        return 1;
    return 0;
}
