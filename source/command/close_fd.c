/*
** EPITECH PROJECT, 2023
** mhsh
** File description:
** close_fd
*/

#include "mysh.h"

void close_fd(context_t *context)
{
    if (context->fd_close >= 0) {
        close(context->fd_close);
    }
}
