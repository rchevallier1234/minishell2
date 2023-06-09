/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** change_directory_error
*/

#include "mysh.h"

int change_directory_error_option(struct system_s *system)
{
    if (system->new_argv[2] != NULL) {
        mini_printf("Usage: cd [-plvn][-|<dir>].\n");
        system->last_sig = 1;
        return (1);
    }
    return (0);
}

int change_directory_error(struct system_s *system)
{
    struct stat s;

    if (system->new_argv[2] != NULL) {
        mini_printf("cd: Too many arguments.\n");
        system->last_sig = 1;
        return (84);
    }
    if (opendir(system->new_argv[1]) == NULL) {
        if (stat(system->new_argv[1], &s) != -1) {
        mini_printf("%s: Not a directory.\n", system->new_argv[1]);
        system->last_sig = 1;
        return (84);
        }
        mini_printf("%s: No such file or directory.\n",
            system->new_argv[1]);
        system->last_sig = 1;
        return (84);
    }
    return 0;
}

int change_directory_error2(struct system_s *system)
{
    if (system->new_argv[1] == NULL) {
        if (find_env(system->env, "HOME") == -1) {
            mini_printf("cd: No home directory.\n");
            system->last_sig = 1;
            return (84);
        }
    }
    return (0);
}
