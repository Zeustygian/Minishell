/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** all_cd_stuff
*/

#include "my.h"
#include "my_minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int cd_only(char **input, env_t *env_cpy, char *current_dir)
{
    char *path = NULL;

    if (my_array_len(input) == 1) {
        if (cd_no_home(env_cpy) != 0)
            return 84;
        path = cd_alone(input, env_cpy, path);
        update_oldpwd(env_cpy, current_dir);
        update_pwd(env_cpy, path);
        chdir(path);
        MY_FREE(path);
        current_dir = getcwd(NULL, 0);
        return 0;
    }
    return 1;
}

int cd_on_folder(char **input, env_t *env_cpy,
                char *current_dir, struct stat statbuffer)
{
    char *new_command = NULL;

    if (access(input[1], R_OK) != 0) {
        my_putstr_err(input[1]);
        my_putstr_err(": Permission denied.\n");
        return (84);
    }
    if ((chdir(input[1]) == 0) && (is_it_dir(input[1], statbuffer) == 0)) {
        new_command = input[1];
        chdir(new_command);
        current_dir = getcwd(NULL, 0);
        update_oldpwd(env_cpy, current_dir);
        update_pwd(env_cpy, current_dir);
        return 0;
    }
    return 1;
}

int cd_another(char *path, env_t *env_cpy,
            char *current_dir, struct stat statbuffer)
{
    char *new_command = NULL;

    if ((chdir(path) == 0) && (is_it_dir(path, statbuffer) == 0)) {
        new_command = path;
        chdir(new_command);
        current_dir = getcwd(NULL, 0);
        update_oldpwd(env_cpy, current_dir);
        update_pwd(env_cpy, current_dir);
        return 0;
    }
    return 1;
}
