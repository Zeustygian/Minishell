/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** my_strdup_array_rep_key
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

char **dup_arr_repkey(env_t *env_cpy, char **arr_cpy, char *key, char **input)
{
    int i = 0;
    int index_key = my_getenv_index(input[1], env_cpy);

    while (env_cpy->env_copy[i] != NULL) {
        if (i == index_key) {
            arr_cpy[i] = my_strdup(key);
        } else {
            arr_cpy[i] = my_strdup(env_cpy->env_copy[i]);
        }
        i++;
    }
    arr_cpy[i] = NULL;
    return arr_cpy;
}
