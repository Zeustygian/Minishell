/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** my_str_is_alphanum
*/

#include "my.h"

int my_str_is_alphanum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= 'A' && str[i] <= 'Z')
        || (str[i] >= '0' && str[i] <= '9'))
            i++;
        else
            return 1;
    }
    return 0;
}
