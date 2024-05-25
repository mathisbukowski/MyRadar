/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** entity_destroyer.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>


void null_list(link_radar_t **list, link_radar_t *to_remove)
{
    while (*list != NULL) {
        to_remove = (*list);
        (*list) = (*list)->next;
        if (to_remove->graphic.type == PLANE)
            sfRectangleShape_destroy(to_remove->graphic.plane.rect);
        if (to_remove->graphic.type == TOWER)
            sfCircleShape_destroy(to_remove->graphic.tower.shape);
        sfSprite_destroy(to_remove->graphic.sprite);
        sfTexture_destroy(to_remove->graphic.texture);
        free(to_remove);
    }
}

void entity_destroyer(link_radar_t **begin)
{
    link_radar_t *tmp;
    link_radar_t *to_remove = NULL;

    null_list(begin, to_remove);
    tmp = (*begin);
    while (tmp != NULL && tmp->next != NULL) {
        to_remove = tmp->next;
        tmp->next = tmp->next->next;
        if (to_remove->graphic.type == PLANE)
            sfRectangleShape_destroy(to_remove->graphic.plane.rect);
        if (to_remove->graphic.type == TOWER)
            sfCircleShape_destroy(to_remove->graphic.tower.shape);
        sfSprite_destroy(to_remove->graphic.sprite);
        sfTexture_destroy(to_remove->graphic.texture);
        free(to_remove);
    }
}
