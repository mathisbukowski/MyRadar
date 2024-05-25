/*
** EPITECH PROJECT, 2023
** flag.c
** File description:
** flag for my_printf
*/

#include "../../include/my_printf.h"
#include <stdarg.h>
#include <unistd.h>

int p_flag(va_list arg)
{
    if (arg == 0)
        my_putstr("(nil)");
    write(1, "0x", 2);
    x_flag(arg);
    return 0;
}

int pc_flag(va_list arg)
{
    write(1, "%", 1);
    return 0;
}

int n_flag(va_list arg, int count)
{
    int *value = va_arg(arg, int *);

    *value = count;
    return 0;
}
