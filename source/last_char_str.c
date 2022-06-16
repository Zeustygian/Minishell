/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** check_last_char_str
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "my.h"
#include "my_minishell.h"

bool last_char_str(char *str, char elem)
{
    if (str[my_strlen(str)] == elem)
        return true;
    return false;
}
