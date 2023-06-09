/*
** EPITECH PROJECT, 2023
** my_sh
** File description:
** change_directory2
*/

#include "mysh.h"

int change_directory_get_newpwd_root(char *name_directory,
    struct system_s *system)
{
    if (name_directory[0] == '/') {
        system->old_pwd = my_strdup(system->pwd);
        system->pwd = my_strdup(name_directory);
        my_setenv(system->env, "PWD", name_directory);
        return (1);
    }
    return (0);
}

void change_directory_get_newpwd_special(struct system_s *system,
    char **list_pwd)
{
    if (system->pwd[1] != '\0') {
        list_pwd = my_str_to_word_array(system->pwd, '/');
        system->pwd = "\0";
        for (int j = 0; list_pwd[j + 1] != NULL; j++) {
            system->pwd = (j != 0) ? my_strcat(system->pwd, "/") : system->pwd;
            system->pwd = my_strcat(system->pwd, list_pwd[j]);
        }
    }
}

void change_directory_get_newpwd_current(struct system_s *system,
    char **list_directory, char **list_pwd)
{
    for (int i = 0; list_directory[i] != NULL; i++) {
        if (my_strcmp_only_first(list_directory[i], "..") == 1) {
            change_directory_get_newpwd_special(system, list_pwd);
        }
        if (system->pwd[1] != '.' && my_strcmp_only_first(list_directory[i], "..") != 1) {
            system->pwd = my_strcat(system->pwd, "/");
            system->pwd = my_strcat(system->pwd, list_directory[i]);
        }
    }
}

void change_directory_get_newpwd_main(char *name_directory,
    struct system_s *system)
{
    char **list_directory = NULL;
    char **list_pwd = NULL;

    if (change_directory_get_newpwd_root(name_directory, system) == 1) {
        return;
    }
    list_directory = my_str_to_word_array(name_directory, '/');
    system->old_pwd = system->pwd;
    change_directory_get_newpwd_current(system,
        list_directory, list_pwd);
    my_setenv(system->env, "PWD", system->pwd);
}
