/*
** EPITECH PROJECT, 2023
** src/my_printf.c
** File description:
** my_printf's main code
*/

#include "my.h"

static void call_functions(const char *format, va_list *args, int *a,
    int *count)
{
    int arg_length = check_bad_arg(format, *a);
    int (*spec[14]) (va_list *args) =
        {s_percent, s_vstring, s_vstring, s_int, s_int, my_putfloat,
        my_putfloat, my_putbase_o, my_putbase_u, my_putbase_x,
        my_putbase_xupper, my_putpointer, my_put_sc_writing_e,
        my_put_sc_writing_eupper};

    if (format[*a + arg_length] == 'n') {
        *count += my_putnbr(*count);
    } else {
        *count += spec[my_char_finder(SPECIFIERS,
            format[*a + arg_length])] (&*args);
    }
    *a += arg_length;
}

int my_dprintf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    for (int a = 0; format[a] != 0; a++) {
        if (format[a] == '%') {
            call_functions(format, &args, &a, &count);
        } else {
            count += my_putcharerr(format[a]);
        }
    }
    return count;
}
