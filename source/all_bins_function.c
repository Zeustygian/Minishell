/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** all_bins_function
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"
#include "my_minishell.h"

int error_message(char **input)
{
    my_putstr_err(input[0]);
    my_putstr_err(": Command not found.\n");
    return 0;
}

void execute_order_66(char *path, char **input, env_t *env_cpy, bool forkable)
{
    pid_t pid = 0;
    int status = 0;

    if (forkable) {
        pid = fork();
        if (pid == 0) {
            execve(path, input, env_cpy->env_copy);
            exit(84);
        }
        waitpid(pid, &status, WUNTRACED);
    } else {
        execve(path, input, env_cpy->env_copy);
        exit(84);
    }
}

int some_errs(char *indication, char **input,
                env_t *env_cpy, struct stat file_info)
{
    if (S_ISDIR(file_info.st_mode)) {
        my_putstr_err(indication);
        my_putstr_err(": Permission denied.\n");
        return (84);
    }
    if (access(indication, X_OK) != -1) {
        execute_order_66(indication, input, env_cpy, true);
        return (1);
    }
    if (access(indication, X_OK) == -1)
        error_message(input);
    return (84);
}

int all_bins_function(char *indication, char **input,
                    env_t *env_cpy, bool forkable)
{
    char **path_tab = my_split(my_getenv("PATH", env_cpy), ":");
    char *final_path = NULL;
    int i = 0;
    int nb_path = nb_occ_strstr(my_getenv("PATH", env_cpy), ":");
    struct stat file_info;

    stat(indication, &file_info);
    for (; access(create_path_ez(path_tab[i], indication), X_OK) == -1 &&
            i < nb_path; i++);
    if (access(create_path_ez(path_tab[i], indication), X_OK) != -1) {
        final_path = create_path_ez(path_tab[i], indication);
        execute_order_66(final_path, input, env_cpy, forkable);
        free_array(path_tab);
        return (1);
    }
    free_array(path_tab);
    for (; access(indication, X_OK) == -1 && i < nb_path; i++);
    if (some_errs(indication, input, env_cpy, file_info) == 1)
        return (1);
    return (84);
}
