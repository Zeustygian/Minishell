/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** cd function
*/

#include "my.h"
#include "my_minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

char *cd_alone(char **input, env_t *env_cpy, char *path)
{
    (void)input;
    char *home = NULL;

    home = my_getenv("HOME", env_cpy);
    path = my_strdup(home);
    return path;
}

int cd_not_existing(char **input)
{
    if (access(input[1], F_OK) != 0) {
        my_putstr_err(input[1]);
        my_putstr_err(": No such file or directory.\n");
        return 84;
    }
    return 1;
}

int cd_on_file(char **input, char *path, struct stat statbuffer)
{
    if ((access(input[1], F_OK) == 0) && (is_it_file(path, statbuffer) == 0)) {
        my_putstr_err(input[1]);
        my_putstr_err(": Not a directory.\n");
        return 84;
    }
    return 1;
}

int all_cd_stuff(char **input, env_t *env_cpy,
            char *current_dir, struct stat statbuffer)
{
    char *path = NULL;
    struct stat file_info;
    stat(input[1], &file_info);

    if (cd_only(input, env_cpy, current_dir) == 0)
        return 0;
    path = create_path_i(current_dir, input, 1);
    if (cd_minus(input, env_cpy, current_dir) == 0)
        return 0;
    if (cd_on_file(input, path, statbuffer) == 84 ||
        cd_not_existing(input) == 84)
        return 84;
    if (cd_on_folder(input, env_cpy, current_dir, statbuffer) == 0)
        return 0;
    if (cd_another(path, env_cpy, current_dir, statbuffer) == 0)
        return 0;
    return 1;
}

int my_cd(char **input, env_t *env_cpy)
{
    char *current_dir = getcwd(NULL, 0);
    struct stat statbuffer = {};
    size_t size = 0;
    char *buff_old_pwd = NULL;

    getcwd(buff_old_pwd, size);
    if (my_array_len(input) > 2) {
        my_putstr_err("cd: Too many arguments\n");
        return 84;
    }
    if (all_cd_stuff(input, env_cpy, current_dir, statbuffer) == 0)
        return 0;
    return 84;
}
