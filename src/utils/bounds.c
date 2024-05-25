/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** bounds.c
*/

#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include <stdlib.h>
#include <math.h>


sfFloatRect my_getlocalbounds(sfRectangleShape *rect)
{
    sfVector2f rect_size = sfRectangleShape_getSize(rect);
    float width = rect_size.x;
    float height = rect_size.y;
    sfFloatRect local_bounds = {0.f, 0.f, width, height};

    return local_bounds;
}

sfFloatRect my_getglobalbounds(sfRectangleShape *rect)
{
    sfTransform transform = sfRectangleShape_getTransform(rect);
    sfFloatRect bounds = my_getlocalbounds(rect);
    sfFloatRect transformed_rect =
    sfTransform_transformRect(&transform, bounds);

    return transformed_rect;
}

static int is_point_inside(sfCircleShape *circle, sfVector2f *v)
{
    float dx;
    float dy;
    float diam;
    int result;
    sfVector2f center = {sfCircleShape_getPosition(circle).x +
    sfCircleShape_getRadius(circle),
    sfCircleShape_getPosition(circle).y + sfCircleShape_getRadius(circle)};

    dx = (v->x - center.x);
    dy = (v->y - center.y);
    diam = powf(sfCircleShape_getRadius(circle), 2);
    dx = powf(dx, 2);
    dy = powf(dy, 2);
    result = ((dx + dy) < diam);
    return result;
}

int my_circleglobalbounds(sfCircleShape *circle, sfRectangleShape *rect)
{
    sfFloatRect bounds = my_getglobalbounds(rect);
    sfVector2f tl = {bounds.left, bounds.top};
    sfVector2f tr = {bounds.left + bounds.width, bounds.top};
    sfVector2f bl = {bounds.left, bounds.top + bounds.height};
    sfVector2f br = {bounds.left + bounds.width, bounds.top +
    bounds.height};
    int result = is_point_inside(circle, &tl) ||
    is_point_inside(circle, &tr) ||
    is_point_inside(circle, &bl) ||
    is_point_inside(circle, &br);

    return result;
}
