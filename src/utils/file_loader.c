/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** file_loader.c
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "../../include/radar.h"
#include "../../include/my_printf.h"
#include "../../include/my.h"

int check_line_plane(char **args)
{
    if (args[0][0] == 'A') {
        if (args[1] == NULL || (my_str_isnum(args[1])) != 1)
            return 1;
        if (args[2] == NULL || (my_str_isnum(args[2])) != 1)
            return 1;
        if (args[3] == NULL || (my_str_isnum(args[3])) != 1)
            return 1;
        if (args[4] == NULL || (my_str_isnum(args[4])) != 1)
            return 1;
        if (args[5] == NULL || (my_str_isnum(args[5])) != 1)
            return 1;
        if (args[6] == NULL || (my_str_isnum(args[6])) != 1)
            return 1;
        if (args[7])
            return 1;
    }
    return 0;
}

int check_map(char *line)
{
    char **args = my_str_to_word_array(line, " ");

    if (args[0][0] != 'A' && args[0][0] != 'T')
        return 1;
    if (args[0][0] == 'T') {
        if (args[1] == NULL || (my_str_isnum(args[1])) != 1)
            return 1;
        if (args[2] == NULL || (my_str_isnum(args[2])) != 1)
            return 1;
        if (args[3] == NULL || (my_str_isnum(args[3])) != 1)
            return 1;
        if (args[4])
            return 1;
    }
    if ((check_line_plane(args)) != 0)
        return 1;
    free_array(args);
    return 0;
}

char *info_loader(char const *file)
{
    struct stat sb;
    int fd = open(file, O_RDONLY);
    char *radar_info = NULL;
    size_t size;

    if (fd == -1)
        return NULL;
    if (stat(file, &sb) == -1) {
        my_printf("Error: obtaining infos.");
        close(fd);
        return NULL;
    }
    size = sb.st_size;
    radar_info = (char *)malloc((size + 1) * sizeof(char));
    read(fd, radar_info, size);
    radar_info[size] = '\0';
    close(fd);
    return radar_info;
}

int extract_data(radar_t *radar, char *file)
{
    char *radar_info = info_loader(file);
    char **infos;

    if (radar_info == NULL)
        return 1;
    else
        infos = my_str_to_word_array(radar_info, "\n");
    for (int i = 0; infos[i] != NULL; i++) {
        if ((check_map(infos[i])) != 0)
            return 1;
        if (infos[i][0] == 'A')
            create_entity(PLANE, infos[i], radar);
        if (infos[i][0] == 'T')
            create_entity(TOWER, infos[i], radar);
    }
    free_array(infos);
    free(radar_info);
    return 0;
}
