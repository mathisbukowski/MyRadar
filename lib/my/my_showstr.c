/*
** EPITECH PROJECT, 2023
** my_showstr
** File description:
** my_showstr
*/
#include "../../include/my.h"

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putstr(str);
    }
    return (0);
}
