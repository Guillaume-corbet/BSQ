/*
** EPITECH PROJECT, 2018
** BSQ
** File description:
** bootstrap bsq
*/

#include "./../lib/my/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./../include/main.h"
#include "./../include/stock.h"

char *stock(char *filepath, bsqstr_t *test)
{
    char *str;
    int fd = 0;
    char charac = 96;
    int i = 0;
    int j = 0;

    fd = open(filepath, O_RDONLY);
    while (charac != '\n') {
        read(fd, &charac, 1);
    }
    j = (test->columns + 1) * test->line;
    str = malloc(sizeof(char) * (j));
    read(fd, str, j);
    close(fd);
    return (str);
}

int search(char *str, int i, bsqstr_t *test)
{
    int a = i;

    test->x = 0;
    test->y = 0;
    while (test->y < test->max + 1) {
        while (test->x < test->max + 1) {
            if (str[i] == '.') {
                i = i + 1;
                test->x = test->x + 1;
            } else {
                return (-1);
            }
        }
        test->x = 0;
        i = i + test->columns - test->max;
        test->y = test->y + 1;
    }
    test->stock = a;
    return (1);
}

int bsq(char *str, bsqstr_t *test)
{
    int i = 0;

    test->max = 0;
    test->now = 0;
    while (str[i] != '\0') {
        if (str[i] == '.') {
            test->now = search(str, i, test);
            if (test->now != -1)
                test->max = test->max + 1;
            else
                i = i + 1;
        }
        while (str[i] != '.' && str[i] != '\0')
            i = i + 1;
    }
    return (test->max);
}

void display_bsq(char *str, bsqstr_t *test)
{
    int i = 0;

    i = test->stock;
    test->y = 0;
    test->x = 0;
    while (test->y != test->max) {
        while (test->x != test->max) {
            str[i] = 'x';
            i = i + 1;
            test->x = test->x + 1;
        }
        test->x = 0;
        i = i + test->columns - test->max + 1;
        test->y = test->y +1;
    }
    str[(test->columns + 1) * test->line] = '\0';
    my_putstr(str);
}

int main(int argc, char **argv)
{
    char *str;
    int all = 0;
    int i = 0;
    bsqstr_t *test;
    struct stat sb;

    stat(argv[1], &sb);
    if (argc != 2 || sb.st_size== 0)
        return (84);
    test->stock = 0;
    test = malloc(sizeof(bsqstr_t));
    str = argv[1];
    test->line = number_of_line(argv[1]);
    test->columns = number_of_columns(argv[1]);
    str = malloc(sizeof(char) * test->line * (test->columns + 1));
    my_strcpy(str, stock(argv[1], test));
    bsq(str, test);
    display_bsq(str, test);
    free;
    return (0);
}
