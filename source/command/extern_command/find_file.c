/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** find_file
*/

#include "mysh.h"

char *find_file_error(char *name_file, char *path_file)
{
    DIR *dir = NULL;

    path_file = name_file;
    dir = opendir(name_file);
    if (dir != NULL || (access(name_file, X_OK) == -1 &&
        access(name_file, F_OK) == 0)) {
        mini_printf("%s: Permission denied.\n", name_file);
        closedir(dir);
        return ("directory_error");
    }
    closedir(dir);
    return (path_file);
}

char *find_path(char *path, char *name_file)
{
    char *file_path = NULL;
    char **path_env2 = NULL;
    struct stat s;

    if (path == NULL) {
        return (NULL);
    }
    path_env2 = my_str_to_word_array(path, ':');
    for (int i = 0; path_env2[i] != NULL; i++) {
        file_path = my_strcat(path_env2[i], "/");
        file_path = my_strcat(file_path, name_file);
        if (stat(file_path, &s) != -1) {
            return (file_path);
        }
    }
    return (NULL);
}

char *find_file(char *name_file, char *path)
{
    char *file_path = NULL;

    file_path = find_path(path, name_file);
    return (file_path);
}

char *find_file_main(char *name_file, char *path)
{
    char *path_file = NULL;

    if (my_charcmp(name_file, '/') == 0) {
        path_file = find_file(name_file, path);
    } else {
        path_file = find_file_error(name_file, path_file);
        if (my_strcmp(path_file, "perm_error") == 1 ||
            my_strcmp(path_file, "directory_error") == 1) {
            return (path_file);
        }
    }
    if (access(path_file, X_OK) == -1) {
        path_file = NULL;
    }
    return (path_file);
}
