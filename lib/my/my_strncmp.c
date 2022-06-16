/*
** EPITECH PROJECT, 2021
** B-BOO-101-RUN-1-1-phoenixd02-lucas.gangnant
** File description:
** my_strncmp
*/

#include <stdio.h>
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (s1 == NULL || s2 == NULL
        || my_strlen(s1) == 0 || my_strlen(s2) == 0)
        return -1;
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] != s2[i])
            return -1;
    }
    return (0);
}
