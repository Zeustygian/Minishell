/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** execute_order
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

void execute_order(char *path, char **input, char **env)
{
    if (fork() == 0) {
        execve(path, input, env);
    } else {
        wait(NULL);
    }
}
