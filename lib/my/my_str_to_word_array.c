/*
** EPITECH PROJECT, 2023
** /lib/my/my_str_to_word_array.c
** File description:
** Extracts words from a string and create an array of words
*/

#include <stdlib.h>
#include "my.h"

static int words_count(char const *str)
{
    int wc = 0;

    for (int a = 0 ; str[a] != 0 ; a++) {
        if (my_isalnum(str[a]) > 0 && my_isalnum(str[a + 1]) < 1)
            wc++;
    }
    return wc;
}

static int word_length(int pos, char const *str)
{
    int length = 0;

    for (int a = pos ; my_isalnum(str[a]) > 0 ; a++)
        length++;
    return length;
}

static void coding_style_compliance(
    int *index_array, int *index, int *malloced)
{
    *index_array += 1;
    *index = 0;
    *malloced = 0;
}

char **my_str_to_word_array(char const *str)
{
    char **words_array = malloc(sizeof(char *) * (words_count(str) + 1));
    int index_array = 0;
    int index = 0;
    int malloced = 0;

    for (int a = 0 ; str[a] != 0 ; a++) {
        if (malloced == 0) {
            words_array[index_array] =
                malloc(sizeof(char) * (word_length(a, str) + 1));
            malloced++;
        }
        if (my_isalnum(str[a]) > 0) {
            words_array[index_array][index] = str[a];
            index++;
        }
        if ((my_isalnum(str[a + 1]) > 0) && (my_isalnum(str[a]) < 1))
            coding_style_compliance(&index_array, &index, &malloced);
    }
    words_array[words_count(str)] = NULL;
    return words_array;
}
