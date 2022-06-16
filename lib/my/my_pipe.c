/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** my_pipe
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

int another_pid(int *fd, char **arr_two, env_t *env_cpy, int fd_running)
{
    int pid = 0;

    if ((pid = fork()) == 0) {
        if (pid < 0)
            return 84;
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        part_one_builtin(arr_two, env_cpy);
        part_two_builtin(arr_two, env_cpy, false);
    } else {
        waitpid(fd_running, NULL, 0);
    }
    close(fd[0]);
    return 0;
}

int fork_stuff(char **arr_one, char **arr_two, env_t *env_cpy, int *fd)
{
    int fd_running = fork();

    if (fd_running < 0)
        return 84;
    if (fd_running == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        part_one_builtin(arr_one, env_cpy);
        part_two_builtin(arr_one, env_cpy, false);
        close(fd[1]);
        exit(0);
    } else {
        if (another_pid(fd, arr_two, env_cpy, fd_running) == 84)
            return 84;
    }
    return 0;
}

int my_pipe(char *order_one, char *order_two, env_t *env_cpy)
{
    int fd[2];
    char **arr_one = NULL;
    char **arr_two = NULL;

    if (order_one == NULL || order_two == NULL) {
        my_putstr_err("Invalid null command.\n");
        return 84;
    }
    arr_one = my_split(order_one, " \t");
    arr_two = my_split(order_two, " \t");
    if (pipe(fd) == -1)
        return 84;
    if (fork_stuff(arr_one, arr_two, env_cpy, fd) == 84)
        return 84;
    return 0;
}
