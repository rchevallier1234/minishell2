/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function.
*/

#include "mysh.h"

int my_strcmp_only_first(char const *s1, char const *s2)
{
    int i = 0;

    while ( s1[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (0);
        }
        i++;
    }
    return (1);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = (0);

    if (my_strlen(s1) != my_strlen(s2)) {
        return 0;
    }
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (0);
        }
        i++;
    }
    return (1);
}
