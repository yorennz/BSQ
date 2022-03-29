/*
** EPITECH PROJECT, 2021
** set_map
** File description:
** returns int** that represent the map replacing '.' by 1 and 'o' by 0
*/

#include <stdlib.h>
#include "../include/bsq.h"

int **malloc_lines(char **buffer, int lines)
{
    int **map;
    int start = 0;
    int columns;

    for (int i = 0; buffer[0][i] != '\n' && buffer[0][i] != '\0'; i++)
        start += 1;
    buffer[0] += (start + 1);
    map = malloc(sizeof(int*) * lines);
    columns = get_columns(buffer[0]);
    for (int k = 0; k != lines; k++)
        map[k] = malloc(sizeof(int) * columns);
    map[0][0] = -1;
    return (map);
}

int *set_p_array(char *buffer)
{
    int *p = malloc(sizeof(int) * 4);

    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = get_columns(buffer);
    return p;
}

int set_pos(int val, int *p)
{
    p[1]++;
    return (val);
}

int **replace_map(int **map, char **buffer, int *p, int lines)
{
    if (p[1] == p[3] && buffer[0][p[2]] != '\n') {
        map[0][0] = -1;
        return map;
    }
    if (buffer[0][p[2]] == '\n' && p[1] < p[3]) {
        map[0][0] = -1;
        return map;
    }
    if (buffer[0][p[2]] == '.')
        map[p[0]][p[1]] = set_pos(1, p);
    if (buffer[0][p[2]] == 'o')
        map[p[0]][p[1]] = set_pos(0, p);
    if (buffer[0][p[2]] == '\n') {
        p[1] = 0;
        p[0] += 1;
    } else if (buffer[0][p[2]] != 'o' && buffer[0][p[2]] != '.' ) {
        map[0][0] = -1;
        return map;
    }
}

int **set_map(char **buffer, int lines)
{
    int **map = malloc_lines(buffer, lines);
    int *p = set_p_array(buffer[0]);

    if (buffer[0][0] != '.' && buffer[0][0] != 'o') {
        free(p);
        return (map);
    }
    if (lines == 1)
        return (one_line(map, buffer));
    for (; buffer[0][p[2]] != '\0' && p[0] < lines; p[2]++) {
        replace_map(map, buffer, p, lines);
        if (map[0][0] == -1) {
            free(p);
            return map;
        }
    }
    if (p[0] != lines || p[0] == lines && buffer[0][p[2]] != '\0')
        map[0][0] = -1;
    free(p);
    return (map);
}
