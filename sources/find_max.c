/*
** EPITECH PROJECT, 2021
** find_max
** File description:
** returns int* containing value of biggest square with his position x y
*/

#include <stdlib.h>
#include "../include/bsq.h"

int *set_max(void)
{
    int *max = malloc(sizeof(int) * 3);

    max[0] = 0;
    max[1] = 0;
    max[2] = 0;
    return max;
}

void replace(int **map, int *max, int y, int x)
{
    int min = map[y - 1][x - 1];

    if (map[y][x] == 0)
        min = -1;
    if (map[y][x - 1] < min && min != -1)
        min = map[y][x - 1];
    if (map[y - 1][x] < min && min != -1)
        min = map[y - 1][x];
    if (max[0] < min + 1) {
        max[0] = min + 1;
        max[1] = y;
        max[2] = x;
    }
    map[y][x] = min + 1;
    return;
}

void free_map(int **map, int lines)
{
    for (int i = 0; i != lines; i++)
        free(map[i]);
    free(map);
    return;
}

int *find_max(char **buffer)
{
    int l = my_getnbr(buffer[0]);
    int *max = set_max();
    int **map = set_map(buffer, l);

    if (map[0][0] == -1) {
        free_map(map, l);
        max[0] = -1;
        return (max);
    }
    for (int y = 1, min = map[0][0], c = get_columns(buffer[0]); y != l; y++) {
        for (int x = 1; x != c; x++, min = map[y - 1][x - 1])
            replace(map, max, y, x);
        free(map[y - 1]);
    }
    free(map[l - 1]);
    free(map);
    return (max);
}
