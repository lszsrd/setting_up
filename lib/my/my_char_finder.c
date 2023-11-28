/*
** EPITECH PROJECT, 2023
** src/my_char_finder.c
** File description:
** Search for a char in a string
*/

int my_char_finder(const char *str, const char c)
{
    for (int a = 0; str[a] != 0; a++)
        if (str[a] == c)
            return a;
    return -1;
}
