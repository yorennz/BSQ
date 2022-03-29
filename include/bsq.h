/*
** EPITECH PROJECT, 2021
** bsq.h
** File description:
** write all proto's needed by bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_

int perror(void);
int get_start(char *buffer);
char *set_buffer(int fd, int size);
int my_getnbr(char const *str);
int error_handling2(char *buffer);
int error_handling(int ac, int fd, int size, int is_dir);
int **one_line(int **map, char **buffer);
int **set_map(char **buffer, int lines);
int *find_max(char **buffer);
int get_columns(char *buffer);
#endif
