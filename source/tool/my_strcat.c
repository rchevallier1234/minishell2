/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** my_strcat
*/

#include "mysh.h"

char *my_strcat(char *dest, char *src)
{
    char *result = NULL;
    int lenght = 0;
    int i = 0;

    result = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
    while (dest[lenght] != '\0') {
        result[lenght] = dest[lenght];
        lenght++;
    }
    while (i != my_strlen(src)) {
        result[lenght] = src[i];
        i++;
        lenght++;
    }
    result[lenght] = '\0';
    return (result);
}
