/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** update_pwd
*/

#include "my.h"
#include "my_minishell.h"

void update_pwd(env_t *env_cpy, char *current_dir)
{
    int index_value = 0;
    char *new_pwd = NULL;

    index_value = my_getenv_index("PWD", env_cpy);
    if (index_value == -1) {
        env_cpy->env_copy = create_new_key(env_cpy, "PWD=");
        index_value = my_getenv_index("PWD", env_cpy);
        MY_FREE(env_cpy->env_copy[index_value]);
        new_pwd = str_concat("PWD=", current_dir);
        env_cpy->env_copy[index_value] = my_strdup(new_pwd);
        MY_FREE(new_pwd);
    } else {
        index_value = my_getenv_index("PWD", env_cpy);
        MY_FREE(env_cpy->env_copy[index_value]);
        new_pwd = str_concat("PWD=", current_dir);
        env_cpy->env_copy[index_value] = my_strdup(new_pwd);
        MY_FREE(new_pwd);
    }
}
