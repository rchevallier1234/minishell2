/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** Write a function that allocates memory and
** copies the string given as argument in it
*/
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    int a = 0;
    char *dest = NULL;

    while (src[a] != '\0') {
        a++;
    }
    dest = malloc(sizeof(char) * a + 1);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
