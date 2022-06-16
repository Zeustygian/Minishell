/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** copy content of an array into another malloced one
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

char **my_strcpy_array(char **array_copy, char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        array_copy[i] = my_strcpy(array_copy[i], array[i]);
        i++;
    }
    return array_copy;
}
