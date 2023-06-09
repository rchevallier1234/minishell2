/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** parse_line_user_error
*/

#include "mysh.h"

t_pipe_tree *parse_line_user_error(t_pipe_tree *current, parsing_t *parsing,
    int *error)
{
    if (parsing->command[parsing->i] == '|' &&
        parsing->command[parsing->i + 1] == '|') {
        current->type = COMMAND;
        current->command = parsing->pipe[parsing->index];
        *error = -1;
    }
    return (current);
}

char **merge_array(char **array, int index1)
{
    char **new_array = NULL;

    new_array = malloc(sizeof(char) * my_array_len(array));
    for (int i = 0; array[i] != NULL; i++) {
        new_array[i] = my_strdup(array[i]);
        if (i == index1) {
            new_array[i] = my_strcat(new_array[i], " << ");
            new_array[i] = my_strcat(new_array[i], array[i + 1]);
            i++;
            new_array[i] = NULL;
        } else {
            new_array[i + 1] = NULL;
        }
    }
    free_array(array);
    return (new_array);
}

char **parse_line_user_dredin(char **pipe, char *command)
{
    int index = 0;

    for (int i = 0; command[i] != '\0'; i++) {
        if (command[i] == '<' && command[i + 1] == '<') {
            pipe = merge_array(pipe, index);
            i += 2;
        }
        if (command[i] == '>' && command[i + 1] == '>') {
            index++;
            i += 2;
        }
        if (command[i] == '<' || command[i] == '>' || command[i] == '|') {
            index++;
        }
    }
    return (pipe);
}
