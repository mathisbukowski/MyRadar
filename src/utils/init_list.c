/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** init_list.c
*/

#include "../../include/my_printf.h"
#include "../../include/my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include <stdlib.h>

void init_list(radar_t *radar)
{
    sfVideoMode dimensions = {1920, 1080, 32};
    char *title = "My_Radar";

    radar->window = sfRenderWindow_create(dimensions, title,
    sfResize | sfClose, NULL);
    if (!radar->window)
        return;
    radar->entities = NULL;
    radar->clock = sfClock_create();
    radar->timer = sfClock_create();
    radar->timer_font = sfFont_createFromFile("assets/background/roboto.ttf");
    radar->timer_text = sfText_create();
    radar->timer_str = NULL;
    radar->delay = sfClock_create();
    sfRenderWindow_setFramerateLimit(radar->window, 90);
}
