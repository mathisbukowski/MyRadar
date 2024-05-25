/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** main.c
*/

#include "../include/my_printf.h"
#include "../include/my.h"
#include "../include/radar.h"
#include <stdlib.h>
#include <string.h>

int help(void)
{
    my_putstr("Air traffic simulation panel\n");
    my_putstr("USAGE\n");
    my_putstr("./my_radar [OPTIONS] path_to_script\n");
    my_putstr("path_to_script The path to the script file.\n");
    my_putstr("OPTIONS\n");
    my_putstr("-h print the usage and quit.\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("‘L’ key enable/disable hitboxes and areas.\n");
    my_putstr("‘S’ key enable/disable sprites.\n");
    return 0;
}

int print_help(char *str)
{
    if (str[0] == '-')
        if (str[1] == 'h'){
            help();
            return (1);
        }
    return 0;
}

int check_tty(char **env)
{
    for (char **current_env = env; *current_env != NULL; ++current_env) {
        if (my_strncmp(*current_env, "DISPLAY", my_strlen("DISPLAY")) == 0)
            return 0;
    }
    return 1;
}

int main(int ac, char **av, char **env)
{
    radar_t *radar = malloc(sizeof(radar_t));
    int indicator = check_tty(env);

    if (indicator != 0)
        return 84;
    if (ac != 2) {
        my_putstr("./my_radar: bad arguments: 0 given but 84 is required\n");
        my_putstr("retry with -h\n");
        return (84);
    }
    if (print_help(av[1]) == 1)
        return (0);
    init_list(radar);
    if (radar_loop(radar, av[1]) != 0)
        return (84);
    free(radar);
    return (0);
}
