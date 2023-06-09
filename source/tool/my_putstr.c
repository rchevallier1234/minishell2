/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** Wrte a fonction that displays, one-by-one,
** the characters of a string
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        write(1, &str[i], 1);
        i = i + 1;
    }
    return (1);
}
