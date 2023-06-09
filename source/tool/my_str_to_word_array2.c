/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

int find_nb_separator2(char *str, char *separator)
{
    int nb_separator = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (my_charcmp(separator, str[i]) == 1) {
            nb_separator++;
        }
    }
    if (my_charcmp(separator, str[i]) == 1) {
        nb_separator++;
    }
    nb_separator++;
    return (nb_separator);
}

int *find_nb_charaters2(char *str, char *separator, int nb_separator)
{
    int *nb_charaters = NULL;
    int index = 0;

    nb_charaters = malloc(sizeof(int) * (nb_separator + 1));
    nb_charaters[index] = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_charcmp(separator, str[i]) == 1) {
            index++;
            nb_charaters[index] = 0;
        }
        nb_charaters[index] = nb_charaters[index] + 1;
    }
    return (nb_charaters);
}

int passe_separator2(int i, char *str, char *separator)
{
    while (my_charcmp(separator, str[i]) == 1) {
        i++;
    }
    return (i);
}

char **convert_str_to_array2(char **array, char *str, char *separator)
{
    int rows = 0;
    int cols = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_charcmp(separator, str[i]) == 1) {
            i = passe_separator2(i, str, separator);
            i--;
            rows++;
            cols = 0;
            array[rows][cols] = '\0';
        } else {
            array[rows][cols] = str[i];
            cols++;
            array[rows][cols] = '\0';
        }
    }
    array[rows + 1] = NULL;
    return (array);
}

char **my_str_to_word_array2(char *str, char *separator)
{
    char **array = NULL;
    int nb_separator = 0;
    int *nb_charaters = NULL;

    nb_separator = find_nb_separator2(str, separator);
    nb_charaters = find_nb_charaters2(str, separator, nb_separator);
    array = malloc(sizeof(char *) * (nb_separator + 1));
    for (int i = 0; i != nb_separator; i++) {
        array[i] = malloc(sizeof(char) * (nb_charaters[i] + 1));
        array[i][0] = '\0';
        array[i + 1] = NULL;
    }
    free(nb_charaters);
    array = convert_str_to_array2(array, str, separator);
    return (array);
}
