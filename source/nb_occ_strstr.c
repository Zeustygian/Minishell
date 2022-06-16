/*
** EPITECH PROJECT, 2021
** B-BOO-101-RUN-1-1-phoenixd02-lucas.gangnant
** File description:
** find nb of occurences of a string into another one
*/

#include <stdio.h>
#include "my.h"
#include "my_minishell.h"

void occ_condition_1(char *str, int *i, char *to_find, int *j)
{
    while (str[*i + 1] == to_find[*j + 1]) {
        (*i)++;
        (*j)++;
    }
}

void occ_condition_2(char *str, int *i, char *to_find, int *j)
{
    if (to_find[*j + 1] == '\0')
        str = str + (*i - *j);
}

int nb_occ_strstr(char *str, char *to_find)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == to_find[j]) {
            occ_condition_1(str, &i, to_find, &j);
            occ_condition_2(str, &i, to_find, &j);
            count++;
        }
        i++;
    }
    return count;
}
