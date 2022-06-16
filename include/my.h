/*
** EPITECH PROJECT, 2022
** my
** File description:
** my
*/

#ifndef MY_H
    #define MY_H
    #define AUT_SPLIT "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    #define EXT_AUT_SPLIT "/,-."
    #define MORE "0123456789&é'(-è_çà)=É!,<>?./§ù%%@^$£¨+°}\"]@^\\`|[{#~*µ"
    #define MORE_C "0123456789&é'(-è_çà)=É!,<>?./§ù%%@^$£¨+°}\"]@^\\`|[{#~*µ "
    #define MORE_P "0123456789&é'(-è_çà)=É!,<>?./§ù%%@^$£¨+°}\"]@^\\`[{#~*µ;"
    #define ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    #define DIGITS "0123456789"
    #define EXT_ALPHABET "./="
    #define CONDITION ((my_strcmp(input[0], "cd") != 0) &&\
                        (my_strcmp(input[0], "exit") != 0) &&\
                        (my_strcmp(input[0], "env") != 0) &&\
                        (my_strcmp(input[0], "setenv") != 0) &&\
                        (my_strcmp(input[0], "unsetenv") != 0))
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <stdint.h>
    #include <sys/sysmacros.h>
    #define MY_FREE(x)  if (x) {\
                            free(x);\
                            (x) = NULL;\
                        }

    void my_putchar(char c);
    int my_put_digit(int i);
    int my_charcmp(char c1, char c2);
    int display_alphabet(void);
    void my_swap(int *a,int *b);
    char *my_strchr(char *str, char to_find);
    int my_strlen(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int is_alpha(char c);
    int count_words(char *str, char *separator);
    int is_alphanum(char c);
    char *my_strdup(char *src);
    char *my_strndup(char *str, int n);
    int is_prime_number(int nb);
    char *my_strcpy(char *src, char *dest);
    int my_strncmp(char const *s1, char const *s2, int n);
    int iterative_factorial(int nb);
    int my_strstr(char *str, char *to_find);
    int recursive_power(int nb, int p);
    char *reverse_string(char *str);
    char *str_concat(char *dest, char const *src);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    char *my_strcapitalize(char *str);
    int show_combinations(int nb);
    int my_isneg (int n);
    int my_put_nbr(int nb);
    int my_putstr(char const *str);
    int my_str_isnum(char const *str);
    int my_str_iscapalpha(char *str);
    int my_str_islowalpha(char *str);
    int my_str_isanyalpha(char *str);
    int my_str_is_alphanum(char *str);
    int str_contain_char(char *str, char c);
    char *my_strncpy(char *dest,char const *src,int n);
    int my_strspn(char *str, char *accepted_chars);
    int my_strcspn(char *str, char *acptd_chars);
    int palindrome_guesser(char *str);
    char **my_split(char *str, char *separator);
    char *str_cleaner(char *str, char separator);
    int my_array_len(char **array);
    void free_array(char **array);
    void draw_array(char **array);

#endif
