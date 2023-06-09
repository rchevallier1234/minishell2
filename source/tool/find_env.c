/*
** EPITECH PROJECT, 2023
** mhsh
** File description:
** find_env
*/

#include "mysh.h"

int find_env(char **env, char *name_var)
{
    char **name_var_t = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        name_var_t = my_str_to_word_array(env[i], '=');
        if (my_strcmp(name_var_t[0], name_var) == 1) {
            return (i);
        }
    }
    return (-1);
}

char *find_value_env(char **env, int pos)
{
    char **env_var = NULL;
    if (pos == -1) {
        return (NULL);
    }
    env_var = my_str_to_word_array(env[pos], '=');
    return (env_var[1]);
}
