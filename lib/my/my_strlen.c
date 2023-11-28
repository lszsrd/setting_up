/*
** EPITECH PROJECT, 2023
** /lib/my/my_strlen.c
** File description:
** Returns the lenght of the given string
*/

int my_strlen(char const *str)
{
    int c = 0;

    for (int a = 0; str[a] != 0; a++)
        c++;
    return c;
}
