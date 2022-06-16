/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** check_key_existence
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

bool check_key_existence(char *name_value, env_t *env_cpy)
{
    for (int i = 0; env_cpy->env_copy[i] != NULL; i++) {
        if (my_strncmp(name_value, env_cpy->env_copy[i],
            getenv_name_len(env_cpy->env_copy[i])) == 0)
            return true;
    }
    return false;
}
