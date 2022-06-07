/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** semicolons
*/

#include "minishell.h"

void make_semicolons(mini_t *m)
{
    m->buffer = m->all_cmd[m->i];
    for (int i = 0; m->buffer[i] != '\0'; ++i)
        if (m->buffer[i] == '$')
            m->buffer[i] = ' ';
    make_minishel(m);
    m->i++;
}
