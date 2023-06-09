/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** my_array_len
*/

#include <stddef.h>

int my_array_len(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        i++;
    }
    return (i);
}
