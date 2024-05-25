/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** radar.c
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../include/radar.h"
#include <stdlib.h>

void destroy_window(radar_t *radar)
{
    entity_destroyer(&(radar->entities));
    radar->entities = NULL;
    sfSprite_destroy(radar->map_sprite);
    sfTexture_destroy(radar->map_texture);
    sfText_destroy(radar->timer_text);
    sfFont_destroy(radar->timer_font);
    sfClock_destroy(radar->timer);
    sfClock_destroy(radar->clock);
    sfClock_destroy(radar->delay);
    sfRenderWindow_destroy(radar->window);
}

void render_screen(radar_t *radar)
{
    sfRenderWindow_clear(radar->window, sfBlack);
    sfRenderWindow_drawSprite(radar->window, radar->map_sprite, NULL);
    sfRenderWindow_drawText(radar->window, radar->timer_text, NULL);
    entity_move(radar->entities, radar);
    detect_collisions(radar->entities);
    entity_displayer(radar);
    check_end(radar->entities, radar);
    sfRenderWindow_display(radar->window);
}

void screen_create(radar_t *radar)
{
    create_background(radar);
    while (sfRenderWindow_isOpen(radar->window)) {
        create_timer(radar);
        radar->lastFrame = sfClock_restart(radar->clock);
        display_event(radar);
        render_screen(radar);
    }
}

int radar_loop(radar_t *radar, char *file)
{
    if (extract_data(radar, file) != 0)
        return 1;
    screen_create(radar);
    destroy_window(radar);
    return 0;
}
