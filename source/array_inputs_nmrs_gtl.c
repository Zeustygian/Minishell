/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** array_inputs_nmrs_gtl
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

char **array_inputs_nmrs_gtl(char *buffer)
{
    char **array_one = {0};
    char *first_step_array = my_strdup(buffer);
    int i = 0;

    array_one = my_split(first_step_array, "\n");
    while (array_one[i] != NULL) {
        first_step_array = turn_sep_to_spaces(first_step_array, '\t');
        first_step_array = str_cleaner(first_step_array, ' ');
        i++;
    }
    return array_one;
}
