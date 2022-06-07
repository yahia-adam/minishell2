/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** ambiguous_output_redirect
*/

#include "minishell.h"
#include <wait.h>

void is_ambigous(void)
{
    int fd = 0;

    if ((fd = fork()) == 0) {
        my_putstr("Ambiguous output redirect.\n");
        exit (1);
    } else
        waitpid(fd, NULL, 0);
}

bool ambiguous_output_redirect(mini_t *m)
{
    list_t *tmp = m->l;
    bool is_abigu = false;

    if (tmp == NULL)
        return (false);
    while (tmp->next != NULL) {
        is_abigu = false;
        if (my_strcmp(tmp->name, ">") == 1 || my_strcmp(tmp->name, ">>"))
            is_abigu = true;
        if (my_strcmp(tmp->next->name, "|") == 1 && is_abigu == true)
            return (is_abigu);
        if ((my_strcmp(tmp->next->name, ">") == 1 ||
        my_strcmp(tmp->next->name, ">") == 1) && is_abigu == true)
            return (is_abigu);
        tmp = tmp->next;
    }
    return (false);
}
