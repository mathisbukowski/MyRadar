/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** entity_move.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float calculate_distance(float x, float y)
{
    return sqrtf(powf(x, 2) + powf(y, 2));
}

float rotation(coords_t coords)
{
    float angleRad = atan2f(coords.distanceY, coords.distanceX);
    float degree = angleRad * 180 / M_PI;

    return degree;
}

void anime_plane(plane_t *plane, sfSprite *sprite, radar_t *radar)
{
    coords_t coords;

    coords.vel = (float)plane->plane_speed *
    sfTime_asSeconds(radar->lastFrame);
    coords.distanceX = plane->pos_arrived.x - plane->pos_departure.x;
    coords.distanceY = plane->pos_arrived.y - plane->pos_departure.y;
    coords.distance = calculate_distance(coords.distanceX, coords.distanceY);
    if ((int)coords.distance <= 3) {
        plane->is_enabled = 0;
        return;
    }
    plane->pos_departure.x += coords.distanceX / coords.distance * coords.vel;
    plane->pos_departure.y += coords.distanceY / coords.distance * coords.vel;
    sfRectangleShape_setRotation(plane->rect, rotation(coords));
    sfRectangleShape_setPosition(plane->rect, plane->pos_departure);
    sfSprite_setRotation(sprite, rotation(coords));
    sfSprite_setPosition(sprite, plane->pos_departure);
}

static void delay_cond(radar_t *radar, link_radar_t *current)
{
    if (current->graphic.plane.plane_delay > 0) {
        current->graphic.plane.plane_delay -= sfTime_asSeconds(
    sfClock_getElapsedTime(radar->delay));
    } else {
        anime_plane(&(current->graphic.plane),
        current->graphic.sprite, radar);
    }
}

void loop(link_radar_t *head, radar_t *radar, plane_t *plane)
{
    link_radar_t *curr = head;

    while (curr != NULL) {
        if (curr->graphic.type == TOWER)
            is_in_tower_area(plane, &(curr->graphic.tower));
        if (curr->graphic.plane.is_in_tower != 1)
            break;
        curr = curr->next;
    }
}

void entity_move(link_radar_t *head, radar_t *radar)
{
    link_radar_t *current = head;

    while (current != NULL) {
        if (current->graphic.type == PLANE) {
            delay_cond(radar, current);
            loop(head, radar, &(current->graphic.plane));
        }
        current = current->next;
    }
    sfClock_restart(radar->delay);
}
