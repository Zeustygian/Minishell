/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** my_getenv
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

char *my_getenv(char *name, env_t *env_cpy)
{
    char *value = "something went wrong\n";
    char **name_value = NULL;
    char *name_env = str_concat(name, "=");
    int len_name_env = my_strlen(name_env);

    for (int i = 0; env_cpy->env_copy[i] != NULL; i++) {
        if (my_strncmp(name_env, env_cpy->env_copy[i], len_name_env) == 0) {
            name_value = my_split(env_cpy->env_copy[i], "=");
            return name_value[1];
        }
    }
    return value;
}
