/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** rm_last_space
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

char *rm_trailling_spaces(char *str)
{
    char *new_str = NULL;
    int i = my_strlen(str) - 1;
    int count_space = 0;
    int new_str_len = 0;
    int k = 0;

    if (str == NULL)
        return NULL;
    for (; str[i] == ' '; i--)
        count_space++;
    new_str_len = my_strlen(str) - count_space;
    new_str = malloc(sizeof(char) * ((my_strlen(str) - count_space + 1)));
    for (; k != new_str_len; k++) {
        new_str[k] = str[k];
    }
    new_str[k] = '\0';
    return new_str;
}
