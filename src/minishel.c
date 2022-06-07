/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** minishel
*/

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include "list_chaine.h"

void handler(int signum)
{
    if (signum == SIGINT) {
        my_putchar('\n');
        my_putstr(getcwd(NULL, 0));
        my_putstr("$>");
    }
}

int make_minishel(mini_t *m)
{
    input_comand(m);
    if (str_compare(m->buffer, "exit") == 1) {
        my_putstr("exit\n");
        exit(0);
    }
    make_builtins(m);
    if (m->etap == 0)
        make_builtins_with_path(m);
}

void make_inter_minishel(mini_t *m, int i)
{
    if (m->l != NULL)
        if (my_strcmp(m->p[i].str, m->l->name) == 1)
            m->p[i].pointer(m);
}

void make_intermake_minishell(mini_t *m)
{
    m->buffer = reinite_word_arr(m->buffer);
    m->all_cmd = my_str_to_word_arr(m->buffer,";|<>");
    for (m->i = 0; m->all_cmd[m->i] != NULL;) {
        for (int i = 0; m->p[i].pointer != NULL; ++i)
            make_inter_minishel(m, i);
        if (m->l != NULL)
            m->l = m->l->next;
        if (m->all_cmd[m->i] != NULL && m->l == NULL) {
            m->buffer = clear_str(m->all_cmd[m->i]);
            make_minishel(m);
            m->i++;
        }
    }
}

int make_minishel2(mini_t *m)
{

    m->p = create_function();
    signal(SIGINT, handler);
    m->buffer = "";
    while (1) {
        m->buffer = my_getline(m);
        m->l = pars_cmd(m->buffer);
        if (ambiguous_output_redirect(m))
            is_ambigous();
        else if (m->l == NULL)
            make_minishel(m);
        else
            make_intermake_minishell(m);
    }
}
