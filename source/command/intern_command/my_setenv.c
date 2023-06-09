/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** my_setenv
*/

#include "mysh.h"

char **setenv_creat_new_var(char **env, char *name_var, char *value_var)
{
    int i = 0;
    char **new_env = NULL;

    new_env = malloc(sizeof(char *) * (my_array_len(env) + 2));
    for (i = 0; env[i] != NULL; i++) {
        new_env[i] = NULL;
        new_env[i] = my_strdup(env[i]);
    }
    new_env[i] = my_strcat(name_var, "=");
    if (value_var != NULL) {
        new_env[i] = my_strcat(new_env[i], value_var);
    }
    new_env[i + 1] = NULL;
    return (new_env);
}

char **setenv_modify_value(char **env, char *value_var, int i)
{
    char **env_var = NULL;
    char *new_value = NULL;

    env_var = my_str_to_word_array(env[i], '=');
    new_value = my_strcat(env_var[0], "=");
    if (value_var != NULL) {
        new_value = my_strcat(new_value, value_var);
    }
    env[i] = new_value;
    return (env);
}

char **my_setenv(char **env, char *name_var, char *value_var)
{
    int i = 0;

    if (name_var == NULL) {
        envf(env);
        return (env);
    }
    if (setenv_is_error(name_var) == 1) {
        return (env);
    }
    i = find_env(env, name_var);
    if (i != -1) {
        env = setenv_modify_value(env, value_var, i);
        return (env);
    }
    env = setenv_creat_new_var(env, name_var, value_var);
    return (env);
}

int b_setenv(t_system *system)
{
    int i = 0;

    if (system->new_argv[1] == NULL) {
        envf(system->env);
        return (0);
    }
    if ((system->last_sig = setenv_is_error2(system)) == 1) {
        return (1);
    }
    i = find_env(system->env, system->new_argv[1]);
    if (i != -1) {
        system->env = setenv_modify_value(system->env, system->new_argv[2], i);
        return (0);
    }
    system->env = setenv_creat_new_var(system->env,
        system->new_argv[1], system->new_argv[2]);
    return (0);
}
