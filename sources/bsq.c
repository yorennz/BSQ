/*
** EPITECH PROJECT, 2021
** bsq project
** File description:
** returns bigger square in a map given
*/

#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/bsq.h"

void do_bsq(char *buffer, int *max, int columns)
{
    for (int i = 0, corner = max[2] + columns * max[1]; i != max[0]; i++) {
        for (int j = 0, pos = corner; j != max[0]; j++, pos -= 1)
            buffer[pos] = 'x';
        corner -= columns;
    }
    return;
}

int bsq(char *buffer, int size)
{
    int lines = my_getnbr(buffer);
    int start = get_start(buffer);
    int *max = find_max(&buffer);
    int columns = get_columns(buffer) + 1;

    if (lines == 1) {
        if (buffer[0] == '.')
            buffer[0] = 'x';
    } else
        do_bsq(buffer, max, columns);
    write(1, buffer, size - start);
    free(max);
    return 0;
}

int main(int ac, char **av)
{
    struct stat bytes;
    int fd = open(av[1], O_RDONLY);
    int size;
    char *buffer;

    stat(av[1], &bytes);
    size = bytes.st_size;
    if (error_handling(ac, fd, size, S_ISDIR(bytes.st_mode)) == 84)
        return 84;
    buffer = set_buffer(fd, size);
    if (error_handling2(buffer) == 84)
        return 84;
    if (bsq(buffer, size) == -1) {
        free(buffer);
        return perror();
    }
    free(buffer);
    return 0;
}
