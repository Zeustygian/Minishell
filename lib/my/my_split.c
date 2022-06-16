/*
** EPITECH PROJECT, 2022
** stumper
** File description:
** split_a_string
*/

#include "my.h"
#include <stdlib.h>

char **my_split(char *str, char *separator)
{
    char **tab = NULL;
    int nb_chars = 0;
    int nb_to_skip = 0;
    int nb_words = count_words(str, separator);

    tab = malloc(sizeof(char *) * (nb_words + 1));
    str += my_strspn(str, separator);
    for (int i = 0; i < nb_words; i++) {
        nb_chars = my_strcspn(str, separator);
        nb_to_skip = my_strspn(str + nb_chars, separator);
        tab[i] = my_strndup(str, nb_chars);
        str += nb_chars + nb_to_skip;
    }
    tab[nb_words] = NULL;
    return tab;
}
