/*
** EPITECH PROJECT, 2021
** error_handling
** File description:
** returns 84 if error detected
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../include/bsq.h"

int perror(void)
{
    write(1, "error\n", 6);
    return 84;
}

int error_handling2(char *buffer)
{
    if (my_getnbr(buffer) <= 0)
        return perror();
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            return 0;
        if (!(buffer[i] >= '0' && buffer[i] <= '9'))
            return perror();
    }
    return perror();
}

int error_flags(int ac, int fd, int size, int is_dir)
{
    if (ac != 2)
        return 84;
    if (fd <= 0)
        return 84;
    if (size == 0)
        return 84;
    if (is_dir == 1)
        return 84;
    return 0;
}

int error_handling(int ac, int fd, int size, int is_dir)
{
    if (error_flags(ac, fd, size, is_dir) == 84)
        return perror();
    return 0;
}
