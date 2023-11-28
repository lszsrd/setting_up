/*
** EPITECH PROJECT, 2023
** display fun
** File description:
**  all the displaying functions
*/

#include "my.h"

// display a char
int my_putchar(char c)
{
    return write(1, &c, 1);
}

//display a * char
int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}

// display a int
static int print_nb(int nb, int i)
{
    if (nb > 9) {
        print_nb(nb / 10, i);
        i++;
    }
    my_putchar(48 + (nb % 10));
    i++;
    return i;
}

int my_putnbr(int nb)
{
    int i = 0;

    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return 11;
    }
    if (nb == 2147483647) {
        my_putstr("2147483647");
        return 10;
    }
    if (nb == 0) {
        my_putchar('0');
        return 1;
    } else if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
        i++;
    }
    i = print_nb(nb, i);
    return i;
}
