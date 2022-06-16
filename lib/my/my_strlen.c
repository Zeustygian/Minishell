/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** display a string
*/

#include "my.h"

int my_strlen(char const *str)
{
    ssize_t i = 0;

    if (str == NULL)
        return -1;
    for (; str[i] != '\0'; i++);
    return i;
}
