/*
** EPITECH PROJECT, 2022
** B-PSU-100-RUN-1-1-myls-lucas.gangnant
** File description:
** my_str_clear
*/

#include "my_minishell.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

char *my_str_clear(char *str, char separator)
{
    char *str_cleared = malloc(sizeof(char) * len_str_sepless(str, separator));
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != separator) {
            str_cleared[j] = str[i];
            j++;
        }
    }
    return str_cleared;
}
