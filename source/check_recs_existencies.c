/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** check_recs_existencies
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
#include <stdbool.h>

bool check_recs_existencies(char *str, char separator)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator && str[i + 1] == separator)
            return true;
    }
    return false;
}
