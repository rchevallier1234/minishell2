/*
** EPITECH PROJECT, 2022
** header
** File description:
** header
*/

#ifndef MINI_PRINTF
    #define MINI_PRINTF
    #include <stdarg.h>

int int_lenght(int num);
void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(char *str);
int display_var2(int i, const char *format, va_list list);
int display_var1(int i, const char *format, va_list list);
int mini_printf(const char *format, ...);
int my_strlen(char const *str);

#endif
