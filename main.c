/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** main
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

int child_pid_f(void)
{
    int child_pid = fork();

    return (child_pid);
}

int part_one_builtin(char **input, env_t *env_cpy)
{
    if (my_strcmp(input[0], "cd") == 0)
        my_cd(input, env_cpy);
    if (my_strcmp(input[0], "exit") == 0)
        exit(0);
    if (my_strcmp(input[0], "env") == 0)
        my_env(env_cpy);
    return 84;
}

int part_two_builtin(char **input, env_t *env_cpy, bool forkable)
{
    if (my_strcmp(input[0], "setenv") == 0)
        if (my_setenv(env_cpy, input) == 0)
            return 0;
    if (my_strcmp(input[0], "unsetenv") == 0)
        if (my_unsetenv(env_cpy, input) == 0)
            return 0;
    if (CONDITION)
        all_bins_function(input[0], input, env_cpy, forkable);
    return 84;
}

void run_mysh(env_t *env_cpy)
{
    size_t n = 0;
    char *buffer = NULL;
    char **array_coma = NULL;

    if (getline(&buffer, &n, stdin) == -1)
        exit(0);
    if (my_strcmp(buffer, "\n") != 0) {
        array_coma = get_array_inputs_coma(buffer);
        parse_on_pipe(array_coma, env_cpy);
    }
}

int main(int argc, char **argv, char **env)
{
    (void)argv;
    int tty = 1;
    env_t *env_cpy = malloc(sizeof(env_t));
    env_cpy->env_copy = dup_entire_array(env);
    env_cpy->old_pwd = NULL;
    env_cpy->pwd = NULL;

    if (argc != 1)
        return 84;
    while (tty) {
        if (isatty(0))
            my_putstr("[Redshell]$> ");
        run_mysh(env_cpy);
    }
    return 0;
}
