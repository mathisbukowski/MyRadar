/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** entity_creator.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>


void create_plane(graphic_t *newEntity, char *line)
{
    char **args = my_str_to_word_array(line, " ");

    newEntity->plane.pos_departure.x = my_atoi(args[1]);
    newEntity->plane.pos_departure.y = my_atoi(args[2]);
    newEntity->plane.pos_arrived.x = my_atoi(args[3]);
    newEntity->plane.pos_arrived.y = my_atoi(args[4]);
    newEntity->plane.plane_speed = my_atoi(args[5]);
    newEntity->plane.plane_delay = my_atoi(args[6]);
    newEntity->plane.rect = create_rectangle_entity(newEntity);
    newEntity->plane.rect_visible = 1;
    newEntity->plane.plane_visible = 1;
    newEntity->plane.is_enabled = 1;
    newEntity->plane.is_in_tower = 0;
    newEntity->plane.collapsed = 1;
    newEntity->plane.bounds = my_getglobalbounds(newEntity->plane.rect);
    free_array(args);
}

void create_tower(graphic_t *newEntity, char *line)
{
    char **args = my_str_to_word_array(line, " ");

    newEntity->tower.pos.x = my_atoi(args[1]);
    newEntity->tower.pos.y = my_atoi(args[2]);
    newEntity->tower.radius = my_atoi(args[3]);
    newEntity->tower.tower_visible = 1;
    newEntity->tower.shape_visible = 1;
    free_array(args);
}

static void set_pos_scale_plane(graphic_t newEntity)
{
    sfVector2f plane_position;
    sfVector2u originalSize;
    float scaleX;
    float scaleY;
    sfVector2f plane_scale;

    originalSize = sfTexture_getSize(newEntity.texture);
    plane_scale.x = 20.f / originalSize.x;
    plane_scale.y = 20.f / originalSize.y;
    plane_position = (sfVector2f){newEntity.plane.pos_departure.x,
    newEntity.plane.pos_departure.y};
    sfSprite_setPosition(newEntity.sprite, plane_position);
    sfSprite_setScale(newEntity.sprite, plane_scale);
}

static void set_pos_scale_tower(graphic_t *newEntity)
{
    sfVector2f tower_position;
    sfVector2u originalSize;
    float scaleX;
    float scaleY;
    sfVector2f tower_scale;

    originalSize = sfTexture_getSize(newEntity->texture);
    tower_scale.x = 45.f / originalSize.x;
    tower_scale.y = 45.f / originalSize.y;
    tower_position = (sfVector2f){newEntity->tower.pos.x,
    newEntity->tower.pos.y};
    newEntity->tower.scale = tower_scale;
    sfSprite_setPosition(newEntity->sprite, tower_position);
    sfSprite_setScale(newEntity->sprite, tower_scale);
    newEntity->tower.shape = create_circle_entity(newEntity,
    newEntity->tower.radius);
}

sfTexture *create_texture(enum type_s EntityType)
{
    sfTexture *texture = NULL;

    switch (EntityType) {
        case PLANE:
            texture = sfTexture_createFromFile("assets/entities/plane.png",
    NULL);
            break;
        case TOWER:
            texture = sfTexture_createFromFile("assets/entities/tower.png",
    NULL);
            break;
        default:
            my_printf("Error: invalid type.");
    }
    return texture;
}

void add_entity(link_radar_t **begin, graphic_t newEntity)
{
    link_radar_t *new_node = malloc(sizeof(link_radar_t));

    if (!new_node)
        return;
    new_node->graphic = newEntity;
    new_node->next = *begin;
    *begin = new_node;
}

void create_entity(enum type_s EntityType, char *line, radar_t *radar)
{
    graphic_t newEntity;

    newEntity.sprite = sfSprite_create();
    newEntity.texture = create_texture(EntityType);
    if ((check_texture(newEntity.sprite, newEntity.texture)) != 0)
        return;
    sfSprite_setTexture(newEntity.sprite, newEntity.texture, sfTrue);
    newEntity.type = EntityType;
    switch (EntityType) {
        case PLANE:
            create_plane(&newEntity, line);
            set_pos_scale_plane(newEntity);
            break;
        case TOWER:
            create_tower(&newEntity, line);
            set_pos_scale_tower(&newEntity);
            break;
    }
    add_entity(&(radar->entities), newEntity);
}
