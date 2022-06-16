/*
** EPITECH PROJECT, 2022
** B-PSU-100-RUN-1-1-myls-lucas.gangnant
** File description:
** len_str_sepless
*/

#include "my_minishell.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int len_str_sepless(char *str, char separator)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == separator)
            count--;
        if (str[i] != separator)
            count++;
        i++;
    }
    return count;
}
