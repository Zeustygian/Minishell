/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** rm_last_gtl
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

char *rm_last_gtl(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (; i != my_strlen(str) - 1; i++)
        new_str[i] = str[i];
    if (str[i] != '\n') {
        new_str[i] = str[i];
        new_str[i + 1] = '\0';
    } else {
        new_str[i] = '\0';
    }
    return new_str;
}
