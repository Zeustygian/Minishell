/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** delete key from env copy
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

char **delete_key(env_t *env_cpy, char *key)
{
    int nb_line_array = count_nb_lines_array(env_cpy->env_copy);
    char **new_env_copy = malloc(sizeof(char *) * nb_line_array);

    new_env_copy = my_strdup_array_keyless(env_cpy, new_env_copy, key);
    new_env_copy[nb_line_array - 1] = NULL;
    return new_env_copy;
}
