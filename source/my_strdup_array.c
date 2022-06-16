/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** duplicate content of an array
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

char **my_strdup_array(char **array, char **array_copy)
{
    int i = 0;

    while (array[i] != NULL) {
        array_copy[i] = my_strdup(array[i]);
        i++;
    }
    array_copy[i] = NULL;
    return array_copy;
}
