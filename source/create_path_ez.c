/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** create path according to a char * from a char **
*/

#include "my.h"
#include "my_minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

char *create_path_ez(char *current_dir, char *order)
{
    char *new_path = str_concat(str_concat(current_dir, "/"), order);

    return new_path;
}
