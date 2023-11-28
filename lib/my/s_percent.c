/*
** EPITECH PROJECT, 2023
** src/s_percent.h
** File description:
** Handles % prints
*/

#include "my.h"

int s_percent(va_list *args)
{
    (void) args;
    return my_putchar('%');
}

int s_char(va_list *args)
{
    return my_putchar((char) va_arg(*args, int));
}

int s_vstring(va_list *args)
{
    char *str = va_arg(*args, char *);

    if (str == NULL)
        return my_puterr("(null)");
    else
        return my_puterr(str);
}

int s_int(va_list *args)
{
    return my_putnbr(va_arg(*args, int));
}

int s_string(va_list *args)
{
    char *str = va_arg(*args, char *);

    if (str == NULL)
        return my_putstr("(null)");
    else
        return my_putstr(str);
}
