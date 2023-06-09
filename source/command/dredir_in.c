/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** dredir_in
*/

#include "mysh.h"

char *dredir_in_get_new_argv(char **split, char **split2)
{
    char *new_command = NULL;

    new_command = malloc(sizeof(char) * 1);
    new_command[0] = '\0';
    new_command = my_strcat(new_command, clean_str(split[0]));
    for (int i = 1; split2[i] != NULL; i++) {
        new_command = my_strcat(new_command, " ");
        new_command = my_strcat(new_command, split2[i]);
    }
    free_array(split);
    free_array(split2);
    return (new_command);
}

int dredir_in2(char *command, int p[2])
{
    char *line = "\0", *str = "\0";
    size_t len = 0;
    int pid = 0;

    while (my_strcmp(my_strcat(clean_str(command), "\n"),
        line) != 1) {
        mini_printf("? ");
        getline(&line, &len, stdin);
        str = my_strcat(str, line);
    }
    pid = fork();
    if (pid == -1) {
        return (0);
    }
    if (pid == 0) {
        close(p[0]);
        write(p[1], str, my_strlen(str));
        exit(0);
    }
    return (1);
}

int dredir_in(struct system_s *system, char *command,
    context_t *context, int *return_value)
{
    char *new_command = NULL;
    char **split = NULL;
    char **split2 = NULL;
    int p[2];

    if (str_is_in_str(command, "<<") == 0)
        return (0);
    split = my_str_to_word_array2(command, "<");
    split2 = my_str_to_word_array2(clean_str(split[1]), " \t");
    if (redir_error2(split) == 1)
        return (1);
    pipe(p);
    *return_value += dredir_in2(split2[0], p);
    new_command = dredir_in_get_new_argv(split, split2);
    context->fd[STDIN_FILENO] = p[STDIN_FILENO];
    context->fd_close = p[STDOUT_FILENO];
    *return_value += extern_command(system, context,  new_command);
    close(p[1]);
    close(p[0]);
    return (1);
}
