/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** update_pwd
*/

#include "my.h"
#include "my_minishell.h"

void update_oldpwd(env_t *env_cpy, char *current_dir)
{
    int index_value = 0;
    char *new_old_pwd = NULL;

    index_value = my_getenv_index("OLDPWD", env_cpy);
    if (index_value == -1) {
        env_cpy->env_copy = create_new_key(env_cpy, "OLDPWD=");
        index_value = my_getenv_index("OLDPWD", env_cpy);
        new_old_pwd = str_concat("OLDPWD=", current_dir);
        env_cpy->env_copy[index_value] = my_strdup(new_old_pwd);
    } else {
        new_old_pwd = str_concat("OLDPWD=", my_getenv("PWD", env_cpy));
        env_cpy->env_copy[index_value] = my_strdup(new_old_pwd);
    }
}
