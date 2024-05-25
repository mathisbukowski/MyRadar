/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** my_strncpy.c
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i = i + 1;
    }
    if (n > my_strlen(src)) {
        dest[i] = '\0';
    }
    return (dest);
}
