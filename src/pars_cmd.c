/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** pars_cmd
*/

#include "minishell.h"

list_t *make_interpars_cmd(list_t *l, int i, char *buffer, int *len_l)
{
    int z = *len_l;

    if (buffer[i] == ';') {
        l = add_elem(l, "NULL", ";", z);
        z++;
    }
    if (buffer[i] == '|') {
        l = add_elem(l, "NULL", "|", z);
        z++;
    }
    if (buffer[i] == '<' && buffer[i + 1] != '<') {
        l = add_elem(l, "NULL", "<", z);
        z++;
    }
    if ((buffer[i] == '>' && buffer[i + 1] != '>')) {
        l = add_elem(l, "NULL", ">", z);
        z++;
    }
    *len_l = z;
    return (l);
}

list_t *pars_cmd(char *buffer)
{
    int len_l = 0;
    list_t *l = NULL;

    for (int i = 0; buffer[i + 1] != '\0'; i++) {
        l = make_interpars_cmd(l, i, buffer, &len_l);
        if (buffer[i] == '<' && buffer[i + 1] == '<') {
            l = add_elem(l, "NULL", "<<", len_l);
            len_l++;
            i++;
        }
        if (buffer[i] == '>' && buffer[i + 1] == '>') {
            l = add_elem(l, "NULL", ">>", len_l);
            len_l++;
            i++;
        }
    }
    return (l);
}