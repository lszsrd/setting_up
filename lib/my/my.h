/*
** EPITECH PROJECT, 2023
** lib/my/my.h
** File description:
** Manages lib's prototypes and avoid
** warnings on compilation
*/

#pragma once

#include "my_printf.h"

/* Includes from C lib */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
/* Display functions */
int my_putchar(char);
int my_putnbr(int);
int my_putstr(char const *);
int my_put_prefix(char);
int my_putcharerr(char c);
int my_puterr(char *);
int my_printf(const char *restrict, ...);
int my_dprintf(const char *format, ...);
/* Functions to check a string's characters */
int my_strlen(char const *);
int my_getnbr(char const *);
int my_char_finder(const char *, const char);
int check_bad_arg(const char *format, int a);
int my_str_isnum(char const *str);
int my_str_isalnum(char const *str);
// and its dependencies
int my_isalpha(char);
int my_islower(char);
int my_isupper(char);
int my_isnum(char);
int my_isalnum(char);
/* Functions to act on a string */
char *my_strupcase(char *);
char *my_strcpy(char *, char const *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_revstr(char *);
char **my_str_to_word_array(char const *str);
/* Function to compute */
char *my_convertbase(unsigned long long, int, bool);
char *sc_writing_not_null(double, char);
char *my_float(double);
char *convert_pointer(void *);
