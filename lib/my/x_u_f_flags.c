/*
** EPITECH PROJECT, 2023
** flag.c
** File description:
** flag for my_printf
*/

#include "../../include/my_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int conditions_round(int integerPart, int decimalPart)
{
    if (integerPart < 0 && decimalPart >= 9999990)
        integerPart--;
    if (integerPart > 0 && decimalPart >= 9999990)
        integerPart++;
    return integerPart;
}

static int conditions(int integerPart, int decimalPart)
{
    int tmp;

    if (decimalPart % 10 >= 5) {
        integerPart = conditions_round(integerPart, decimalPart);
        decimalPart += 10;
    }
    decimalPart /= 10;
    my_put_nbr_f_flag(integerPart);
    write(1, ".", 1);
    if (decimalPart == 0)
        write(1, "0000", 4);
    tmp = decimalPart;
    for (; tmp < 100000; tmp *= 10) {
        write(1, "0", 1);
    }
    my_put_nbr_f_flag(decimalPart);
    return 0;
}

static void display_f_flag(int integerPart, int decimalPart, double nb)
{
    if (nb == -1)
        write(1, "-1.000000", 9);
    else if (nb == 1)
        write(1, "1.000000", 8);
    else {
        conditions(integerPart, decimalPart);
    }
}

int maj_x_flag(va_list arg)
{
    unsigned int quotient = va_arg(arg, unsigned int);
    char hexa[100];
    int reste;
    int j;

    for (j = 0; quotient; j++) {
        reste = quotient % 16;
        if (reste < 10)
            hexa[j] = '0' + reste;
        else
            hexa[j] = 'A' + reste - 10;
        quotient /= 16;
    }
    hexa[j] = '\0';
    my_revstr(hexa);
    my_putstr(hexa);
    return 0;
}

int x_flag(va_list arg)
{
    unsigned long int quotient = va_arg(arg, unsigned long int);
    char hexa[100];
    int reste;
    int j;

    for (j = 0; quotient; j++) {
        reste = quotient % 16;
        if (reste < 10)
            hexa[j] = '0' + reste;
        else
            hexa[j] = 'A' + reste - 10;
        quotient /= 16;
    }
    hexa[j] = '\0';
    my_revstr(hexa);
    my_strlowcase(hexa);
    my_putstr(hexa);
    return 0;
}

void u_flag_rec(unsigned int nb)
{
    unsigned int n;

    if (nb >= 10) {
        u_flag_rec((nb / 10));
    }
    n = ('0' + nb % 10);
    write(1, &n, 1);
}

int u_flag(va_list arg)
{
    unsigned int nb = va_arg(arg, unsigned int);

    u_flag_rec(nb);
    return 0;
}

int f_flag(va_list arg)
{
    double nb = va_arg(arg, double);
    int integerPart = (int)nb;
    int decimalPart = (nb - integerPart) * 10000000;

    if (decimalPart < 0)
        decimalPart = -decimalPart;
    if (nb == 0.0)
        write(1, "0.000000", 8);
    else {
        if (nb < 0 && nb > -1)
            write(1, "-", 1);
        display_f_flag(integerPart, decimalPart, nb);
    }
    return 0;
}
