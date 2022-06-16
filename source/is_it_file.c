/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** did this path lead to a file ?
*/

#include "my.h"
#include "my_minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdint.h>
#include <sys/sysmacros.h>

int is_it_file(char *path, struct stat statbuffer)
{
    if (stat(path, &statbuffer) == -1)
        return 84;
    if ((statbuffer.st_mode & S_IFMT) == S_IFREG)
        return 0;
    return 1;
}
