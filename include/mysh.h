/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** header
*/

#ifndef MYSH
    #define MYSH

    #include <unistd.h>
    #include <stdio.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <string.h>
    #include <signal.h>
    #include <errno.h>
    #include <fcntl.h>
    #include "mini_printf.h"

    enum commande_type {
            COMMAND = 0,
            PIPE,
            REDIR_OUT,
            DREDIR_OUT,
            REDIR_IN,
        };

    typedef struct pipe_tree_s {
        char *command;
        enum commande_type type;
        struct pipe_tree_s *left;
        struct pipe_tree_s *right;
    } t_pipe_tree;

    typedef struct context_s {
        int fd[2];
        int fd_close;
    } context_t;

    typedef struct system_s {
        char **env;
        char **new_argv;
        char *old_pwd;
        char *pwd;
        char *path;
        int intern_command_v;
        int last_sig;
        int error_redir;
    } t_system;

    typedef struct parsing_s {
        char **pipe;
        char *command;
        int index;
        int i;
    } parsing_t;

    char **my_str_to_word_array(char *str, char separator);
    char **my_str_to_word_array2(char *str, char *separator);
    char *get_command(int last_sig);
    int my_strcmp_only_first(char const *s1, char const *s2);
    int my_strcmp(char const *s1, char const *s2);
    int execute_command(char *line_user, struct system_s *system);
    int execute_command2(struct system_s *system, t_pipe_tree *pipe_tree,
        context_t *context);
    int extern_command(struct system_s *system, context_t *context,
        char *command);
    int intern_command(t_system *system, char *command, context_t *context);
    char *find_file_main(char *name_file, char *path);
    char *my_strcat(char *dest, char *src);
    char **my_setenv(char **env, char *name_var, char *value_var);
    int setenv_is_error(char *name_var);
    int setenv_is_error2(struct system_s *system);
    int my_array_len(char **array);
    char *my_strdup(char const *src);
    int find_env(char **env, char *name_var);
    char *find_value_env(char **env, int pos);
    void change_directory_get_newpwd_main(char *name_directory,
        struct system_s *system);
    int change_directory_error(struct system_s *system);
    int change_directory_error2(struct system_s *system);
    int change_directory_error_option(struct system_s *system);
    void env_command(struct system_s *system);
    char *clean_str(char *str);
    int my_char_is_alphanum(char c);
    int my_charcmp(char *str, char c);
    int my_str_isnum(char *str);
    int my_char_isnum(char c);
    int get_num(char *format);
    void free_array(char **array);
    int envf(char **env);
    int envf2(char **env, context_t *context);
    t_pipe_tree *parse_line_user(char *command);
    int print_status(int status);
    int redir_out(struct system_s *system, t_pipe_tree *pipe_tree,
        context_t *context);
    int dredir_out(struct system_s *system, t_pipe_tree *pipe_tree,
        context_t *context);
    int redir_in(struct system_s *system, t_pipe_tree *pipe_tree,
        context_t *context);
    t_pipe_tree *parse_line_user_error(t_pipe_tree *current, parsing_t *parsing,
        int *error);
    int dredir_in(struct system_s *system, char *command,
        context_t *context, int *return_value);
    int redir_error(t_pipe_tree *pipe_tree);
    int redir_error2(char **command);
    int free_tree(t_pipe_tree *tree);
    char **parse_line_user_dredin(char **pipe, char *command);
    int str_is_in_str(char *str, char *str2);
    int execute_pipe(struct system_s *system, t_pipe_tree *pipe_tree,
    context_t *context);
    void close_fd(context_t *context);

#endif
