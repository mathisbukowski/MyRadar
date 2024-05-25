/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** check_collisions.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>

sfBool are_planes_colliding(link_radar_t *plane1, link_radar_t *plane2)
{
    sfFloatRect bounds1 = my_getglobalbounds(plane1->graphic.plane.rect);
    sfFloatRect bounds2 = my_getglobalbounds(plane2->graphic.plane.rect);

    return sfFloatRect_intersects(&bounds1, &bounds2, NULL);
}

static int initialize_collision(link_radar_t *plane1, link_radar_t *plane2)
{
    if (plane2->graphic.type == PLANE && plane1 != plane2 &&
        plane1->graphic.plane.is_in_tower != 1 &&
        plane2->graphic.plane.is_in_tower != 1) {
        return are_planes_colliding(plane1, plane2) ? 1 : 0;
    }
    return 0;
}

int is_colliding(link_radar_t *plane, link_radar_t *head)
{
    link_radar_t *current = head;

    while (current != NULL) {
        if (initialize_collision(plane, current) != 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

static void last_cond(link_radar_t *current, link_radar_t *head)
{
    if (is_colliding(current, head) != 0) {
        current->graphic.plane.collapsed = 0;
    }
}

void detect_collisions(link_radar_t *head)
{
    link_radar_t *current = head;

    while (current != NULL) {
        if (current->graphic.type == PLANE) {
            last_cond(current, head);
        }
        current = current->next;
    }
}
