/*
** EPITECH PROJECT, 2023
** my_pointer_hex
** File description:
** void * printed in hexadecimal
*/

#include <stdbool.h>
#include "my.h"

char *convert_pointer(void *p)
{
    return (my_convertbase((unsigned long long)p, 16, true));
}

int my_putpointer(va_list *args)
{
    my_put_prefix('x');
    return (my_putstr(convert_pointer(va_arg(*args, void *)) + 2));
}
