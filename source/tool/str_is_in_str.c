/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** str_is_in_str
*/

#include "mysh.h"

int str_is_in_str(char *str, char *str2)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == str2[len]) {
            len++;
        } else {
            len = 0;
        }
        if (my_strlen(str2) == len) {
            return (1);
        }
    }
    return (0);
}
