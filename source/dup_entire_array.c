/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** dup_entire_array
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

char **dup_entire_array(char **model)
{
    char **copy = malloc(sizeof(char *) * (nb_len_array(model) + 1));
    int i = 0;

    while (model[i] != NULL) {
        copy[i] = my_strdup(model[i]);
        i++;
    }
    copy[i] = NULL;
    return copy;
}
