/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** free_array.c
*/

#include "../../include/radar.h"
#include "../../include/my_printf.h"
#include <stdlib.h>

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
