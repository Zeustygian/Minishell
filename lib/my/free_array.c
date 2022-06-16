/*
** EPITECH PROJECT, 2022
** B-CPE-210-RUN-2-1-stumper6-lucas.gangnant
** File description:
** free_array
*/

#include "my.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        MY_FREE(array[i]);
    }
    MY_FREE(array);
}
