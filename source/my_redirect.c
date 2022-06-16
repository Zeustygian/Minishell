/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** my_redirect
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "my.h"
#include "my_minishell.h"

int error_redirect(char *order_one, char *order_two, int zero_empty)
{
    if (order_one == NULL) {
        my_putstr_err("Missing name for redirect.\n");
        return 84;
    }
    if (zero_empty == 0) {
        my_putstr_err("Invalid null command.\n");
        return 84;
    }
    if (order_two == NULL) {
        my_putstr_err("Missing name for redirect.\n");
        return 84;
    }
    return 0;
}

int my_redirect(char *order_one, char *order_two, env_t *env_cpy,
                int zero_empty)
{
    char **arr_one = NULL;
    char **arr_two = NULL;
    int fd = 0;
    int file = 0;

    if (error_redirect(order_one, order_two, zero_empty) == 84)
        return 84;
    arr_one = my_split(order_one, " \t");
    arr_two = my_split(order_two, " \t");
    fd = dup(STDOUT_FILENO);
    file = open(arr_two[0], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    dup2(file, STDOUT_FILENO);
    part_one_builtin(arr_one, env_cpy);
    part_two_builtin(arr_one, env_cpy, true);
    close(file);
    dup2(fd, STDOUT_FILENO);
    return 0;
}

int my_double_redirect(char *order_one, char *order_two, env_t *env_cpy,
                int zero_empty)
{
    char **arr_one = NULL;
    char **arr_two = NULL;
    int fd = 0;
    int file = 0;

    if (error_redirect(order_one, order_two, zero_empty) == 84)
        return 84;
    arr_one = my_split(order_one, " \t");
    arr_two = my_split(order_two, " \t");
    fd = dup(STDOUT_FILENO);
    file = open(arr_two[0], O_WRONLY | O_CREAT | O_APPEND, 0777);
    dup2(file, STDOUT_FILENO);
    part_one_builtin(arr_one, env_cpy);
    part_two_builtin(arr_one, env_cpy, true);
    close(file);
    dup2(fd, STDOUT_FILENO);
    return 0;
}
