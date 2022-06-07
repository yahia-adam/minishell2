/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** minishell
*/

#include "list_chaine.h"

#ifndef MINISHELL_H_
    #define MINISHELL_H_

typedef enum {
    false,
    true
} bool;

typedef struct mini_s {
    char *buffer;
    char *path;
    char **argv;
    char **env;
    int len_env;
    int etap;
    int count_env;
    struct pointers *p;
    list_t *lenv;
    list_t *l;
    int i;
    char **all_cmd;
} mini_t;

typedef struct pointers {
    void (*pointer)(mini_t *m);
    char *str;
} pointer;

void my_strerror(char *str);
char *clear_str(char *str);
void input_comand(mini_t *m);
void make_builtins(mini_t *m);
void make_builtins_with_path(mini_t *m);
list_t *pars_cmd(char *buffer);
void is_ambigous(void);
bool ambiguous_output_redirect(mini_t *m);
char *reinite_word_arr(char *buffer);
char *clear_str(char *str);
char *read_file(char *filepath);
char **list_to_arr(list_t *l);
int my_strcmp(char const *s1, char const *s2);
pointer *create_function(void);
void redirect_cmd_in_string(mini_t *m);
void redirect_standard_input(mini_t *m);
void make_semicolons(mini_t *m);
void append_standard_out_to_an_existing_file(mini_t *m);
void redirect_standard_out_to_a_new_file(mini_t *m);
void make_pipline(mini_t *m);
int getfile_type(char *av);
char *my_strncpy(char *str, int n);
int get_index_var(char **env, char *var);
int my_setenv(mini_t *m);
int echo_dollar(mini_t *m);
int print_env(list_t *l);
int my_unsetenv(mini_t *m);
int var_access_or_not(char **env, char *str);
char *find_path(mini_t *m, char *str);
char **free_list(char **arr);
char *get_var_env(char **env, char *str);
char *my_strcat(char *dest, char *src);
int make_minishel(mini_t *m);
void create_env(char **envp, mini_t *my_sh);
void pwd(char **env);
char *my_getline(mini_t *m);
char **my_str_to_word_arr(char *str, char *str2);
int str_compare(char *str1, char *str2);
void my_putchar(char c);
void my_putstr(char const *str);
void my_putnbr(int n);
int my_strlen(char const *str);
int make_my_cd(mini_t *m);
char **change_display(char **env, char *value);
void verif_seg(int state, mini_t *m);
int make_minishel2(mini_t *m);
#endif/*!MINISHELL_H_*/
