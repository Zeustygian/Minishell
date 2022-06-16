/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** my_getenv_index
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

int my_getenv_index(char *name, env_t *env_cpy)
{
    char *name_env = str_concat(name, "=");
    int len_name_env = my_strlen(name_env);
    int index = 0;

    for (int i = 0; env_cpy->env_copy[i] != NULL; i++) {
        if (my_strncmp(name_env, env_cpy->env_copy[i], len_name_env) == 0)
            return index;
        index++;
    }
    return -1;
}
