/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** my_strcat
*/
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int lenght_dest = my_strlen(dest);
    int lenght_src = my_strlen(src);

    while (i < lenght_src) {
        dest[lenght_dest + i] = src[i];
        i++;
    }
    dest[lenght_dest + lenght_src] = '\0';
    return (dest);
}
