/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** turn_sep_to_space
*/

#include "my_minishell.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

char *turn_sep_to_spaces(char *str, char separator)
{
    int i = 0;
    char *str_cleared = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != separator)
            str_cleared[i] = str[i];
        else
            str_cleared[i] = ' ';
    }
    str_cleared[i] = '\0';
    return str_cleared;
}
