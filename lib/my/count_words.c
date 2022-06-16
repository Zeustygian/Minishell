/*
** EPITECH PROJECT, 2022
** stumper
** File description:
** count numbers of words
*/

#include <unistd.h>
#include <stdbool.h>
#include "my.h"

int count_words(char *str, char *separator)
{
    int i = 0;
    int count = 0;
    bool sep_requiem = true;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        if (my_strchr(separator, str[i]) != NULL) {
            i++;
            count += !sep_requiem;
            sep_requiem = true;
        } else {
            i++;
            sep_requiem = false;
        }
    }
    count += !sep_requiem;
    return count;
}
