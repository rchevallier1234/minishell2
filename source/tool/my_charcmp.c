/*
** EPITECH PROJECT, 2023
** mysh
** File description:
** my_charcmp
*/

int my_charcmp(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return (1);
        }
    }
    return (0);
}
