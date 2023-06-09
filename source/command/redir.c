/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** redir.c
*/

#include "mysh.h"

int redir_out(struct system_s *system, t_pipe_tree *pipe_tree,
    context_t *context)
{
    int fd = 0;
    int return_value = 0;
    context_t left_context = *context;
    t_pipe_tree *pipe_tree_right = pipe_tree->right;

    close_fd(context);
    if (redir_error(pipe_tree) == 1) {
        system->error_redir = 1;
        return (0);
    }
    fd = open(clean_str(pipe_tree_right->command),
        O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        return 1;
    }
    left_context.fd[STDOUT_FILENO] = fd;
    left_context.fd_close = -1;
    return_value += execute_command2(system, pipe_tree->left, &left_context);
    close(fd);
    return (1);
}

int dredir_out(struct system_s *system, t_pipe_tree *pipe_tree,
    context_t *context)
{
    int fd = 0;
    int return_value = 0;
    context_t left_context = *context;

    close_fd(context);
    if (redir_error(pipe_tree) == 1) {
        system->error_redir = 1;
        return (0);
    }
    fd = open(clean_str(pipe_tree->right->command),
        O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        return (1);
    }
    left_context.fd[STDOUT_FILENO] = fd;
    left_context.fd_close = -1;
    return_value += execute_command2(system, pipe_tree->left, &left_context);
    close(fd);
    return (1);
}

int redir_in(struct system_s *system, t_pipe_tree *pipe_tree,
    context_t *context)
{
    int fd = 0;
    int return_value = 0;
    context_t left_context = *context;

    close_fd(context);
    if (redir_error(pipe_tree) == 1) {
        system->error_redir = 1;
        return 0;
    }
    fd = open(clean_str(pipe_tree->right->command), O_RDONLY);
    if (fd == -1) {
        mini_printf("%s: No such file or directory.\n",
            clean_str(pipe_tree->right->command));
        return 0;
    }
    left_context.fd[STDIN_FILENO] = fd;
    left_context.fd_close = -1;
    return_value += execute_command2(system, pipe_tree->left, &left_context);
    close(fd);
    return return_value;
}
