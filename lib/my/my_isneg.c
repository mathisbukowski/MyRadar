/*
** EPITECH PROJECT, 2023
** my_isneg.c
** File description:
** display n or p for number
*/
#include "../../include/my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar(80);
    } else {
        my_putchar(78);
    }
}
