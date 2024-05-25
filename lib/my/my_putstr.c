/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** display one-by-one some variables
*/
#include "../../include/my.h"

int my_putstr(char const *str)
{
    int index;

    index = 0;
    while (str[index] != '\0') {
        my_putchar(str[index]);
        index++;
    }
    return 0;
}
