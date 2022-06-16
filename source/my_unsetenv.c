/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** my_unsetenv
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

void just_free_copy (env_t *env_cpy)
{
    if (env_cpy->env_copy != NULL)
        MY_FREE(env_cpy->env_copy);
}

int my_unsetenv(env_t *env_cpy, char **input)
{
    char **new_env = NULL;
    char *key = NULL;

    if (input[1] == NULL) {
        my_putstr_err("unsetenv: Too few arguments.\n");
        return 84;
    }
    for (int i = 1; input[i] != NULL; i++) {
        if (check_key_existence(input[i], env_cpy) == true) {
            key = str_concat(input[i], "=");
            new_env = delete_key(env_cpy, key);
            just_free_copy(env_cpy);
            env_cpy->env_copy = new_env;
        }
    }
    if (check_key_existence(input[1], env_cpy) == false)
        return 84;
    return 0;
}
