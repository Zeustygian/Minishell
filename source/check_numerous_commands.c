/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** check_numerous_commands
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

bool check_nmrs_gtl(char *buffer)
{
    int i = 0;
    int count = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            count++;
        i++;
        if (count > 1)
            return true;
    }
    return false;
}
