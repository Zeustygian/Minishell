/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** replace_key
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

char **replace_key(env_t *env_cpy, char *key, char **input)
{
    int nb_line_array = my_array_len(env_cpy->env_copy);
    char **new_env_copy = malloc(sizeof(char *) * (nb_line_array));

    new_env_copy = dup_arr_repkey(env_cpy, new_env_copy, key, input);
    new_env_copy[nb_line_array] = NULL;
    return new_env_copy;
}
