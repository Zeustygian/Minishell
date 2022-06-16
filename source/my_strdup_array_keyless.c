/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** my_strdup_array_keyless
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

char **my_strdup_array_keyless(env_t *env_cpy, char **arr_cpy, char *key)
{
    int i = 0;
    int j = 0;

    while (env_cpy->env_copy[i] != NULL) {
        if (my_strncmp(env_cpy->env_copy[i], key, my_strlen(key)) == 0) {
            i++;
            j++;
            continue;
        }
        arr_cpy[i - j] = my_strdup(env_cpy->env_copy[i]);
        i++;
    }
    arr_cpy[i - j] = NULL;
    return arr_cpy;
}
