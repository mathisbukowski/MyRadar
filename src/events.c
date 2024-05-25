/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** events.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/radar.h"
#include "../include/my_printf.h"

void close_window(radar_t *radar)
{
    sfRenderWindow_close(radar->window);
}

static void disp_sprite_type(link_radar_t *current)
{
    if (current->graphic.type == PLANE) {
        if (current->graphic.plane.plane_visible == 1) {
            current->graphic.plane.plane_visible = 0;
        } else {
            current->graphic.plane.plane_visible = 1;
        }
    }
    if (current->graphic.type == TOWER) {
        if (current->graphic.tower.tower_visible == 1) {
            current->graphic.tower.tower_visible = 0;
        } else {
            current->graphic.tower.tower_visible = 1;
        }
    }
}

void display_sprite(link_radar_t *head)
{
    link_radar_t *current = head;

    while (current != NULL) {
        disp_sprite_type(current);
        current = current->next;
    }
}

static void disp_shape_type(link_radar_t *current)
{
    if (current->graphic.type == PLANE) {
        if (current->graphic.plane.rect_visible == 1) {
            current->graphic.plane.rect_visible = 0;
        } else {
            current->graphic.plane.rect_visible = 1;
        }
    }
    if (current->graphic.type == TOWER) {
        if (current->graphic.tower.shape_visible == 1) {
            current->graphic.tower.shape_visible = 0;
        } else {
            current->graphic.tower.shape_visible = 1;
        }
    }
}

void display_shape(link_radar_t *head)
{
    link_radar_t *current = head;

    while (current != NULL) {
        disp_shape_type(current);
        current = current->next;
    }
}

void analyse_events(sfEvent event, radar_t *radar)
{
    if (event.type == sfEvtClosed)
        close_window(radar);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        close_window(radar);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
        display_sprite(radar->entities);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
        display_shape(radar->entities);
}

void display_event(radar_t *radar)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(radar->window, &event)) {
        analyse_events(event, radar);
    }
}
