/*
** EPITECH PROJECT, 2023
** my_putbase
** File description:
** display nb of the base given
*/

#include "my.h"
#include <stdbool.h>

int my_put_prefix(char base)
{
    int i = 1;

    my_putchar('0');
    if (base != 'o') {
        my_putchar(base);
        i++;
    }
    return i;
}

int my_putbase_o(va_list *args)
{
    int len = 0;

    len = my_putstr(my_convertbase(va_arg(*args, unsigned int), 8, true));
    return len;
}

int my_putbase_x(va_list *args)
{
    int len = 0;

    len = my_putstr(my_convertbase(va_arg(*args, unsigned int), 16, true));
    return len;
}

int my_putbase_xupper(va_list *args)
{
    int len = 0;

    len = my_putstr(my_convertbase(va_arg(*args, unsigned int), 16, false));
    return len;
}

int my_putbase_u(va_list *args)
{
    int len = 0;

    len = my_putnbr(va_arg(*args, unsigned int));
    return len;
}
