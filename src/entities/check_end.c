/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** check_end.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


static int check_end_cond(link_radar_t *cur)
{
    if (cur->graphic.type == PLANE)
        if (cur->graphic.plane.is_enabled != 0)
            return 1;
    return 0;
}

void check_end(link_radar_t *head, radar_t *radar)
{
    link_radar_t *cur = head;

    while (cur != NULL) {
        if ((check_end_cond(cur)) != 0)
            return;
        cur = cur->next;
    }
    close_window(radar);
}
