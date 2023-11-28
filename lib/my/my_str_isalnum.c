/*
** EPITECH PROJECT, 2023
** /lib/my/my_str_isalnum.c
** File description:
** Check if the given string is alphanumeric
** Return 1 if so, 0 otherwise
*/

#include "my.h"

int my_str_isalnum(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        if (my_isalnum(str[a]) > 0)
            return 0;
    return 1;
}
