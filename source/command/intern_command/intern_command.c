/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** intern_command
*/

#include "builtin.h"

int intern_command2(t_system *system, context_t *context)
{
    int pid = 0;

    pid = fork();
    if (pid == -1) {
        return (84);
    }
    if (pid == 0) {
        if (context->fd_close >= 0) {
            close(context->fd_close);
        }
        dup2(context->fd[STDIN_FILENO], STDIN_FILENO);
        dup2(context->fd[STDOUT_FILENO], STDOUT_FILENO);
        envf2(system->env, context);
        exit(0);
    }
    return (0);
}

int intern_command(t_system *system, char *command, context_t *context)
{
    int return_value = 0;

    if (dredir_in(system, command, context, &return_value) != 0) {
        return (return_value);
    }
    system->new_argv = my_str_to_word_array2(clean_str(command), " \t");
    if (my_strcmp(system->new_argv[0], "env") == 1 ||
        (my_strcmp(system->new_argv[0], "setenv") == 1 &&
        system->new_argv[1] == NULL)) {
        intern_command2(system, context);
        system->intern_command_v = 1;
        return (1);
    }
    for (int i = 0; builtins[i].name != NULL; i++) {
        if (my_strcmp(builtins[i].name, system->new_argv[0]) == 1) {
            builtins[i].f_builtin(system);
            system->intern_command_v = 1;
        }
    }
    return (0);
}
