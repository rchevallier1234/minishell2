/*
** EPITECH PROJECT, 2023
** mhsy
** File description:
** redir_error
*/

#include "mysh.h"

int redir_error(t_pipe_tree *pipe_tree)
{
    if (pipe_tree->right->type == COMMAND &&
        pipe_tree->right->command[0] == '\0') {
        mini_printf("Missing name for redirect.\n");
        return 1;
    }
    if (pipe_tree->left->command[0] == '\0') {
        mini_printf("Invalid null command.\n");
        return 1;
    }
    if (pipe_tree->right->type != COMMAND) {
        if (clean_str(pipe_tree->right->left->command)[0] == '\0') {
            mini_printf("Missing name for redirect.\n");
        } else {
            mini_printf("Ambiguous output redirect.\n");
        }
        return 1;
    }
    return (0);
}

int redir_error2(char **command)
{
    if (clean_str(command[1])[0] == '\0') {
        mini_printf("Missing name for redirect.\n");
        return 1;
    }
    if (clean_str(command[0])[0] == '\0') {
        mini_printf("Invalid null command.\n");
        return 1;
    }
    return (0);
}
