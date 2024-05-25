/*
** EPITECH PROJECT, 2023
** flag.c
** File description:
** flag for my_printf
*/

#include "../../include/my_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int d_and_i_flags(va_list arg)
{
    my_put_nbr_f_flag(va_arg(arg, int));
    return 0;
}

int s_flag(va_list arg)
{
    my_putstr(va_arg(arg, char *));
    return 0;
}

int c_flag(va_list arg)
{
    unsigned long n = va_arg(arg, unsigned long);

    write(1, &n, 1);
    return 0;
}

int o_flag(va_list arg)
{
    int octal[100];
    int n = va_arg(arg, int);
    int i;

    for (i = 0; n != 0; i++) {
        octal[i] = n % 8;
        n /= 8;
    }
    for (int j = i - 1; j >= 0; j--)
        my_put_nbr(octal[j]);
    return 0;
}
