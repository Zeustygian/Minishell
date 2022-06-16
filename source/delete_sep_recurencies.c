/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** delete_sep_recurencies
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

int count_total_sep_recurencies(char *str, char separator)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == separator && str[i + 1] == separator)
            count++;
        i++;
    }
    return count;
}

int count_consecutives_seps(char *str, char separator, int i)
{
    int count = 0;

    while (str[i] == separator && str[i + 1] == separator) {
        count++;
        i++;
    }
    return count;
}

char *delete_sep_recurencies(char *str, char separator)
{
    int j = 0;
    int count = count_total_sep_recurencies(str, separator);
    char *one_rec_str = malloc(sizeof(char) * (my_strlen(str) - count));

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator && str[i + 1] == separator) {
            one_rec_str[j] = str[i];
            i += count_consecutives_seps(str, separator, i);
            continue;
        }
        if (str[i] == separator && str[i + 1] != separator)
            one_rec_str[j] = str[i];
        if (str[i] != separator)
            one_rec_str[j] = str[i];
        j++;
    }
    return one_rec_str;
}
