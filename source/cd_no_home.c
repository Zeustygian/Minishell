/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** cd_no_home
*/

#include "my.h"
#include "my_minishell.h"

int cd_no_home(env_t *env_cpy)
{
    if (my_getenv_index("HOME", env_cpy) == -1) {
        my_putstr_err("cd: No home directory.\n");
        return 1;
    }
    return 0;
}
