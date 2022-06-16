/*
** EPITECH PROJECT, 2021
** my_str_isnum.c
** File description:
** oui
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
            i++;
        else
            return 1;
    }
    return 0;
}
