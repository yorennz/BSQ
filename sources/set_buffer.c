/*
** EPITECH PROJECT, 2021
** set_buffer
** File description:
** return buffer with correct malloc and with \0
*/

#include <stdlib.h>
#include <unistd.h>

char *set_buffer(int fd, int size)
{
    char *buffer;

    buffer = malloc(sizeof(char) *(size + 1));
    read(fd, buffer, size);
    buffer[size] = '\0';
    return (buffer);
}
