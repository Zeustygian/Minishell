/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** parser
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

void simple_pipe(char **array_coma, int i, env_t *env_cpy)
{
    char **array_pipe = NULL;

    array_pipe = get_array_inputs_pipe(array_coma[i]);
    my_pipe(array_pipe[0], array_pipe[1], env_cpy);
    free_array(array_pipe);
}

void simple_redirection(char **array_coma, int i, env_t *env_cpy)
{
    int zero_empty = 1;
    char **array_redirect = NULL;

    if (array_coma[i][0] == '>')
        zero_empty = 0;
    array_redirect = get_array_inputs_redirect(array_coma[i]);
    my_redirect(array_redirect[0], array_redirect[1], env_cpy, zero_empty);
    free_array(array_redirect);
}

void double_redirection(char **array_coma, int i, env_t *env_cpy)
{
    int zero_empty = 1;
    char **array_redirect = NULL;

    if (array_coma[i][0] == '>')
        zero_empty = 0;
    array_redirect = get_array_inputs_redirect(array_coma[i]);
    my_double_redirect(array_redirect[0], array_redirect[1], env_cpy,
        zero_empty);
    free_array(array_redirect);
}

void core_executor(char **array_coma, int i, env_t *env_cpy)
{
    char **input = 0;

    if (str_contain_char(array_coma[i], '|') == 0) {
        simple_pipe(array_coma, i, env_cpy);
        return;
    }
    if (db_redirect_in_str(array_coma[i]) == 0) {
        double_redirection(array_coma, i, env_cpy);
    } else if (str_contain_char(array_coma[i], '>') == 0) {
        simple_redirection(array_coma, i, env_cpy);
    } else {
        input = get_array_inputs(array_coma[i]);
        part_one_builtin(input, env_cpy);
        part_two_builtin(input, env_cpy, true);
    }
}

void parse_on_pipe(char **array_coma, env_t *env_cpy)
{
    for (int i = 0; array_coma[i] != NULL; i++) {
        if (my_strlen(array_coma[i]) == 0)
            break;
        core_executor(array_coma, i, env_cpy);
    }
}
