/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** parse_line_user
*/

#include "../include/mysh.h"

t_pipe_tree *set_next_current(t_pipe_tree *current, parsing_t *parsing)
{
    current->command = NULL;
    current->left = malloc(sizeof(t_pipe_tree));
    current->left->command = parsing->pipe[parsing->index];
    current->left->type = COMMAND;
    current->right = malloc(sizeof(t_pipe_tree));
    current->right->command = parsing->pipe[parsing->index + 1];
    current->right->type = COMMAND;
    current = current->right;
    return (current);
}

t_pipe_tree *creat_current2(t_pipe_tree *current, parsing_t *parsing)
{
    if (parsing->command[parsing->i] == '<') {
        if (parsing->command[parsing->i + 1] == '<') {
            parsing->i += 2;
            return (current);
        }
        current->type = REDIR_IN;
        current = set_next_current(current, parsing);
        parsing->index++;
    }
    if (parsing->command[parsing->i] == '>') {
        if (parsing->command[parsing->i + 1] == '>'){
            current->type = DREDIR_OUT;
            parsing->i += 2;
        } else
            current->type = REDIR_OUT;
        current = set_next_current(current, parsing);
        parsing->index++;
    }
    return (current);
}

t_pipe_tree *creat_current(t_pipe_tree *current, parsing_t *parsing)
{
    int error = 0;
    parsing->index = 0;

    for (parsing->i = 0; parsing->command[parsing->i] != '\0'; parsing->i++) {
        current = parse_line_user_error(current, parsing, &error);
        if (error == -1) {
            return (current);
        }
        if (parsing->command[parsing->i] == '|') {
            current->type = PIPE;
            current = set_next_current(current, parsing);
            parsing->index++;
        }
        current = creat_current2(current, parsing);
        if (parsing->pipe[parsing->index] == NULL) {
            break;
        }
    }
    return (current);
}

t_pipe_tree *creat_tree(t_pipe_tree **head, parsing_t *parsing)
{
    t_pipe_tree *current = (*head);

    current = creat_current(current, parsing);
    for (int i = 0; parsing->command[i] != '\0'; i++) {
        if (parsing->command[i] == '<' && parsing->command[i + 1] == '<') {
            i += 2;
        }
        if (parsing->command[i] == '|' || parsing->command[i] == '>' ||
            parsing->command[i] == '<') {
            parsing->index++;
        }
    }
    if (parsing->index == 0) {
        (*head)->type = COMMAND;
        (*head)->command = parsing->pipe[0];
        return *head;
    }
    return (*head);
}

t_pipe_tree *parse_line_user(char *command)
{
    t_pipe_tree *head = NULL;
    parsing_t parsing;

    head = malloc(sizeof(t_pipe_tree));
    head->left = NULL;
    head->right = NULL;
    head->type = COMMAND;
    command = clean_str(command);
    parsing.pipe = my_str_to_word_array2(command, "|><");
    parsing.pipe = parse_line_user_dredin(parsing.pipe, command);
    parsing.command = command;
    head = creat_tree(&head, &parsing);
    free(command);
    return (head);
}
