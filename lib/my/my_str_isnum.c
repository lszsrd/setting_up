/*
** EPITECH PROJECT, 2023
** /lib/my/my_str_isnum.c
** File description:
** Check if the given string is numeric
** Returns 1 if so, 0 otherwise
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    for (int a = 0 ; str[a] != '\0'; a++)
        if (my_isnum(str[a]) > 0)
            return 0;
    return 1;
}
