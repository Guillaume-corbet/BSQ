/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** task05
*/

#include "./my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int counter = 0;
    int stock = 0;
    int stock2 = 0;

    while (s1[counter] != '\0') {
        stock = stock + s1[counter];
        counter++;
    }
    counter = 0;
    while (s2[counter] != '\0') {
        stock2 = stock2 + s2[counter];
        counter++;
    }
    if (stock > stock2) {
        return (1);
    } else if (stock < stock2) {
        return (-1);
    } else {
        return (0);
    }
}
