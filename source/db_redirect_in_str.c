/*
** EPITECH PROJECT, 2022
** B-PSU-210-RUN-2-1-minishell2-lucas.gangnant
** File description:
** db_redirect_in_str
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

int db_redirect_in_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] != '>')
            return 0;
    }
    return 1;
}
