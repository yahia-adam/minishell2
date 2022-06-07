/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** bultin
*/

#include "minishell.h"
#include <wait.h>
#include <errno.h>
#include <string.h>

void input_comand(mini_t *m)
{
    m->etap = 0;
    m->argv = my_str_to_word_arr(m->buffer, " ");
    m->path = find_path(m, m->argv[0]);
}

void make_builtins(mini_t *m)
{
    if ((str_compare(m->argv[0], "echo") == 1)\
    && (str_compare(m->argv[1], "$?") == 1))
        m->etap = echo_dollar(m);
    if (str_compare(m->argv[0], "env") == 1)
        m->etap = print_env(m->lenv);
    if (m->argv[0][1] == '/' || m->argv[0][0] == '/')
        m->path = m->argv[0];
    if (str_compare(m->argv[0], "cd") == 1)
        m->etap = make_my_cd(m);
    if (str_compare(m->argv[0], "setenv") == 1)
        m->etap = my_setenv(m);
    if (str_compare(m->argv[0], "unsetenv") == 1)
        m->etap = my_unsetenv(m);
    if (m->etap == 1)
        m->env = list_to_arr(m->lenv);
}

void make_builtins_with_path(mini_t *m)
{
    int state = 0;
    pid_t id = 0;
    pid_t pid = 0;

    if ((id = fork()) == 0) {
        if (execve(m->path, m->argv, m->env) == -1) {
            my_putstr(m->argv[0]);
            my_putstr(": Command not found.\n");
            modif_elem(m->lenv, "1", "DISPLAY");
            exit(1);
        }
        modif_elem(m->lenv, "0", "DISPLAY");
        exit(0);
    } else {
        pid = waitpid(id, &state, 0);
        verif_seg(state, m);
    }
}
