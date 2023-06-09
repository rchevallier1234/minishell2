/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** change_directory
*/

#include "mysh.h"

int change_directory_option(struct system_s *system)
{
    char *t_pwd = NULL;

    if (system->new_argv[1][0] == '-' && system->new_argv[1][1] == '\0') {
        if (change_directory_error_option(system) == 1) {
            return (1);
        }
        if (system->old_pwd == NULL) {
            mini_printf(": No such file or directory.\n");
            system->last_sig = 1;
        } else {
            chdir(system->old_pwd);
            t_pwd = my_strdup(system->pwd);
            system->pwd = my_strdup(system->old_pwd);
            system->old_pwd = my_strdup(t_pwd);
            my_setenv(system->env, "PWD", system->pwd);
        }
        return (1);
    }
    return (0);
}

void change_directory_argv1(struct system_s *system)
{
    int return_value = 0;

    return_value = change_directory_option(system);
    if (return_value == 1) {
        return;
    }
    if (change_directory_error(system) == 84) {
        return;
    }
    chdir(system->new_argv[1]);
    change_directory_get_newpwd_main(system->new_argv[1], system);
}

int b_cd(t_system *system)
{
    char **default_directory = NULL;

    if (change_directory_error2(system) == 84) {
        return (1);
    }
    if (system->new_argv[1] != NULL) {
        change_directory_argv1(system);
    } else if (system->new_argv[1] == NULL) {
        default_directory = my_str_to_word_array(
            system->env[find_env(system->env, "HOME")], '=');
        chdir(default_directory[1]);
        system->old_pwd = system->pwd;
        system->pwd = default_directory[1];
        my_setenv(system->env, "PWD", default_directory[1]);
    }
    return (0);
}
