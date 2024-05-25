/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** create_timer.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "../../include/radar.h"
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>

void foo(char *result, int start, int end, char temp)
{
    while (start < end) {
        temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
}

void int_to_string(int num, char *result)
{
    int index = 0;
    int digit;
    int start = 0;
    int end;
    char temp;

    if (num == 0){
        result[index] = '0';
        index += 1;
    }
    while (num > 0) {
        digit = num % 10;
        result[index] = digit + '0';
        index += 1;
        num /= 10;
    }
    result[index] = '\0';
    end = index - 1;
    foo(result, start, end, temp);
    result[index] = '\0';
}

void check_text(radar_t *radar)
{
    if (!(radar->timer_font))
        return;
    else
        sfText_setFont(radar->timer_text, radar->timer_font);
}

void create_timer(radar_t *radar)
{
    sfTime elapsed = sfClock_getElapsedTime(radar->timer);
    float seconds = sfTime_asSeconds(elapsed);
    char result[100];

    int_to_string(seconds, result);
    check_text(radar);
    sfText_setCharacterSize(radar->timer_text, 36);
    sfText_setString(radar->timer_text, result);
    sfText_setColor(radar->timer_text, sfYellow);
    sfText_setPosition(radar->timer_text, (sfVector2f){1850, 0});
}
