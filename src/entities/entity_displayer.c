/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** entity_displayer.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>

void disp_plane(radar_t *radar, const link_radar_t *current)
{
    if (current->graphic.plane.plane_visible == 1
    && current->graphic.plane.is_enabled == 1 &&
    current->graphic.plane.collapsed == 1)
        sfRenderWindow_drawSprite(radar->window,
    current->graphic.sprite, NULL);
    if (current->graphic.plane.rect_visible == 1
    && current->graphic.plane.is_enabled == 1 &&
    current->graphic.plane.collapsed == 1)
        sfRenderWindow_drawRectangleShape(radar->window,
    current->graphic.plane.rect, NULL);
}

void disp_tower(radar_t *radar, const link_radar_t *current)
{
    if (current->graphic.tower.tower_visible == 1)
        sfRenderWindow_drawSprite(radar->window,
        current->graphic.sprite, NULL);
    if (current->graphic.tower.shape_visible == 1)
        sfRenderWindow_drawCircleShape(radar->window,
        current->graphic.tower.shape, NULL);
}

void entity_displayer(radar_t *radar)
{
    link_radar_t *current = radar->entities;

    while (current != NULL) {
        if (current->graphic.type == PLANE)
            disp_plane(radar, current);
        if (current->graphic.type == TOWER)
            disp_tower(radar, current);
        current = current->next;
    }
}
