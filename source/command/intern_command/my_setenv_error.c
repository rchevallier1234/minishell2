/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** my_setenv_error
*/

#include "mysh.h"

int setenv_is_error(char *name_var)
{
    if (my_char_is_alphanum(name_var[0]) != 1) {
        mini_printf("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    for (int i = 0; name_var[i] != '\0'; i++) {
        if (my_char_is_alphanum(name_var[i]) != 1) {
            mini_printf("setenv: Variable name must contain");
            mini_printf(" alphanumeric characters.\n");
            return (1);
        }
    }
    return (0);
}

int setenv_is_error2(struct system_s *system)
{
    if (my_char_is_alphanum(system->new_argv[1][0]) != 1) {
        mini_printf("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    for (int i = 0; system->new_argv[1][i] != '\0'; i++) {
        if (my_char_is_alphanum(system->new_argv[1][i]) != 1) {
            mini_printf("setenv: Variable name must contain");
            mini_printf(" alphanumeric characters.\n");
            return (1);
        }
    }
    if (my_array_len(system->new_argv) >= 4) {
        mini_printf("setenv: Too many arguments.\n");
        return (1);
    }
    return (0);
}
