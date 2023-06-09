/*
** EPITECH PROJECT, 2023
** clean_str
** File description:
** clean_str.c
*/

#include "mysh.h"

char *clean_str3(char new_str_i, char *new_str2, int *nb_caracter,
    int *is_new_space)
{
    if (new_str_i != ' ' && new_str_i != '\t') {
        new_str2[*nb_caracter] = new_str_i;
        new_str2[*nb_caracter + 1] = '\0';
        (*nb_caracter)++;
        *is_new_space = 0;
    } else if ((new_str_i == ' ' || new_str_i == '\t') && *is_new_space == 0) {
        *is_new_space = 1;
        new_str2[*nb_caracter] = ' ';
        new_str2[*nb_caracter + 1] = '\0';
        (*nb_caracter)++;
    }
    return (new_str2);
}

int get_nb_caracter(char c, int *nb_save, int *nb_caracter)
{
    if (c != ' ' && c != '\t') {
        (*nb_caracter)++;
        *nb_save = 0;
    } else if ((c == ' ' || c == '\t') && *nb_save == 0) {
        *nb_save = 1;
        (*nb_caracter)++;
    }
    return 0;
}

char *clean_str2(char *new_str)
{
    int is_new_space = 1;
    int nb_caracter = 0;
    char *new_str2 = NULL;
    int nb_save = 1;

    for (int i = 0; new_str[i] != '\0'; i++) {
        get_nb_caracter(new_str[i], &nb_save, &nb_caracter);
    }
    new_str2 = malloc(sizeof(char) * nb_caracter + 1);
    nb_caracter = 0;
    for (int i = 0; new_str[i] != '\0'; i++) {
        new_str2 = clean_str3(new_str[i], new_str2,
            &nb_caracter, &is_new_space);
    }
    free(new_str);
    return (new_str2);
}

int get_nb_separator(char *str, int *nb_separator, int *nb_separator_end)
{
    for (int i = 0; str[i] == ' ' || str[i] == '\t'; i++) {
        (*nb_separator)++;
        if (str[i + 1] == '\0') {
            return 1;
        }
    }
    for (int i = my_strlen(str) - 1; str[i] == ' ' || str[i] == '\t'; i--) {
        (*nb_separator_end)++;
    }
    return 0;
}

char *clean_str(char *str)
{
    int nb_separator = 0;
    int nb_separator_end = 0;
    char *new_str = NULL;

    if (get_nb_separator(str, &nb_separator, &nb_separator_end) == 1) {
        return "\0";
    }
    new_str = malloc(sizeof(char) * (my_strlen(str) - nb_separator -
        nb_separator_end));
    for (int i = 0; str[nb_separator] != '\0' &&
        nb_separator != my_strlen(str) - nb_separator_end;
        nb_separator++, i++) {
        new_str[i] = str[nb_separator];
        new_str[i + 1] = '\0';
    }
    free(str), new_str = clean_str2(new_str);
    return (new_str);
}
