/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** That function has to print all the characters in
** the string format and print variable when % is used before.
*/

#include <stdarg.h>
#include "mini_printf.h"

int int_lenght(int num)
{
    int lenght = 0;

    while (num > 9 || num < -9) {
        num = num / 10;
        lenght++;
    }
    lenght++;
    return (lenght);
}

int display_var2(int i, const char *format, va_list list)
{
    int result = 0;
    int intsave = 0;

    switch (format[i + 1]) {
    case 'i':
        intsave = va_arg(list, int);
        my_put_nbr(intsave);
        result += int_lenght(intsave);
        break;
    case 'd':
        intsave = va_arg(list, int);
        my_put_nbr(intsave);
        result += int_lenght(intsave);
        break;
    case '%':
        my_putchar('%');
        result++;
        break;
    }
    return (result);
}

int display_var1(int i, const char *format, va_list list)
{
    int result = 0;
    char *savestring;

    switch (format[i + 1]) {
    case 'c':
        my_putchar((char) va_arg(list, int));
        result++;
        break;
    case 's':
        savestring = va_arg(list, char *);
        my_putstr(savestring);
        result += my_strlen(savestring);
        break;
    }
    return (result);
}

int mini_printf(const char *format, ...)
{
    int i = 0;
    int result = 0;
    va_list list;
    va_start(list, *format);

    while (format[i] != '\0') {
        if (format[i] == '%') {
            result += display_var1(i, format, list);
            result += display_var2(i, format, list);
            i++;
        } else {
            my_putchar(format[i]);
            result++;
        }
        i++;
    }
    va_end(list);
    return (result);
}
