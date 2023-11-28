/*
** EPITECH PROJECT, 2023
** /lib/my/my_revstr.c
** File description:
** Reverse the given string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int str_len = my_strlen(str);
    char str_rev[str_len + 1];

    for (int a = 0 ; a <= str_len ; a++)
        str_rev[a] = str[str_len - a - 1];
    for (int a = 0; a < str_len; a++)
        str[a] = str_rev[a];
    return str;
}
