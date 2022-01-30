/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** stock
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./../lib/my/my.h"

int number_of_line(char *filepath)
{
    int fd = 0;
    char charac = 96;
    char *str;
    int i = 0;
    int size = 0;

    str = malloc(sizeof(char) * 11);
    fd = open(filepath, O_RDONLY);
    while (charac != '\n' && charac != '\0') {
        read(fd, &charac, 1);
        str[i] = charac;
        i = i + 1;
    }
    size = my_getnbr(str);
    close(fd);
    return (size);
}

int number_of_columns(char *filepath)
{
    int fd = 0;
    char charac = 96;
    int size = 0;

    fd = open(filepath, O_RDONLY);
    while (charac != '\n' && charac != '\0') {
        read(fd, &charac, 1);
    }
    read(fd, &charac, 1);
    while (charac != '\n') {
        read(fd, &charac, 1);
        size = size + 1;
    }
    close(fd);
    return (size);
}