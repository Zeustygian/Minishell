/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** append_arr_to_arr
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

char **append_arr_to_arr(char **arr_dest, char **arr_src)
{
    (void)arr_dest;
    char **new_array = NULL;

    for (int i = 0; arr_src[i] != NULL; i++)
        new_array = append_to_array(new_array, arr_src[i]);
    return new_array;
}
