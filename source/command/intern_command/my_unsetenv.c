/*
** EPITECH PROJECT, 2023
** mysh.h
** File description:
** my_unsetenv
*/

#include "mysh.h"

int my_unsetenv_find_pos_env(struct system_s *system, int index2)
{
    int i = 0;
    char **env_name = NULL;

    for (i = 0; system->env[i] != NULL; i++) {
        env_name = my_str_to_word_array(system->env[i], '=');
        if (my_strcmp(system->new_argv[index2], env_name[0]) == 1) {
            return (i);
        }
    }
    free_array(env_name);
    return (-1);
}

char **creat_new_env(struct system_s *system, int index2)
{
    char **new_env = NULL;
    int index = 0;
    int i = 0;

    new_env = malloc(sizeof(char *) * my_array_len(system->env));
    i = my_unsetenv_find_pos_env(system, index2);
    for (int j = 0; system->env[j] != NULL; j++) {
        if (j != i) {
            new_env[index] = NULL;
            new_env[index] = my_strdup(system->env[j]);
            new_env[index + 1] = NULL;
            index++;
        }
    }
    if (index == 0 && i != -1) {
        new_env[0] = NULL;
    }
    return (new_env);
}

int b_unsetenv(t_system *system)
{
    if (system->new_argv[1] == NULL) {
        mini_printf("unsetenv: Too few arguments.\n");
        system->last_sig = 1;
        return (1);
    }
    for (int j = 1; system->new_argv[j] != NULL; j++) {
        if (system->env[0] != NULL) {
            system->env = creat_new_env(system, j);
        }
    }
    return (0);
}
