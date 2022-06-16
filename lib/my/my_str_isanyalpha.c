/*
** EPITECH PROJECT, 2022
** stumper
** File description:
** my_str_isanyalpha
*/

#include "my.h"

int my_str_isanyalpha(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= 'A' && str[i] <= 'Z'))
            i++;
        else
            return 1;
    }
    return 0;
}
