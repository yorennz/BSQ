/*
** EPITECH PROJECT, 2021
** get_columns
** File description:
** returns int representing amount of columns in a map given
*/

int get_columns(char *buffer)
{
    int columns = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        columns++;
    return columns;
}
