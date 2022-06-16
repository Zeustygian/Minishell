/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** create_new_khey
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

char **create_new_key(env_t *env_cpy, char *new_key)
{
    int nb_line_array = count_nb_lines_array(env_cpy->env_copy);
    int len_new_env = nb_line_array + 1;
    char **new_env_copy = malloc(sizeof(char *) * (len_new_env + 1));

    new_env_copy = my_strdup_array(env_cpy->env_copy, new_env_copy);
    new_env_copy[len_new_env - 1] = my_strdup(new_key);
    new_env_copy[len_new_env] = NULL;
    return new_env_copy;
}
