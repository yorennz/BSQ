/*
** EPITECH PROJECT, 2021
** get_start
** File description:
** get_start
*/

int get_start(char *buffer)
{
    int start = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        start += 1;
    return (start + 1);
}
