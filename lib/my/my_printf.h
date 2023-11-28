/*
** EPITECH PROJECT, 2023
** B-CPE-110-NCY-1-1-settingup-laszlo.serdet-1
** File description:
** myprintf
*/

#pragma once

#include <stdarg.h>
/* my_printf's maccros */
#define FLAGS "#0- +"
#define MODIFIERS "hlqLjzZt"
#define SPECIFIERS "%csdifFouxXpeEgGaAm"
#define ALLOWED_CHARS ".*"
/* my_printf's array of functions */
int s_percent(va_list *args);
int s_char(va_list *args);
int s_int(va_list *args);
int s_string(va_list *args);
int s_vstring(va_list *args);
int my_putbase_x(va_list *args);
int my_putbase_o(va_list *args);
int my_putbase_xupper(va_list *args);
int my_putbase_u(va_list *args);
int my_putfloat(va_list *args);
int my_put_sc_writing_eupper(va_list *args);
int my_put_sc_writing_e(va_list *args);
int my_putpointer(va_list *args);
