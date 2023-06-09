/*
** EPITECH PROJECT, 2023
** free_tree
** File description:
** free_tree
*/

#include "mysh.h"

int free_tree(t_pipe_tree *tree)
{
    if (tree->right != NULL) {
        tree = tree->right;
        free_tree(tree);
    } else if (tree->left != NULL) {
        tree = tree->left;
        free_tree(tree);
    } else {
        free(tree);
        return (0);
    }
    return (0);
}
