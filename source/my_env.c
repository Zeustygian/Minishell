/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** my_env
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

int my_env(env_t *env_cpy)
{
    for (int i = 0; env_cpy->env_copy[i] != NULL; i++) {
        my_putstr(env_cpy->env_copy[i]);
        my_putstr("\n");
    }
    return 0;
}
