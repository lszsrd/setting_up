/*
** EPITECH PROJECT, 2023
** src/my_stderr.c
** File description:
** Writes a given string to the stderr
*/

#include "my.h"

int my_puterr(char *str)
{
    return write(2, str, my_strlen(str));
}

int my_putcharerr(char c)
{
    return write(2, &c, 1);
}

int s_cchar(va_list *args)
{
    return my_putcharerr((char) va_arg(*args, int));
}
