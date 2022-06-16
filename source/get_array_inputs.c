/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** token_in_array
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

char **get_array_inputs(char *buffer)
{
    char **array = NULL;
    char *clean_str = my_strdup(buffer);

    array = my_split(clean_str, " \t");
    MY_FREE(clean_str);
    return array;
}

char **get_array_inputs_coma(char *buffer)
{
    char **array = NULL;
    char *clean_str = my_strdup(buffer);

    clean_str = rm_last_gtl(clean_str);
    array = my_split(clean_str, ";");
    MY_FREE(clean_str);
    return array;
}

char **get_array_inputs_pipe(char *buffer)
{
    char **array = NULL;
    char *clean_str = my_strdup(buffer);

    clean_str = turn_sep_to_spaces(clean_str, '\t');
    clean_str = str_cleaner(clean_str, ' ');
    clean_str = rm_last_gtl(clean_str);
    clean_str = rm_trailling_spaces(clean_str);
    array = my_split(clean_str, "|");
    MY_FREE(clean_str);
    return array;
}

char **get_array_inputs_redirect(char *buffer)
{
    char **array = NULL;
    char *clean_str = my_strdup(buffer);

    clean_str = turn_sep_to_spaces(clean_str, '\t');
    clean_str = str_cleaner(clean_str, ' ');
    clean_str = rm_last_gtl(clean_str);
    clean_str = rm_trailling_spaces(clean_str);
    array = my_split(clean_str, ">");
    MY_FREE(clean_str);
    return array;
}
