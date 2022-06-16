/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** my_setenv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

int my_setenv_error_case(char **input, env_t *env_cpy)
{
    if (input[1] == NULL) {
        my_env(env_cpy);
        return 84;
    }
    for (int p = 0; input[p] != NULL; p++) {
        if (p >= 3) {
            my_putstr_err("setenv: Too many arguments.\n");
            return 84;
        }
    }
    if (is_alpha(input[1][0]) != 0) {
        my_putstr_err("setenv: Variable name must begin with a letter.\n");
        return 84;
    }
    if (my_str_is_alphanum(input[1]) != 0) {
        my_putstr_err("setenv: Variable name must contain ");
        my_putstr_err("alphanumeric characters.\n");
        return 84;
    }
    return 0;
}

char **append_to_array(char **array, char *str)
{
    int len = my_array_len(array);
    char **new_array = malloc(sizeof(char *) * (len + 2));

    for (size_t i = 0; array && array[i]; i++)
        new_array[i] = my_strdup(array[i]);
    new_array[len] = my_strdup(str);
    new_array[len + 1] = NULL;
    return new_array;
}

int my_setenv(env_t *env_cpy, char **input)
{
    int index = 0;
    char *new_var = NULL;

    if (my_setenv_error_case(input, env_cpy) == 84)
        return 84;
    index = my_getenv_index(input[1], env_cpy);
    new_var = my_strdup(input[1]);
    new_var = str_concat(new_var, "=");
    if (my_array_len(input) > 2)
        new_var = str_concat(new_var, input[2]);
    if (index == -1)
        env_cpy->env_copy = append_to_array(env_cpy->env_copy, new_var);
    else
        env_cpy->env_copy[index] = new_var;
    return 0;
}
