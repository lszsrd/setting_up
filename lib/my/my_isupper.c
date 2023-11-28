/*
** EPITECH PROJECT, 2023
** /lib/my/my_isupper.c
** File description:
** Check if the given character is a uppercase alpha
** Return 1 if so, 0 otherwise
*/

#include "my.h"

int my_isupper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}
