/*
** EPITECH PROJECT, 2023
** my_put_nbr.
** File description:
** put number
*/
#include "../../include/my_printf.h"
#include <unistd.h>

int my_put_nbr_f_flag(int n)
{
    char neg = '-';
    int var;

    if (n < 0) {
        write(1, &neg, 1);
        n = n * (-1);
    }
    if (n >= 0) {
        if (n > 10) {
            var = n % 10;
            n = ((n - var) / 10);
            my_put_nbr_f_flag(n);
            my_putchar(48 + var);
        } else
            my_putchar(48 + n % 10);
    }
    return n;
}
