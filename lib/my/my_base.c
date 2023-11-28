/*
** EPITECH PROJECT, 2023
** conversion
** File description:
** decimal to base
*/

#include "my.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

char *my_convertbase(unsigned long long to_convert, int base, bool hexa_lower)
{
    char *converted_base;
    unsigned long long to_convert_copy = to_convert;
    int converted_length = 0;
    int check_hex;
    int case_hex = (hexa_lower == true) ? 87 : 55;

    for (; (to_convert_copy / base) > 0; ) {
        to_convert_copy = to_convert_copy / base;
        converted_length++;
    }
    converted_base = malloc(sizeof(char) * converted_length);
    if (converted_base == NULL)
        return NULL;
    for (int a = converted_length; a >= 0; a--) {
        check_hex = ((to_convert % base) > 9)
        ? (to_convert % base + case_hex) : (to_convert % base + 48);
        converted_base[a] = check_hex;
        to_convert = to_convert / base;
    }
    return converted_base;
}
