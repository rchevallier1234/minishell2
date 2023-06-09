/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** tab_builtins
*/

#include "../../../include/builtin.h"

t_builtin builtins[] = {
    {"cd", "change directory", &b_cd},
    {"exit", "exit mysh", &b_exit},
    {"env", "display env", &b_env},
    {"setenv", "add or modify env", &b_setenv},
    {"unsetenv", "rm var env", &b_unsetenv},
    {NULL, NULL, NULL}
};