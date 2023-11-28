/*
** EPITECH PROJECT, 2023
** /find/my/my_strcpy.c
** File description:
** Copy a given string to a destination string
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    for (int a = 0; a <= my_strlen(src); a++)
        dest[a] = src[a];
    return dest;
}
