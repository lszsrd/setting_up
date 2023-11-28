/*
** EPITECH PROJECT, 2023
** putbase
** File description:
** display a double
*/

#include "my.h"

// display the scientific writing
int my_put_sc_writing_e(va_list *args)
{
    int i = 0;
    double nb = va_arg(*args, double);

    if (nb == 0) {
        my_putchar('0');
        my_putchar('.');
        for (int i = 0; i < 6; i++) {
            my_putchar('0');
        }
    } else {
        i = my_putstr(sc_writing_not_null(nb, 'e'));
    }
    return (2 + i);
}

int my_put_sc_writing_eupper(va_list *args)
{
    int i = 0;
    double nb = va_arg(*args, double);

    if (nb == 0) {
        my_putchar('0');
        my_putchar('.');
        for (int i = 0; i < 6; i++) {
            my_putchar('0');
        }
    } else {
        i = my_putstr(sc_writing_not_null(nb, 'E'));
    }
    return (2 + i);
}

int my_putfloat(va_list *args)
{
    int i = 0;
    double nb = va_arg(*args, double);

    if (nb == 0) {
        my_putchar('0');
        my_putchar('.');
        for (int i = 0; i < 6; i++) {
            my_putchar('0');
        }
    } else {
        i = my_putstr(my_float(nb));
    }
    return (2 + i);
}
