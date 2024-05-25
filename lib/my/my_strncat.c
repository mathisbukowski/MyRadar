/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** my_strncat
*/
#include "../../include/my.h"


char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int lenght_dest = my_strlen(dest);
    int lenght_src = my_strlen(src);

    while (i <= nb) {
        dest[lenght_dest + i] = src[i];
        i++;
    }
    dest[lenght_dest + nb] = '\0';
}
