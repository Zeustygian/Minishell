/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** str_contain_char
*/

#include <stdio.h>
#include "my.h"

int str_contain_char(char *str, char c)
{
    if (str == NULL || my_strlen(str) == 0)
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return 0;
        }
    }
    return 1;
}
