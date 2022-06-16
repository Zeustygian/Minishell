/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** allowed_letter
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

bool condition(char *str, int i, int j, char *aphbet)
{
    while (str[i] != aphbet[j]) {
        j++;
        if (aphbet[j] == '\0')
            return false;
    }
    return true;
}

bool allowed_letter(char *str)
{
    int i = 0;
    int j = 0;
    char *aphbet = str_concat(ALPHABET, EXT_ALPHABET);

    while (str[i] != '\0') {
        if (str[i] == aphbet[j]) {
            i++;
            j = 0;
        }
        if (condition(str, i, j, aphbet) == false)
            return false;
    }
    return true;
}
