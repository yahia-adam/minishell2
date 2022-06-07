/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** my_setenv
*/

#include <stdlib.h>
#include "minishell.h"

bool make_intersetenv(mini_t *m)
{
    if (m->argv[1] == NULL) {
        print_env(m->lenv);
        return true;
    }
    if (m->argv[1][0] >= '0' && m->argv[1][0] <= '9') {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return true;
    }
    return (false);
}

bool ver_argv(mini_t *m, list_t *tmp)
{
    if (m->argv[2] != NULL) {
        tmp->value = m->argv[2];
        return true;
    }
    return false;
}

void make_inter_setenv(mini_t *m, int i)
{
    if (m->argv[2] != NULL)
        m->lenv = add_elem
(m->lenv, clear_str(m->argv[2]), clear_str(m->argv[1]), i);
    else
        m->lenv = add_elem(m->lenv, "NULL", clear_str(m->argv[1]), i);
}

int my_setenv(mini_t *m)
{
    list_t *tmp = m->lenv;
    bool verif = false;
    int i = 0;

    if (make_intersetenv(m) == true)
        return (1);
    while (tmp != NULL) {
        verif = false;
        if (my_strcmp(tmp->name, m->argv[1]) == 1)
            verif = ver_argv(m, tmp);
        if (verif == true)
            return (1);
        tmp = tmp->next;
        i++;
    }
    make_inter_setenv(m, i);
    return (1);
}