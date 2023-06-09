/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** exitf
*/

#include "mysh.h"

int b_exit(t_system *system)
{
    if (system->new_argv[1] != NULL) {
        if (my_str_isnum(system->new_argv[1]) == 0) {
            mini_printf("exit: Expression Syntax.\n");
            system->last_sig = 1;
            return (0);
        }
        if (system->new_argv[2] != NULL) {
            mini_printf("exit: Expression Syntax.\n");
            system->last_sig = 1;
            return (0);
        }
        mini_printf("exit\n");
        exit(get_num(system->new_argv[1]));
    }
    mini_printf("exit\n");
    exit(0);
    return (84);
}
