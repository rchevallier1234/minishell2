/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** env
*/

#include "mysh.h"

int b_env(t_system *system)
{
    for (int i = 0; system->env[i] != NULL; i++) {
        mini_printf("%s\n" ,system->env[i]);
    }
    return (0);
}

int envf(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        mini_printf("%s\n" ,env[i]);
    }
    return (0);
}

int envf2(char **env, context_t *context)
{
    for (int i = 0; env[i] != NULL; i++) {
        write(STDOUT_FILENO, env[i], my_strlen(env[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    return (0);
}