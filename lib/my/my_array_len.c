/*
** EPITECH PROJECT, 2022
** B-PSU-200-RUN-2-1-tetris-lucas.gangnant
** File description:
** my_array_len
*/

#include "my.h"

int my_array_len(char **array)
{
    int i = 0;

    if (array == NULL) {
        return 0;
    }
    for (; array[i] != NULL; i++);
    return (i);
}
