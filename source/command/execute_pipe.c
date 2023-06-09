/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** execute_pipe
*/

#include "mysh.h"

void execute_pipe_set_context(int p[2], context_t *left_context,
    context_t *right_context)
{
    left_context->fd[STDOUT_FILENO] = p[STDOUT_FILENO];
    left_context->fd_close = p[STDIN_FILENO];
    right_context->fd[STDIN_FILENO] = p[STDIN_FILENO];
    right_context->fd_close = p[STDOUT_FILENO];
}

int execute_pipe_error(struct system_s *system, t_pipe_tree *pipe_tree)
{
    if ((pipe_tree->right->type == COMMAND &&
        pipe_tree->right->command[0] == '\0') ||
        (pipe_tree->left->type == COMMAND &&
        pipe_tree->left->command[0] == '\0')) {
        system->error_redir = 1;
        mini_printf("Invalid null command.\n");
        return 1;
    }
    if ((clean_str(pipe_tree->left->command)[0] == '\0')) {
        system->error_redir = 1;
        mini_printf("Invalid null command.\n");
        return 1;
    }
    return 0;
}

int execute_pipe(struct system_s *system, t_pipe_tree *pipe_tree,
    context_t *context)
{
    int p[2];
    int return_value = 0;
    context_t left_context = *context, right_context = *context;

    if (context->fd_close >= 0) {
        close(context->fd_close);
    }
    if (execute_pipe_error(system, pipe_tree) == 1) {
        return return_value;
    }
    pipe(p);
    execute_pipe_set_context(p, &left_context, &right_context);
    return_value += execute_command2(system, pipe_tree->left, &left_context);
    return_value += execute_command2(system, pipe_tree->right, &right_context);
    close(p[STDIN_FILENO]);
    close(p[STDOUT_FILENO]);
    return (return_value);
}
