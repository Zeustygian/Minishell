/*
** EPITECH PROJECT, 2022
** stumper
** File description:
** my_str_isalpha
*/

#include "my.h"

int my_str_islowalpha(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
        else
            return 1;
    }
    return 0;
}
