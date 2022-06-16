/*
** EPITECH PROJECT, 2022
** B-PSU-101-RUN-1-1-minishell1-lucas.gangnant
** File description:
** my_minishell
*/

#ifndef MY_MINISHELL_H
    #define MY_MINISHELL_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <stdint.h>
    #include <sys/sysmacros.h>
    #include <stdbool.h>

    typedef struct env_s {
        char **env_copy;
        char *old_pwd;
        char *pwd;
    } env_t;

    char *my_getenv(char *name, env_t *env_cpy);
    bool check_nmrs_gtl(char *buffer);
    int my_getenv_index(char *name, env_t *env_cpy);
    int count_nb_lines_array(char **array);
    int nb_occ_strstr(char *str, char *to_find);
    int is_it_file(char *path, struct stat statbuffer);
    int is_it_dir(char *path, struct stat statbuffer);
    int nb_len_array(char **array);
    int my_cd(char **input, env_t *env_cpy);
    bool check_key_existence(char *name_value, env_t *env_cpy);
    int my_env(env_t *env_cpy);
    char **replace_key(env_t *env_cpy, char *key, char **input);
    char **create_new_key(env_t *env_cpy, char *new_key);
    char **delete_key(env_t *env_cpy, char *key);
    char **dup_arr_repkey(env_t *env_cpy, char **arr_cpy,
                            char *key, char **input);
    int my_setenv(env_t *env_cpy, char **input);
    int my_unsetenv(env_t *env_cpy, char **input);
    int all_bins_function(char *indication, char **input,
        env_t *env_cpy, bool forkable);
    char *create_path_ez(char *current_dir, char *order);
    char *create_path_i(char *current_dir, char **input, int i);
    void my_putstr_err(char *message);
    void execute_order(char *path, char **input, char **env);
    char **my_strcpy_array(char **array_copy, char **array);
    char **my_strdup_array(char **array, char **array_copy);
    char **my_strdup_array_keyless(env_t *env_cpy, char **arr_cpy, char *key);
    char **dup_entire_array(char **model);
    int len_str_sepless(char *str, char separator);
    bool allowed_letter(char *str);
    bool check_diff_seps(char *str, char separator);
    bool check_recs_existencies(char *str, char separator);
    char *delete_sep_recurencies(char *str, char separators);
    char *turn_sep_to_spaces(char *str, char separator);
    char *rm_last_gtl(char *str);
    char *rm_trailling_spaces(char *str);
    bool last_char_str(char *str, char elem);
    char *my_str_clear(char *str, char separator);
    char **my_split_getenv(char *str, char separator);
    char **my_split_for_inputs(char *str, char separator);
    char **array_inputs_nmrs_gtl(char *buffer);
    char **get_array_inputs(char *buffer);
    int part_one_builtin(char **input, env_t *env_cpy);
    int part_two_builtin(char **input, env_t *env_cpy, bool forkable);
    void update_pwd(env_t *env_cpy, char *current_dir);
    void update_oldpwd(env_t *env_cpy, char *current_dir);
    int cd_no_home(env_t *env_cpy);
    int getenv_name_len(char *whole_key);
    char *cd_alone(char **input, env_t *env_cpy, char *path);
    int cd_only(char **input, env_t *env_cpy, char *current_dir);
    int cd_on_folder(char **input, env_t *env_cpy,
                    char *current_dir, struct stat statbuffer);
    int cd_another(char *path, env_t *env_cpy,
                char *current_dir, struct stat statbuffer);
    int cd_minus(char **input, env_t *env_cpy, char *current_dir);
    char **append_to_array(char **array, char *str);
    char **my_split_coma(char *str, char separator);
    char **my_split_pipe(char *str, char separator);
    char **get_array_inputs_coma(char *buffer);
    char **get_array_inputs_pipe(char *buffer);
    char **get_array_inputs_redirect(char *buffer);
    int db_redirect_in_str(char *str);
    void parse_on_pipe(char **array_coma, env_t *env_cpy);
    int my_pipe(char *order_one, char *order_two, env_t *env_cpy);
    int my_double_redirect(char *order_one, char *order_two, env_t *env_cpy,
                int zero_empty);
    int my_redirect(char *order_one, char *order_two, env_t *env_cpy,
                int zero_empty);
    char **append_arr_to_arr(char **arr_dest, char **arr_src);

#endif
