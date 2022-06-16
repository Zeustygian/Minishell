/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** draw_array
*/

#include "my.h"

void draw_array(char **array)
{
    if (array == NULL || my_array_len(array) == 0) {
        my_putstr("Empty array.\n");
        return;
    }
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr("array[");
        my_put_nbr(i);
        my_putstr("] = \"");
        my_putstr(array[i]);
        my_putstr("\"\n");
    }
}
