/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** my_char_is_alphanum
*/

int my_char_is_alphanum(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z')) {
        return (1);
    }
    if (c >= '0' && c <= '9') {
        return (1);
    }
    if (c == '_') {
        return (1);
    }
    return (0);
}
