/*
** EPITECH PROJECT, 2023
** my_put_nbr.
** File description:
** put number
*/
#include "../../include/my_printf.h"
#include <unistd.h>

int my_put_nbr(int nb)
{
    int n;

    if (nb > 9) {
        n = nb / 10;
        nb -= 10 * n;
        my_put_nbr(n);
    }
    if (nb > -10 && nb < 0)
        write(1, "0", 1);
    my_putchar('0' + nb);
    return 0;
}
