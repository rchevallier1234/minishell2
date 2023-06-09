/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** Write a fonction that counts and returns the number of characters
** found in the string passed as parameter
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
