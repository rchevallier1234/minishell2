/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my_str_isnum
*/

int my_str_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > '9' || str[i] < '0') {
            return (0);
        } else {
            return (1);
        }
    }
    return (0);
}

int my_char_isnum(char c)
{
    if (c > '9' || c < '0') {
        return (0);
    } else {
        return (1);
    }
    return (0);
}
