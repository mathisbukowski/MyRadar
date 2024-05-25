/*
** EPITECH PROJECT, 2023
** flag_g.c
** File description:
** flag_g
*/

#include "../../include/my_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static void print_decimal_part(double nb, int decimalPlaces)
{
    int decimalPart;

    my_putchar('.');
    for (int i = 0; i < decimalPlaces; i++) {
        nb *= 10;
    }
    nb /= 10;
    decimalPart = (int)nb;
    if ((decimalPart % 10) >= 5)
        decimalPart++;
    my_put_nbr(decimalPart);
}

static int inf_to_one(double nb, int *integerPart)
{
    int count = 0;
    double nbbis;

    while (*integerPart <= 0) {
        nb = nb * 10;
        *integerPart = (int)nb;
        count++;
    }
    my_put_nbr(*integerPart);
    nbbis = nb - *integerPart;
    print_decimal_part(nbbis, 6);
    my_putstr("e-");
    if (count < 10)
        my_putchar('0');
    if (count == 10)
        my_putchar('1');
    return count;
}

static int between_one_and_ten(double nb, int *integerPart)
{
    double nbbis;

    if (*integerPart >= 1) {
        *integerPart = (int)nb;
    }
    my_put_nbr(*integerPart);
    nbbis = nb - *integerPart;
    print_decimal_part(nbbis, 5);
    my_putstr("e+");
    write(1, "0", 2);
    return 0;
}

static int more_than_ten(double nb, int *integerPart)
{
    int count = 0;
    double nbbis;

    while (*integerPart > 10) {
        nb /= 10;
        *integerPart = (int) nb;
        count++;
    }
    my_put_nbr(*integerPart);
    nbbis = nb - *integerPart;
    print_decimal_part(nbbis, 6);
    my_putstr("e+");
    if (count < 10)
        my_putchar('0');
    if (count == 10)
        my_putchar('1');
    return count;
}

static int g_exponential_flag(double nb)
{
    int integerPart = (int)nb;
    int tmp1;
    int tmp2;
    int tmp3;

    if (nb < 1 && nb >= 0) {
        tmp1 = inf_to_one(nb, &integerPart);
        my_put_nbr(tmp1);
    }
    if (nb < 10 && nb >= 1) {
        tmp2 = between_one_and_ten(nb, &integerPart);
        my_put_nbr(tmp2);
    }
    if (nb > 10) {
        tmp3 = more_than_ten(nb, &integerPart);
        my_put_nbr(tmp3);
    }
    return 0;
}

int conditions_round(int integerPart, int decimalPart)
{
    if (integerPart < 0 && decimalPart >= 9999990)
        integerPart--;
    if (integerPart > 0 && decimalPart >= 9999990)
        integerPart++;
    return integerPart;
}

void conditions_f_flag(int decimalPart, int integerPart)
{
    if (decimalPart % 10 >= 5) {
        integerPart = conditions_round(integerPart, decimalPart);
        decimalPart += 10;
    }
    decimalPart /= 100;
    my_put_nbr_f_flag(integerPart);
    write(1, ".", 1);
    if (decimalPart == 0)
        write(1, "000", 3);
    if (decimalPart < 100000)
        write(1, "0", 1);
    my_put_nbr_f_flag(decimalPart);
}

void display_f_flag(int integerPart, int decimalPart, double nb)
{
    if (nb == -1)
        write(1, "-1.00000", 8);
    else if (nb == 1)
        write(1, "1.00000", 7);
    else {
        conditions_f_flag(decimalPart, integerPart);
    }
}

int g_float_flag(double nb)
{
    int integerPart = (int)nb;
    int decimalPart = (nb - integerPart) * 10000000;

    if (decimalPart < 0)
        decimalPart = -decimalPart;
    if (nb == 0.0)
        write(1, "0.00000", 7);
    else {
        if (nb < 0 && nb > -1)
            write(1, "-", 1);
        display_f_flag(integerPart, decimalPart, nb);
    }
    return 0;
}

int g_flag(va_list arg)
{
    double nb = va_arg(arg, double);
    int integerPart = (int)nb;
    int decimalPart = nb - integerPart;

    if (nb < 1000000 && nb >= 100000)
        my_put_nbr((int)nb);
    else if (nb >= 0.0001) {
        my_put_nbr(integerPart);
        write(1, ".", 1);
        my_put_nbr(decimalPart);
    } else
        g_exponential_flag(nb);
    return 0;
}
