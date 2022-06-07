/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** main_mysh
*/

#include "minishell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *my_strdup(char *str)
{
    int len_str = my_strlen(str);
    char *dest = malloc(sizeof(char) * (len_str + 1));
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        dest[i] = str[i];
    }
    dest[i] = '\0';
    return (dest);
}

list_t *init_list_env(char **envp)
{
    char *work_directory;
    list_t *l = NULL;
    char **all;

    if (envp[0] == NULL) {
        work_directory = getcwd(NULL, 0);
        l = add_elem(l, "/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:\
/usr/sbin", "PATH", 0);
        l = add_elem(l, work_directory, "PWD", 1);
        l = add_elem(l, work_directory, "OLDPWD", 2);
        return (l);
    }
    for (int i = 0; envp[i] != NULL; ++i) {
        all = my_str_to_word_arr(envp[i], "=");
        l = add_elem(l, all[1], all[0], i);
        free (all[0]);
        free(all[1]);
    }
    return (l);
}

char **list_to_arr(list_t *l)
{
    list_t *tmp = l;
    char **env;
    int len_list = 0;
    int i = 0;

    while (tmp != NULL) {
        len_list++;
        tmp = tmp->next;
    }
    env = malloc(sizeof(char*) * (len_list + 1));
    for (i = 0; i != len_list; ++i) {
        env[i] = my_strcat(l->name, "=");
        env[i] = my_strcat(env[i], l->value);
        l = l->next;
    }
    env[i] = NULL;
    return (env);
}

void display_env(list_t *l)
{
    while (l != NULL) {
        my_putstr(l->name);
        my_putstr("=");
        if (l->value != NULL)
            my_putstr(l->value);
        my_putstr("\n");
        l = l->next;
    }
}

int main(int ac, char **av, char **envp)
{
    mini_t my_sh;

    my_sh.lenv = init_list_env(envp);
    my_sh.env = list_to_arr(my_sh.lenv);
    if (get_elem(my_sh.lenv, "PWD") == NULL)
        my_sh.lenv = add_elem(my_sh.lenv, getcwd(NULL, 0), "PWD", 0);
    make_minishel2(&my_sh);
    return (0);
}
