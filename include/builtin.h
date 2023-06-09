/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** header
*/

#ifndef builtin
    #define builtin

    #include "mysh.h"

typedef struct s_builtin {
    char *name;
    char *man;
    int (*f_builtin)(t_system *);
} t_builtin;

int b_cd(t_system *system);
int b_env(t_system *system);
int b_setenv(t_system *system);
int b_exit(t_system *system);
int b_unsetenv(t_system *system);

extern t_builtin builtins[];

#endif
