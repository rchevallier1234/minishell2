/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** Writre a function that displays the number given as a parameter
*/

#include <stdio.h>
#include "my.h"

int num_lenght(int num)
{
    int lenght = 0;
    while (num > 9 || num < -9) {
        num = num / 10;
        lenght++;
    }
    return (lenght);
}

int my_compute_power_it(int nb, int p)
{
    int resultat = 1;
    if (p == 0) {
        return (1);
    } else if (p < 0) {
        return (0);
    }
    for (; p != 0; p--) {
        resultat *= nb;
    }
    return (resultat);
}

void is_inf(int nb)
{
    if (nb < 0) {
        my_putchar('-');
    }
}

int print_number(int diviseur, int nb)
{
    int nbsave = nb;
    int compteur = 0, num1 = 48;
    char num0 = 0;

    while (diviseur >= 10) {
        nb = nb / diviseur;
        if (nb < 0) {
            num1 -= nb;
        } else {
            num1 += nb;
        }
        num0 = num1;
        my_putchar(num0);
        nb = nbsave;
        nb = nb % diviseur;
        diviseur = diviseur / 10;
        compteur++;
        num1 = 48;
    }
    return (nb);
}

int my_put_nbr(int nb)
{
    int num1 = 48;
    char num0;
    int lenght;
    int diviseur = 0;

    lenght = num_lenght(nb);
    is_inf(nb);
    diviseur = my_compute_power_it(10, lenght);
    nb = print_number(diviseur, nb);
    num1 = 48;
    if (nb < 0) {
        num1 -= nb;
    } else {
        num1 += nb;
    }
    num0 = num1;
    my_putchar(num0);
    return (1);
}
