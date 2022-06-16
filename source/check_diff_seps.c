/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** check_various_seps
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

bool check_diff_seps(char *str, char separator)
{
    int i = 0;

    while (str[i] != '\0') {
        if (allowed_letter(str) == true || str[i] == separator)
            return false;
        if (allowed_letter(str) == false && str[i] != separator)
            return true;
        i++;
    }
    return false;
}
