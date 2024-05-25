/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** my_strdup.c
*/

/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_strdup.c
*/
#include "../../include/my.h"

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest = malloc(my_strlen(src));

    if (dest == NULL) {
        return (NULL);
    }
    my_strcpy(dest, src);
    return (dest);
}
