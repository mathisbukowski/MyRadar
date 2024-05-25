/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** check_tower.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void is_in_tower_area(plane_t *plane, tower_t *tower)
{
    int towerBounds = my_circleglobalbounds(tower->shape, plane->rect);

    if (towerBounds) {
        plane->is_in_tower = 1;
        sfRectangleShape_setOutlineColor(plane->rect, sfCyan);
    } else {
        sfRectangleShape_setOutlineColor(plane->rect, sfRed);
        plane->is_in_tower = 0;
    }
}
