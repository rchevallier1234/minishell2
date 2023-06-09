/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** execute_command
*/

#include "mysh.h"

int execute_command2(struct system_s *system, t_pipe_tree *pipe_tree,
    context_t *context)
{
    int return_value = 0;
    if (system->error_redir == 1) {
        return 0;
    }
    switch (pipe_tree->type) {
    case COMMAND:
        return_value += intern_command(system, pipe_tree->command, context);
        return_value += extern_command(system, context, pipe_tree->command);
        return return_value;
    case PIPE:
        return execute_pipe(system, pipe_tree, context);
    case REDIR_OUT:
        return redir_out(system, pipe_tree, context);
    case REDIR_IN:
        return redir_in(system, pipe_tree, context);
    case DREDIR_OUT:
        return dredir_out(system, pipe_tree, context);
    }
    return (0);
}

void set_context(struct system_s *system, t_pipe_tree *pipe_tree)
{
    context_t context;
    int value = 0;
    int status = 0;

    context.fd[0] = STDIN_FILENO;
    context.fd[1] = STDOUT_FILENO;
    context.fd_close = -1;
    value = execute_command2(system, pipe_tree, &context);
    for (int i = 0; i < value; i++) {
        waitpid(-1, &status, 0);
        system->last_sig = print_status(status);
    }
}

int execute_command(char *line_user, struct system_s *system)
{
    t_pipe_tree *pipe = NULL;
    char **command = NULL;

    if (line_user == NULL) {
        return (0);
    }
    command = my_str_to_word_array(line_user, ';');
    system->error_redir = 0;
    for (int i = 0; command[i] != NULL && system->error_redir == 0; i++) {
        system->last_sig = 0;
        pipe = parse_line_user(command[i]);
        system->intern_command_v = 0;
        set_context(system, pipe);
        free_tree(pipe);
    }
    return (0);
}
