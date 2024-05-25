/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** check_texture.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "../../include/radar.h"
#include "../../include/my.h"
#include "../../include/my_printf.h"

int check_texture(sfSprite *sprite, sfTexture *texture)
{
    if (!texture) {
        my_printf("Error: file not found.\n");
        return 1;
    } else {
        sfSprite_setTexture(sprite, texture, sfTrue);
        return 0;
    }
}
