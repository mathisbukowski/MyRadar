/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** init_shape.c
*/

#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include <stdlib.h>

sfRectangleShape *create_rectangle_entity(graphic_t *newEntity)
{
    sfRectangleShape *rec = sfRectangleShape_create();
    sfVector2f size = {20, 20};
    sfVector2f origin = {0, 0};

    sfRectangleShape_setSize(rec, size);
    sfRectangleShape_setOutlineThickness(rec, 2);
    sfRectangleShape_setOutlineColor(rec, sfCyan);
    sfRectangleShape_setTexture(rec, newEntity->texture, sfTrue);
    sfRectangleShape_setFillColor(rec, sfTransparent);
    sfRectangleShape_setOrigin(rec, origin);
    sfRectangleShape_setPosition(rec, newEntity->plane.pos_departure);
    return (rec);
}

sfCircleShape *create_circle_entity(graphic_t *newEntity, float radius)
{
    sfCircleShape *shape = sfCircleShape_create();
    float result = radius * 10;
    sfVector2u size = sfTexture_getSize(
    sfSprite_getTexture(newEntity->sprite));
    sfVector2f origin = {((float)size.x * newEntity->tower.scale.x) / 2,
    ((float)size.y * newEntity->tower.scale.y) / 2};

    newEntity->tower.new_pos = (sfVector2f){
    (newEntity->tower.pos.x + origin.x - result),
    (newEntity->tower.pos.y + origin.y - result)};
    sfCircleShape_setFillColor(shape, sfTransparent);
    sfCircleShape_setOutlineThickness(shape, 2);
    sfCircleShape_setOutlineColor(shape, sfGreen);
    sfCircleShape_setPosition(shape, newEntity->tower.new_pos);
    sfCircleShape_setRadius(shape, result);
    return (shape);
}
