/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** create_background.c
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include "../../include/my.h"
#include "../../include/my_printf.h"

void check_texture_bg(radar_t *radar, sfVector2u windowSize,
    sfVector2u backSize)
{
    sfVector2f scale = {0.f, 0.f};

    if (radar->map_texture) {
        backSize = sfTexture_getSize(radar->map_texture);
        sfSprite_setTexture(radar->map_sprite, radar->map_texture, sfTrue);
        if (backSize.x != 0 && backSize.y != 0) {
            scale.x = (float)windowSize.x / (float)backSize.x;
            scale.y = (float)windowSize.y / (float)backSize.y;
            sfSprite_setScale(radar->map_sprite, scale);
        } else {
            my_printf("Error: Incorrect Size\n");
            return;
        }
    } else {
        my_printf("Error: background not found.\n");
        return;
    }
}

void create_background(radar_t *radar)
{
    sfVector2u windowSize = sfRenderWindow_getSize(radar->window);
    sfVector2u backSize = {0, 0};

    radar->map_sprite = sfSprite_create();
    radar->map_texture =
        sfTexture_createFromFile("assets/background/background.jpg", NULL);
    check_texture_bg(radar, windowSize, backSize);
}
