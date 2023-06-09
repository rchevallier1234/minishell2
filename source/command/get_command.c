/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** get_command
*/

#include "mysh.h"

int is_valid(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            return 1;
        }
    }
    return (0);
}

void error_get_command(int lineSize, int last_sig)
{
    if (lineSize == -1) {
        if (isatty(0)) {
            mini_printf("exit\n");
        }
        exit(last_sig);
    }
}

char *get_command(int last_sig)
{
    char *line = NULL;
    char **line2 = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;

    if (isatty(0)) {
        mini_printf("$>");
    }
    lineSize = getline(&line, &len, stdin);
    error_get_command(lineSize, last_sig);
    if (line[0] == '\n' || is_valid(line) == 0) {
        return NULL;
    }
    line2 = my_str_to_word_array(line, '\n');
    line = my_strdup(line2[0]);
    free_array(line2);
    return (line);
}
