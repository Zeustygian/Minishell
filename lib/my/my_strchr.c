/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** my_strchr
*/

#include <stdio.h>
#include "my.h"

char *my_strchr(char *str, char to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find) {
            return &str[i];
        }
    }
    return NULL;
}
