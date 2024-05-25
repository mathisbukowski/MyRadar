/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** radar.h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef RADAR_H
    #define RADAR_H

typedef struct plane_s {
    sfVector2f pos_departure;
    sfVector2f pos_arrived;
    sfVector2f current_pos;
    float plane_speed;
    float plane_delay;
    sfRectangleShape *rect;
    int collapsed;
    int is_in_tower;
    int rect_visible;
    int plane_visible;
    int is_enabled;
    sfFloatRect bounds;
} plane_t;

typedef struct tower_s {
    sfVector2f pos;
    float radius;
    sfCircleShape *shape;
    int shape_visible;
    int tower_visible;
    sfVector2f scale;
    sfVector2f new_pos;
} tower_t;

enum type_s {
    PLANE, TOWER
};

typedef struct coords_s {
    float vel;
    float distanceX;
    float distanceY;
    float distance;
} coords_t;

typedef struct graphic_s {
    sfSprite *sprite;
    sfTexture *texture;
    enum type_s type;
    tower_t tower;
    plane_t plane;
} graphic_t;

typedef struct link_radar_s {
    graphic_t graphic;
    struct link_radar_s *next;
} link_radar_t;

typedef struct radar_s {
    link_radar_t *entities;
    sfClock *clock;
    sfClock *timer;
    sfText *timer_text;
    sfFont *timer_font;
    char *timer_str;
    sfSprite *map_sprite;
    sfTexture *map_texture;
    sfRenderWindow *window;
    sfTime lastFrame;
    sfClock *delay;
} radar_t;

int radar_loop(radar_t *radar, char *file);
void display_event(radar_t *radar);
void create_background(radar_t *radar);
int extract_data(radar_t *radar, char *file);
void create_entity(enum type_s EntityType, char *line, radar_t *radar);
void init_list(radar_t *radar);
void free_array(char **array);
int check_texture(sfSprite *sprite, sfTexture *texture);
void entity_displayer(radar_t *radar);
void entity_destroyer(link_radar_t **begin);
sfCircleShape *create_circle_entity(graphic_t *newEntity, float radius);
sfRectangleShape *create_rectangle_entity(graphic_t *newEntity);
void entity_move(link_radar_t *head, radar_t *radar);
float calculate_distance(float x, float y);
sfFloatRect my_getglobalbounds(sfRectangleShape *shape);
void detect_collisions(link_radar_t *head);
void create_timer(radar_t *radar);
void destroy_window(radar_t *radar);
void check_end(link_radar_t *head, radar_t *radar);
void close_window(radar_t *radar);
void is_in_tower_area(plane_t *plane, tower_t *tower);
int my_circleglobalbounds(sfCircleShape *circle, sfRectangleShape *rect);
#endif //RADAR_H
