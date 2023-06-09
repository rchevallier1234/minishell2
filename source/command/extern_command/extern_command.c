/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** extern_command
*/

#include "mysh.h"

void segfault_error(int status, int sig)
{
    if (sig == 11) {
        mini_printf( "Segmentation fault");
        if (WCOREDUMP(status)) {
            mini_printf(" (core dumped)\n");
        } else {
            mini_printf("\n");
        }
    }
    if (sig == 8) {
        mini_printf("Floating exception");
        if (WCOREDUMP(status)) {
            mini_printf(" (core dumped)\n");
        } else {
            mini_printf("\n");
        }
    }
}

int print_status(int status)
{
    int sig = 0;

    if (WIFSIGNALED(status)) {
        sig = WTERMSIG(status);
        segfault_error(status, sig);
    }
    if (status == 11) {
        return 139;
    }
    if (status == 512) {
        return 2;
    }
    if (status == 256) {
        return 1;
    }
    return (status);
}

int extern_command2(struct system_s *system, char *path_file,
    context_t *context)
{
    pid_t pid = 0;
    int test = 0;

    pid = fork();
    if (pid == -1) {
        return (84);
    }
    if (pid == 0) {
        if (context->fd_close >= 0 && test != 1) {
            close(context->fd_close);
        }
        dup2(context->fd[STDIN_FILENO], STDIN_FILENO);
        dup2(context->fd[STDOUT_FILENO], STDOUT_FILENO);
        execve(path_file, system->new_argv, system->env);
        exit(1);
    } else {
    }
    return (1);
}

int extern_command_error(struct system_s *system, char *path_file)
{
    if (my_strcmp(path_file, "perm_error") == 1 ||
        my_strcmp(path_file, "directory_error") == 1) {
        system->last_sig = 1;
        return (1);
    }
    return (0);
}

int extern_command(struct system_s *system, context_t *context, char *command)
{
    char *path_file = NULL;
    int return_value = 0;

    if (dredir_in(system, command, context, &return_value) != 0) {
        return (return_value);
    }
    system->new_argv = my_str_to_word_array2(clean_str(command), " \t");
    path_file = find_file_main(system->new_argv[0], system->path);
    if (system->intern_command_v == 0 && path_file != NULL) {
        if (extern_command_error(system, path_file) == 1) {
            return (0);
        }
        extern_command2(system, path_file, context);
        free(path_file);
        return 1;
    } else if (system->intern_command_v == 0 && path_file == NULL) {
        mini_printf("%s: Command not found.\n", system->new_argv[0]);
        system->last_sig = 1;
    }
    return (0);
}
