/*
** EPITECH PROJECT, 2022
** get_num
** File description:
** get a num of a string
*/

#include "mysh.h"

int get_num3(const char *format, int i, int nb)
{
    switch (format[i]) {
    case '7':
        nb += 7;
        break;
    case '8':
        nb += 8;
        break;
    case '9':
        nb += 9;
        break;
    }
    return (nb);
}

int get_num2(const char *format, int i, int nb)
{
    switch (format[i]) {
    case '3':
        nb += 3;
        break;
    case '4':
        nb += 4;
        break;
    case '5':
        nb += 5;
        break;
    case '6':
        nb += 6;
        break;
    }
    return (nb);
}

int get_num(char *format)
{
    int nb = 0;
    for (int count = 0; my_char_isnum(format[count]) != 0; count++) {
        nb = nb * 10;
        switch (format[count]) {
        case '0':
            nb += 0;
            break;
        case '1':
            nb += 1;
            break;
        case '2':
            nb += 2;
            break;
        }
        nb = get_num2(format, count, nb);
        nb = get_num3(format, count, nb);
    }
    return (nb);
}
