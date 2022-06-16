/*
** EPITECH PROJECT, 2022
** B-PSU-210-RUN-2-1-minishell2-lucas.gangnant
** File description:
** cd_minus
*/

#include "my.h"
#include "my_minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int cd_minus(char **input, env_t *env_cpy, char *current_dir)
{
    if (my_strcmp(input[1], "-") == 0) {
        if (my_getenv_index("OLDPWD", env_cpy) == -1) {
            my_putstr_err(": No such file or directory.\n");
            return 0;
        } else {
            chdir(my_getenv("OLDPWD", env_cpy));
            current_dir = getcwd(NULL, 0);
            update_oldpwd(env_cpy, current_dir);
            update_pwd(env_cpy, current_dir);
            return 0;
        }
    }
    return 84;
}
