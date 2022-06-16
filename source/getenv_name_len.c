/*
** EPITECH PROJECT, 2022
** tres_vieux_shell
** File description:
** getenv_name
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

int getenv_name_len(char *whole_key)
{
    int i = 0;

    for (; whole_key[i] != '\0'; i++) {
        if (whole_key[i] == '=')
            return i;
    }
    return i;
}
